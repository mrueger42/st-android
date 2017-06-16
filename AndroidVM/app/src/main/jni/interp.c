/* Automatically generated from Squeak on 17 January 2010 5:57:19 pm 
   by VMMaker 3.11.8
 */

#include "sq.h"
#include <setjmp.h>

#include "sqMemoryAccess.h"

sqInt printCallStack(void);
void error(char *s);
void error(char *s) {
	/* Print an error message and exit. */
	static sqInt printingStack = false;

	printf("\n%s\n\n", s);
	if (!printingStack) {
		/* flag prevents recursive error when trying to print a broken stack */
		printingStack = true;
		printCallStack();
	}
	exit(-1);
}

/*** Constants ***/
#define ActiveProcessIndex 1
#define AllButHashBits 3758227455U
#define AllButMarkBit 2147483647U
#define AllButMarkBitAndTypeMask 2147483644
#define AllButRootBit 3221225471U
#define AllButTypeMask 4294967292U
#define AtCacheFixedFields 4
#define AtCacheFmt 3
#define AtCacheMask 28
#define AtCacheOop 1
#define AtCacheSize 2
#define AtCacheTotalSize 64
#define AtPutBase 32
#define BaseHeaderSize 4
#define BlockArgumentCountIndex 3
#define Byte0Mask 255
#define Byte1Mask 65280
#define Byte1Shift 8
#define Byte1ShiftNegated -8
#define Byte2Mask 16711680
#define Byte3Mask 4278190080U
#define Byte3Shift 24
#define Byte3ShiftNegated -24
#define Byte4Mask 0
#define Byte4Shift 0
#define Byte4ShiftNegated 0
#define Byte5Mask 0
#define Byte5Shift 0
#define Byte5ShiftNegated 0
#define Byte6Mask 0
#define Byte7Mask 0
#define Byte7Shift 0
#define Byte7ShiftNegated 0
#define Bytes3to0Mask 0
#define Bytes7to4Mask 0
#define BytesPerWord 4
#define CacheProbeMax 3
#define CallbackSemaphoreIndex 55
#define CallerIndex 0
#define CharacterTable 24
#define CharacterValueIndex 0
#define ClassArray 7
#define ClassBitmap 4
#define ClassBlockClosure 36
#define ClassBlockContext 11
#define ClassByteArray 26
#define ClassCharacter 19
#define ClassExternalAddress 43
#define ClassExternalData 45
#define ClassExternalFunction 46
#define ClassExternalLibrary 47
#define ClassExternalStructure 44
#define ClassFloat 9
#define ClassInteger 5
#define ClassLargeNegativeInteger 42
#define ClassLargePositiveInteger 13
#define ClassMessage 15
#define ClassMethodContext 10
#define ClassPoint 12
#define ClassSemaphore 18
#define ClassString 6
#define ClosureFirstCopiedValueIndex 3
#define ClosureIndex 4
#define ClosureNumArgsIndex 2
#define ClosureOuterContextIndex 0
#define ClosureStartPCIndex 1
#define CompactClassMask 126976
#define CompactClasses 28
#define ConstMinusOne -1
#define ConstOne 3
#define ConstTwo 5
#define ConstZero 1
#define CrossedX 258
#define CtxtTempFrameStart 6
#define DoAssertionChecks 0
#define DoBalanceChecks 0
#define Done 4
#define EndOfRun 257
#define ExcessSignalsIndex 2
#define ExternalObjectsArray 38
#define ExtraRootSize 2048
#define FalseObject 1
#define FirstLinkIndex 0
#define GCTopMarker 3
#define HashBits 536739840
#define HashBitsOffset 17
#define HeaderIndex 0
#define HeaderTypeClass 1
#define HeaderTypeFree 2
#define HeaderTypeGC 2
#define HeaderTypeShort 3
#define HeaderTypeSizeAndClass 0
#define HomeIndex 5
#define InitialIPIndex 4
#define InstanceSpecificationIndex 2
#define InstructionPointerIndex 1
#define LargeContextBit 262144
#define LargeContextSize 252
#define LastLinkIndex 1
#define LiteralStart 1
#define LongSizeMask 4294967292U
#define MarkBit 2147483648U
#define MaxExternalPrimitiveTableSize 4096
#define MaxJumpBuf 32
#define MaxPrimitiveIndex 575
#define MessageArgumentsIndex 1
#define MessageDictionaryIndex 1
#define MessageLookupClassIndex 2
#define MessageSelectorIndex 0
#define MethodArrayIndex 1
#define MethodCacheClass 2
#define MethodCacheEntries 512
#define MethodCacheEntrySize 8
#define MethodCacheMask 4088
#define MethodCacheMethod 3
#define MethodCacheNative 5
#define MethodCachePrim 4
#define MethodCachePrimFunction 6
#define MethodCacheSelector 1
#define MethodCacheSize 4096
#define MethodIndex 3
#define MillisecondClockMask 536870911
#define MyListIndex 3
#define NextLinkIndex 0
#define NilContext 1
#define NilObject 0
#define PrimitiveExternalCallIndex 117
#define PriorityIndex 2
#define ProcessListsIndex 0
#define ProcessSignalingLowSpace 22
#define ReceiverIndex 5
#define RootBit 1073741824
#define RootTableRedZone 2400
#define RootTableSize 2500
#define SchedulerAssociation 3
#define SelectorAboutToReturn 48
#define SelectorCannotInterpret 34
#define SelectorCannotReturn 21
#define SelectorDoesNotUnderstand 20
#define SelectorMustBeBoolean 25
#define SelectorRunWithIn 49
#define SelectorStart 2
#define SemaphoresToSignalSize 500
#define SenderIndex 0
#define ShiftForWord 2
#define Size4Bit 0
#define SizeMask 252
#define SmallContextSize 92
#define SpecialSelectors 23
#define StackPointerIndex 2
#define StartField 1
#define StartObj 2
#define StreamArrayIndex 0
#define StreamIndexIndex 1
#define StreamReadLimitIndex 2
#define SuperclassIndex 0
#define SuspendedContextIndex 1
#define TempFrameStart 6
#define TheDisplay 14
#define TheFinalizationSemaphore 41
#define TheInterruptSemaphore 30
#define TheLowSpaceSemaphore 17
#define TheTimerSemaphore 29
#define TrueObject 2
#define TypeMask 3
#define Upward 3
#define ValueIndex 1
#define WordMask 4294967295U
#define XIndex 0
#define YIndex 1

/*** Function Prototypes ***/
sqInt accessibleObjectAfter(sqInt oop);
sqInt activateNewClosureMethod(sqInt blockClosure);
sqInt activateNewMethod(void);
#pragma export on
EXPORT(sqInt) addGCRoot(sqInt *varLoc);
#pragma export off
sqInt addNewMethodToCache(void);
sqInt addToExternalPrimitiveTable(void *functionAddress);
sqInt adjustAllOopsBy(sqInt bytesToShift);
sqInt allYoungand(sqInt array1, sqInt array2);
sqInt allocateChunk(sqInt byteSize);
sqInt allocateOrRecycleContext(sqInt needsLarge);
sqInt argumentCountOf(sqInt methodPointer);
void * arrayValueOf(sqInt arrayOop);
sqInt asciiOfCharacter(sqInt characterObj);
sqInt balancedStackafterPrimitivewithArgs(sqInt delta, sqInt primIdx, sqInt nArgs);
sqInt beRootIfOld(sqInt oop);
sqInt becomewith(sqInt array1, sqInt array2);
sqInt becomewithtwoWaycopyHash(sqInt array1, sqInt array2, sqInt twoWayFlag, sqInt copyHashFlag);
sqInt biasToGrow(void);
sqInt booleanValueOf(sqInt obj);
sqInt byteSizeOf(sqInt oop);
sqInt byteSwapByteObjectsFromto(sqInt startOop, sqInt stopAddr);
sqInt byteSwapped(sqInt w);
sqInt callExternalPrimitive(void * functionID);
#pragma export on
EXPORT(sqInt) callInterpreter(void);
#pragma export off
sqInt callbackEnd(void);
#pragma export on
EXPORT(sqInt) callbackEnter(sqInt *callbackID);
EXPORT(sqInt) callbackLeave(sqInt cbID);
#pragma export off
sqInt callbackSemaphore(void);
sqInt callbackStart(void);
sqInt changeClassOfto(sqInt rcvr, sqInt argClass);
sqInt characterForAscii(sqInt ascii);
sqInt characterTable(void);
sqInt checkForInterrupts(void);
sqInt checkImageVersionFromstartingAt(sqImageFile  f, squeakFileOffsetType  imageOffset);
sqInt checkedIntegerValueOf(sqInt intOop);
sqInt checkedLongAt(sqInt byteAddress);
sqInt classArray(void);
sqInt classBitmap(void);
sqInt classByteArray(void);
sqInt classCharacter(void);
sqInt classExternalAddress(void);
sqInt classExternalData(void);
sqInt classExternalFunction(void);
sqInt classExternalLibrary(void);
sqInt classExternalStructure(void);
sqInt classFloat(void);
sqInt classLargeNegativeInteger(void);
sqInt classLargePositiveInteger(void);
sqInt classNameOfIs(sqInt aClass, char * className);
sqInt classPoint(void);
sqInt classSemaphore(void);
sqInt classSmallInteger(void);
sqInt classString(void);
sqInt clone(sqInt oop);
sqInt commonAt(sqInt stringy);
sqInt commonAtPut(sqInt stringy);
sqInt commonVariableatcacheIndex(sqInt rcvr, sqInt index, sqInt atIx);
sqInt compare31or32Bitsequal(sqInt obj1, sqInt obj2);
sqInt compilerCreateActualMessagestoringArgs(sqInt aMessage, sqInt argArray);
sqInt compilerFlushCache(sqInt aCompiledMethod);
sqInt compilerMapFromto(sqInt memStart, sqInt memEnd);
sqInt compilerMark(void);
sqInt compilerPostGC(void);
sqInt compilerPostSnapshot(void);
sqInt compilerPreGC(sqInt fullGCFlag);
sqInt compilerPreSnapshot(void);
sqInt compilerProcessChange(void);
sqInt compilerProcessChangeto(sqInt oldProc, sqInt newProc);
sqInt compilerTranslateMethod(void);
sqInt containOnlyOopsand(sqInt array1, sqInt array2);
sqInt contexthasSender(sqInt thisCntx, sqInt aContext);
sqInt copyBits(void);
sqInt copyBitsFromtoat(sqInt x0, sqInt x1, sqInt y);
sqInt copyObjtoSegmentaddrstopAtsaveOopAtheaderAt(sqInt oop, sqInt segmentWordArray, sqInt lastSeg, sqInt stopAddr, sqInt oopPtr, sqInt hdrPtr);
sqInt createActualMessageTo(sqInt aClass);
sqInt dispatchFunctionPointer(void * aFunctionPointer);
sqInt dispatchFunctionPointerOnin(sqInt primIdx, void *primTable[]);
sqInt displayBitsOfLeftTopRightBottom(sqInt aForm, sqInt l, sqInt t, sqInt r, sqInt b);
sqInt displayObject(void);
sqInt doPrimitiveDivby(sqInt rcvr, sqInt arg);
sqInt doPrimitiveModby(sqInt rcvr, sqInt arg);
sqInt dummyReferToProxy(void);
#pragma export on
EXPORT(sqInt) dumpImage(sqInt fileName);
#pragma export off
sqInt executeNewMethodFromCache(void);
sqInt failed(void);
sqInt falseObject(void);
void * fetchArrayofObject(sqInt fieldIndex, sqInt objectPointer);
sqInt fetchClassOf(sqInt oop);
sqInt fetchClassOfNonInt(sqInt oop);
double fetchFloatofObject(sqInt fieldIndex, sqInt objectPointer);
sqInt fetchIntegerofObject(sqInt fieldIndex, sqInt objectPointer);
sqInt fetchLong32ofObject(sqInt fieldIndex, sqInt oop);
sqInt fetchPointerofObject(sqInt fieldIndex, sqInt oop);
sqInt fetchStackPointerOf(sqInt aContext);
sqInt fetchWordLengthOf(sqInt objectPointer);
sqInt finalizeReference(usqInt oop);
sqInt findClassOfMethodforReceiver(sqInt meth, sqInt rcvr);
sqInt findNewMethodInClass(sqInt class);
sqInt findObsoleteNamedPrimitivelength(char * functionName, sqInt functionLength);
sqInt findSelectorOfMethodforReceiver(sqInt meth, sqInt rcvr);
sqInt firstAccessibleObject(void);
char * firstFixedField(sqInt oop);
char * firstIndexableField(sqInt oop);
sqInt floatObjectOf(double  aFloat);
double floatValueOf(sqInt oop);
sqInt flushExternalPrimitiveOf(sqInt methodPtr);
sqInt flushExternalPrimitives(void);
sqInt forceInterruptCheck(void);
sqInt fullDisplayUpdate(void);
sqInt fullGC(void);
sqInt fwdTableInit(sqInt blkSize);
sqInt fwdTableSize(sqInt blkSize);
sqInt getCurrentBytecode(void);
sqInt getFullScreenFlag(void);
sqInt getInterruptCheckCounter(void);
sqInt getInterruptKeycode(void);
sqInt getInterruptPending(void);
sqInt getLongFromFileswap(sqImageFile  aFile, sqInt swapFlag);
sqInt getNextWakeupTick(void);
sqInt getSavedWindowSize(void);
sqInt getThisSessionID(void);
sqInt growObjectMemory(usqInt delta);
sqInt imageFormatForwardCompatibilityVersion(void);
sqInt imageSegmentVersion(void);
sqInt incCompBody(void);
sqInt incCompMakeFwd(void);
sqInt incCompMove(sqInt bytesFreed);
sqInt includesBehaviorThatOf(sqInt aClass, sqInt aSuperclass);
sqInt incrementalGC(void);
sqInt initCompilerHooks(void);
sqInt initializeInterpreter(sqInt bytesToShift);
sqInt initializeMemoryFirstFree(usqInt firstFree);
sqInt initializeObjectMemory(sqInt bytesToShift);
sqInt installinAtCacheatstring(sqInt rcvr, sqInt * cache, sqInt atIx, sqInt stringy);
sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
sqInt instantiateContextsizeInBytes(sqInt classPointer, sqInt sizeInBytes);
sqInt instantiateSmallClasssizeInBytes(sqInt classPointer, sqInt sizeInBytes);
sqInt integerObjectOf(sqInt value);
sqInt integerValueOf(sqInt objectPointer);
sqInt interpret(void);
sqInt ioFilenamefromStringofLengthresolveAliases(char * aCharBuffer, char * aFilenameString, sqInt filenameLength, sqInt aBoolean);
sqInt isKindOf(sqInt oop, char * className);
sqInt isMemberOf(sqInt oop, char * className);
sqInt isArray(sqInt oop);
sqInt isBigEnder(void);
sqInt isBytes(sqInt oop);
sqInt isExcessiveAllocationRequestshift(sqInt size, sqInt bits);
sqInt isFloatObject(sqInt oop);
sqInt isHandlerMarked(sqInt aContext);
sqInt isInMemory(sqInt address);
sqInt isIndexable(sqInt oop);
sqInt isIntegerObject(sqInt objectPointer);
sqInt isIntegerValue(sqInt intValue);
sqInt isPointers(sqInt oop);
sqInt isWeak(sqInt oop);
sqInt isWords(sqInt oop);
sqInt isWordsOrBytes(sqInt oop);
sqInt isWordsOrBytesNonInt(sqInt oop);
sqInt lastPointerOf(sqInt oop);
sqInt lengthOf(sqInt oop);
sqInt literalofMethod(sqInt offset, sqInt methodPointer);
sqInt literalCountOf(sqInt methodPointer);
sqInt loadBitBltFrom(sqInt bb);
sqInt loadInitialContext(void);
sqInt lookupMethodInClass(sqInt class);
sqInt lowestFreeAfter(sqInt chunk);
sqInt makePointwithxValueyValue(sqInt xValue, sqInt yValue);
sqInt mapPointersInObjectsFromto(sqInt memStart, sqInt memEnd);
sqInt markAndTrace(sqInt oop);
sqInt markAndTraceInterpreterOops(void);
sqInt markPhase(void);
sqInt methodArgumentCount(void);
sqInt methodPrimitiveIndex(void);
#pragma export on
EXPORT(sqInt) moduleUnloaded(char * aModuleName);
#pragma export off
sqInt nilObject(void);
sqInt nonWeakFieldsOf(sqInt oop);
sqInt noteAsRootheaderLoc(sqInt oop, sqInt headerLoc);
sqInt nullCompilerHook(void);
sqInt objectAfter(sqInt oop);
sqInt obsoleteDontUseThisFetchWordofObject(sqInt fieldIndex, sqInt oop);
sqInt okayFields(sqInt oop);
sqInt okayOop(sqInt signedOop);
sqInt oopHasAcceptableClass(sqInt signedOop);
sqInt oopHasOkayClass(sqInt signedOop);
sqInt pop(sqInt nItems);
sqInt popthenPush(sqInt nItems, sqInt oop);
double popFloat(void);
sqInt popRemappableOop(void);
sqInt popStack(void);
sqInt positive32BitIntegerFor(sqInt integerValue);
sqInt positive32BitValueOf(sqInt oop);
sqInt positive64BitIntegerFor(sqLong integerValue);
sqLong positive64BitValueOf(sqInt oop);
sqInt possibleRootStoreIntovalue(sqInt oop, sqInt valueObj);
sqInt postGCAction(void);
#pragma export on
EXPORT(sqInt) prepareActiveProcess(void);
#pragma export off
sqInt prepareForwardingTableForBecomingwithtwoWay(sqInt array1, sqInt array2, sqInt twoWayFlag);
sqInt primitiveAdd(void);
sqInt primitiveArctan(void);
sqInt primitiveArrayBecome(void);
sqInt primitiveArrayBecomeOneWay(void);
sqInt primitiveArrayBecomeOneWayCopyHash(void);
sqInt primitiveAsFloat(void);
sqInt primitiveAsOop(void);
sqInt primitiveAt(void);
sqInt primitiveAtEnd(void);
sqInt primitiveAtPut(void);
sqInt primitiveBeCursor(void);
sqInt primitiveBeDisplay(void);
sqInt primitiveBeep(void);
sqInt primitiveBitAnd(void);
sqInt primitiveBitOr(void);
sqInt primitiveBitShift(void);
sqInt primitiveBitXor(void);
sqInt primitiveBlockCopy(void);
sqInt primitiveBytesLeft(void);
sqInt primitiveCalloutToFFI(void);
sqInt primitiveChangeClass(void);
#pragma export on
EXPORT(sqInt) primitiveChangeClassWithClass(void);
#pragma export off
sqInt primitiveClass(void);
sqInt primitiveClipboardText(void);
sqInt primitiveClone(void);
sqInt primitiveClosureCopyWithCopiedValues(void);
sqInt primitiveClosureValue(void);
sqInt primitiveClosureValueNoContextSwitch(void);
sqInt primitiveClosureValueWithArgs(void);
sqInt primitiveConstantFill(void);
sqInt primitiveCopyObject(void);
sqInt primitiveDeferDisplayUpdates(void);
#pragma export on
EXPORT(sqInt) primitiveDisablePowerManager(void);
#pragma export off
sqInt primitiveDiv(void);
sqInt primitiveDivide(void);
#pragma export on
EXPORT(sqInt) primitiveDoDialog(void);
#pragma export off
sqInt primitiveDoNamedPrimitiveWithArgs(void);
sqInt primitiveDoPrimitiveWithArgs(void);
sqInt primitiveEqual(void);
sqInt primitiveEquivalent(void);
sqInt primitiveExecuteMethod(void);
sqInt primitiveExecuteMethodArgsArray(void);
sqInt primitiveExitToDebugger(void);
sqInt primitiveExp(void);
sqInt primitiveExponent(void);
sqInt primitiveExternalCall(void);
sqInt primitiveFail(void);
sqInt primitiveFindHandlerContext(void);
sqInt primitiveFindNextUnwindContext(void);
sqInt primitiveFloatAdd(void);
sqInt primitiveFloatAddtoArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFloatDivide(void);
sqInt primitiveFloatDividebyArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFloatEqual(void);
sqInt primitiveFloatEqualtoArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFloatGreaterthanArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFloatGreaterOrEqual(void);
sqInt primitiveFloatGreaterOrEqualtoArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFloatGreaterThan(void);
sqInt primitiveFloatLessthanArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFloatLessOrEqual(void);
sqInt primitiveFloatLessOrEqualtoArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFloatLessThan(void);
sqInt primitiveFloatMultiply(void);
sqInt primitiveFloatMultiplybyArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFloatNotEqual(void);
sqInt primitiveFloatSubtract(void);
sqInt primitiveFloatSubtractfromArg(sqInt rcvrOop, sqInt argOop);
sqInt primitiveFlushCache(void);
sqInt primitiveFlushCacheByMethod(void);
sqInt primitiveFlushCacheSelective(void);
sqInt primitiveFlushExternalPrimitives(void);
sqInt primitiveForceDisplayUpdate(void);
#pragma export on
EXPORT(sqInt) primitiveForceTenure(void);
#pragma export off
sqInt primitiveFormPrint(void);
sqInt primitiveFractionalPart(void);
sqInt primitiveFullGC(void);
sqInt primitiveGetAttribute(void);
sqInt primitiveGetNextEvent(void);
sqInt primitiveGreaterOrEqual(void);
sqInt primitiveGreaterThan(void);
sqInt primitiveImageName(void);
sqInt primitiveIncrementalGC(void);
sqInt primitiveIndexOf(sqInt methodPointer);
sqInt primitiveIndexOfMethodHeader(sqInt methodHeader);
sqInt primitiveInputSemaphore(void);
sqInt primitiveInputWord(void);
sqInt primitiveInstVarAt(void);
sqInt primitiveInstVarAtPut(void);
sqInt primitiveInstVarsPutFromStack(void);
sqInt primitiveIntegerAt(void);
sqInt primitiveIntegerAtPut(void);
sqInt primitiveInterruptSemaphore(void);
sqInt primitiveInvokeObjectAsMethod(void);
#pragma export on
EXPORT(sqInt) primitiveIsEventVM(void);
EXPORT(sqInt) primitiveIsRoot(void);
EXPORT(sqInt) primitiveIsYoung(void);
#pragma export off
sqInt primitiveKbdNext(void);
sqInt primitiveKbdPeek(void);
sqInt primitiveLessOrEqual(void);
sqInt primitiveLessThan(void);
sqInt primitiveListBuiltinModule(void);
sqInt primitiveListExternalModule(void);
sqInt primitiveLoadImageSegment(void);
sqInt primitiveLoadInstVar(void);
sqInt primitiveLogN(void);
sqInt primitiveLowSpaceSemaphore(void);
sqInt primitiveMakePoint(void);
sqInt primitiveMarkHandlerMethod(void);
sqInt primitiveMarkUnwindMethod(void);
sqInt primitiveMethod(void);
sqInt primitiveMillisecondClock(void);
sqInt primitiveMod(void);
sqInt primitiveMouseButtons(void);
sqInt primitiveMousePoint(void);
sqInt primitiveMultiply(void);
sqInt primitiveNew(void);
sqInt primitiveNewMethod(void);
sqInt primitiveNewWithArg(void);
sqInt primitiveNext(void);
sqInt primitiveNextInstance(void);
sqInt primitiveNextObject(void);
sqInt primitiveNextPut(void);
sqInt primitiveNoop(void);
sqInt primitiveNotEqual(void);
sqInt primitiveObjectAt(void);
sqInt primitiveObjectAtPut(void);
sqInt primitiveObjectPointsTo(void);
sqInt primitiveObsoleteIndexedPrimitive(void);
sqInt primitivePerform(void);
sqInt primitivePerformAt(sqInt lookupClass);
sqInt primitivePerformInSuperclass(void);
sqInt primitivePerformWithArgs(void);
sqInt primitivePushFalse(void);
sqInt primitivePushMinusOne(void);
sqInt primitivePushNil(void);
sqInt primitivePushOne(void);
sqInt primitivePushSelf(void);
sqInt primitivePushTrue(void);
sqInt primitivePushTwo(void);
sqInt primitivePushZero(void);
sqInt primitiveQuit(void);
sqInt primitiveQuo(void);
sqInt primitiveRelinquishProcessor(void);
sqInt primitiveResponse(void);
sqInt primitiveResume(void);
#pragma export on
EXPORT(sqInt) primitiveRootTable(void);
EXPORT(sqInt) primitiveRootTableAt(void);
#pragma export off
sqInt primitiveScanCharacters(void);
#pragma export on
EXPORT(sqInt) primitiveScreenDepth(void);
#pragma export off
sqInt primitiveScreenSize(void);
sqInt primitiveSecondsClock(void);
sqInt primitiveSetDisplayMode(void);
sqInt primitiveSetFullScreen(void);
#pragma export on
EXPORT(sqInt) primitiveSetGCBiasToGrow(void);
EXPORT(sqInt) primitiveSetGCBiasToGrowGCLimit(void);
EXPORT(sqInt) primitiveSetGCSemaphore(void);
#pragma export off
sqInt primitiveSetInterruptKey(void);
sqInt primitiveShortAt(void);
sqInt primitiveShortAtPut(void);
sqInt primitiveShowDisplayRect(void);
sqInt primitiveSignal(void);
sqInt primitiveSignalAtBytesLeft(void);
sqInt primitiveSignalAtMilliseconds(void);
sqInt primitiveSine(void);
sqInt primitiveSize(void);
sqInt primitiveSnapshot(void);
sqInt primitiveSnapshotEmbedded(void);
sqInt primitiveSomeInstance(void);
sqInt primitiveSomeObject(void);
sqInt primitiveSpecialObjectsOop(void);
sqInt primitiveSquareRoot(void);
sqInt primitiveStoreImageSegment(void);
sqInt primitiveStoreStackp(void);
sqInt primitiveStringAt(void);
sqInt primitiveStringAtPut(void);
sqInt primitiveStringReplace(void);
sqInt primitiveSubtract(void);
sqInt primitiveSuspend(void);
sqInt primitiveTerminateTo(void);
sqInt primitiveTestDisplayDepth(void);
sqInt primitiveTimesTwoPower(void);
sqInt primitiveTruncated(void);
sqInt primitiveUnloadModule(void);
sqInt primitiveVMParameter(void);
sqInt primitiveVMPath(void);
sqInt primitiveValue(void);
sqInt primitiveValueUninterruptably(void);
sqInt primitiveValueWithArgs(void);
sqInt primitiveWait(void);
sqInt primitiveYield(void);
sqInt print(char * s);
sqInt printAllStacks(void);
sqInt printCallStack(void);
sqInt printCallStackOf(sqInt aContext);
sqInt printNameOfClasscount(sqInt classOop, sqInt cnt);
sqInt printNum(sqInt n);
sqInt printStringOf(sqInt oop);
sqInt printUnbalancedStack(sqInt primIdx);
sqInt push(sqInt object);
sqInt pushBool(sqInt trueOrFalse);
sqInt pushFloat(double  f);
sqInt pushInteger(sqInt integerValue);
sqInt pushRemappableOop(sqInt oop);
sqInt putLongtoFile(sqInt aWord, sqImageFile  aFile);
sqInt readImageFromFileHeapSizeStartingAt(sqImageFile  f, sqInt desiredHeapSize, squeakFileOffsetType  imageOffset);
sqInt readableFormat(sqInt imageVersion);
sqInt remap(sqInt oop);
sqInt removeFirstLinkOfList(sqInt aList);
#pragma export on
EXPORT(sqInt) removeGCRoot(sqInt *varLoc);
#pragma export off
sqInt restoreHeadersFromtofromandtofrom(sqInt firstIn, sqInt lastIn, sqInt hdrBaseIn, sqInt firstOut, sqInt lastOut, sqInt hdrBaseOut);
sqInt resume(sqInt aProcess);
sqInt reverseDisplayFromto(sqInt startIndex, sqInt endIndex);
sqInt rewriteMethodCacheSelclassprimIndex(sqInt selector, sqInt class, sqInt localPrimIndex);
sqInt rewriteMethodCacheSelclassprimIndexprimFunction(sqInt selector, sqInt class, sqInt localPrimIndex, void * localPrimAddress);
sqInt setCompilerInitialized(sqInt newFlag);
sqInt setFullScreenFlag(sqInt value);
sqInt setInterruptCheckCounter(sqInt value);
sqInt setInterruptKeycode(sqInt value);
sqInt setInterruptPending(sqInt value);
sqInt setNextWakeupTick(sqInt value);
sqInt setSavedWindowSize(sqInt value);
sqInt showDisplayBitsLeftTopRightBottom(sqInt aForm, sqInt l, sqInt t, sqInt r, sqInt b);
sqInt signalSemaphoreWithIndex(sqInt index);
sqInt signed32BitIntegerFor(int integerValue);
int signed32BitValueOf(sqInt oop);
sqInt signed64BitIntegerFor(sqLong integerValue);
sqLong signed64BitValueOf(sqInt oop);
sqInt sizeBitsOf(sqInt oop);
sqInt sizeOfSTArrayFromCPrimitive(void * cPtr);
sqInt slotSizeOf(sqInt oop);
sqInt snapshot(sqInt embedded);
sqInt splObj(sqInt index);
sqInt stObjectat(sqInt array, sqInt index);
sqInt stObjectatput(sqInt array, sqInt index, sqInt value);
sqInt stSizeOf(sqInt oop);
double stackFloatValue(sqInt offset);
sqInt stackIntegerValue(sqInt offset);
sqInt stackObjectValue(sqInt offset);
sqInt stackValue(sqInt offset);
sqInt storeIntegerofObjectwithValue(sqInt fieldIndex, sqInt objectPointer, sqInt integerValue);
sqInt storePointerofObjectwithValue(sqInt fieldIndex, sqInt oop, sqInt valuePointer);
sqInt success(sqInt successValue);
sqInt sufficientSpaceAfterGC(usqInt minFree);
sqInt sufficientSpaceToAllocate(usqInt bytes);
sqInt superclassOf(sqInt classPointer);
sqInt sweepPhase(void);
sqInt synchronousSignal(sqInt aSemaphore);
sqInt transferTo(sqInt aProc);
sqInt trueObject(void);
sqInt updatePointersInRangeFromto(sqInt memStart, sqInt memEnd);
sqInt updatePointersInRootObjectsFromto(sqInt memStart, sqInt memEnd);
sqInt validateRoots(void);
sqInt verifyCleanHeaders(void);
sqInt vmEndianness(void);
sqInt wakeHighestPriority(void);
sqInt wordSwapped(sqInt w);
sqInt writeImageFile(sqInt imageBytes);
sqInt writeImageFileIO(sqInt imageBytes);
/*** Variables ***/
usqInt activeContext;
sqInt allocationCount;
sqInt allocationsBetweenGCs;
sqInt argumentCount;
sqInt atCache[65];
usqInt compEnd;
usqInt compStart;
sqInt (*compilerHooks[16])();
sqInt compilerInitialized;
sqInt deferDisplayUpdates;
usqInt endOfMemory;
void *externalPrimitiveTable[4097];
sqInt extraRootCount;
sqInt* extraRoots[2049];
sqInt extraVMMemory;
sqInt falseObj;
sqInt forceTenureFlag;
usqInt freeBlock;
sqInt freeContexts;
sqInt freeLargeContexts;
sqInt fullScreenFlag;
usqInt fwdTableLast;
usqInt fwdTableNext;
sqInt gcBiasToGrow;
sqInt gcBiasToGrowGCLimit;
usqInt gcBiasToGrowThreshold;
sqInt gcSemaphoreIndex;
sqInt globalSessionID;
usqInt growHeadroom;
sqInt headerTypeBytes[4];
sqInt imageFormatVersionNumber = 6502;
usqInt instructionPointer;
struct VirtualMachine* interpreterProxy;
const char *interpreterVersion = "Squeak3.10.2 of '5 June 2008' [latest update: #7179]";
sqInt interruptCheckCounter;
sqInt interruptCheckCounterFeedBackReset;
sqInt interruptChecksEveryNms;
sqInt interruptKeycode;
sqInt interruptPending;
jmp_buf jmpBuf[33];
jmp_buf jmpBufExit;
sqInt jmpDepth;
sqInt jmpMax;
sqInt lastHash;
sqInt lastTick;
sqInt lkupClass;
sqInt lowSpaceThreshold;
usqInt memory;
usqInt memoryLimit;
sqInt messageSelector;
usqInt method;
long methodCache[4097];
sqInt methodClass;
usqInt newMethod;
sqInt newNativeMethod;
sqInt nextPollTick;
sqInt nextWakeupTick;
sqInt nilObj;
char* obsoleteIndexedPrimitiveTable[][3] = {
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "BitBltPlugin", "primitiveCopyBits", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "BitBltPlugin", "primitiveDrawLoop", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "JoystickTabletPlugin", "primitiveReadJoystick", NULL },
{ "BitBltPlugin", "primitiveWarpBits", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "FilePlugin", "primitiveFileAtEnd", NULL },
{ "FilePlugin", "primitiveFileClose", NULL },
{ "FilePlugin", "primitiveFileGetPosition", NULL },
{ "FilePlugin", "primitiveFileOpen", NULL },
{ "FilePlugin", "primitiveFileRead", NULL },
{ "FilePlugin", "primitiveFileSetPosition", NULL },
{ "FilePlugin", "primitiveFileDelete", NULL },
{ "FilePlugin", "primitiveFileSize", NULL },
{ "FilePlugin", "primitiveFileWrite", NULL },
{ "FilePlugin", "primitiveFileRename", NULL },
{ "FilePlugin", "primitiveDirectoryCreate", NULL },
{ "FilePlugin", "primitiveDirectoryDelimitor", NULL },
{ "FilePlugin", "primitiveDirectoryLookup", NULL },
{ "FilePlugin", "primitiveDirectoryDelete", NULL },
{ "FilePlugin", "primitiveDirectoryGetMacTypeAndCreator", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "FilePlugin", "primitiveDirectorySetMacTypeAndCreator", NULL },
{ "SoundPlugin", "primitiveSoundStart", NULL },
{ "SoundPlugin", "primitiveSoundStartWithSemaphore", NULL },
{ "SoundPlugin", "primitiveSoundStop", NULL },
{ "SoundPlugin", "primitiveSoundAvailableSpace", NULL },
{ "SoundPlugin", "primitiveSoundPlaySamples", NULL },
{ "SoundPlugin", "primitiveSoundPlaySilence", NULL },
{ "SoundGenerationPlugin", "primitiveWaveTableSoundMix", NULL },
{ "SoundGenerationPlugin", "primitiveFMSoundMix", NULL },
{ "SoundGenerationPlugin", "primitivePluckedSoundMix", NULL },
{ "SoundGenerationPlugin", "primitiveSampledSoundMix", NULL },
{ "SoundGenerationPlugin", "primitiveMixFMSound", NULL },
{ "SoundGenerationPlugin", "primitiveMixPluckedSound", NULL },
{ "SoundGenerationPlugin", "primitiveOldSampledSoundMix", NULL },
{ "SoundGenerationPlugin", "primitiveApplyReverb", NULL },
{ "SoundGenerationPlugin", "primitiveMixLoopedSampledSound", NULL },
{ "SoundGenerationPlugin", "primitiveMixSampledSound", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "SoundPlugin", "primitiveSoundInsertSamples", NULL },
{ "SoundPlugin", "primitiveSoundStartRecording", NULL },
{ "SoundPlugin", "primitiveSoundStopRecording", NULL },
{ "SoundPlugin", "primitiveSoundGetRecordingSampleRate", NULL },
{ "SoundPlugin", "primitiveSoundRecordSamples", NULL },
{ "SoundPlugin", "primitiveSoundSetRecordLevel", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "SocketPlugin", "primitiveInitializeNetwork", NULL },
{ "SocketPlugin", "primitiveResolverStartNameLookup", NULL },
{ "SocketPlugin", "primitiveResolverNameLookupResult", NULL },
{ "SocketPlugin", "primitiveResolverStartAddressLookup", NULL },
{ "SocketPlugin", "primitiveResolverAddressLookupResult", NULL },
{ "SocketPlugin", "primitiveResolverAbortLookup", NULL },
{ "SocketPlugin", "primitiveResolverLocalAddress", NULL },
{ "SocketPlugin", "primitiveResolverStatus", NULL },
{ "SocketPlugin", "primitiveResolverError", NULL },
{ "SocketPlugin", "primitiveSocketCreate", NULL },
{ "SocketPlugin", "primitiveSocketDestroy", NULL },
{ "SocketPlugin", "primitiveSocketConnectionStatus", NULL },
{ "SocketPlugin", "primitiveSocketError", NULL },
{ "SocketPlugin", "primitiveSocketLocalAddress", NULL },
{ "SocketPlugin", "primitiveSocketLocalPort", NULL },
{ "SocketPlugin", "primitiveSocketRemoteAddress", NULL },
{ "SocketPlugin", "primitiveSocketRemotePort", NULL },
{ "SocketPlugin", "primitiveSocketConnectToPort", NULL },
{ "SocketPlugin", "primitiveSocketListenWithOrWithoutBacklog", NULL },
{ "SocketPlugin", "primitiveSocketCloseConnection", NULL },
{ "SocketPlugin", "primitiveSocketAbortConnection", NULL },
{ "SocketPlugin", "primitiveSocketReceiveDataBufCount", NULL },
{ "SocketPlugin", "primitiveSocketReceiveDataAvailable", NULL },
{ "SocketPlugin", "primitiveSocketSendDataBufCount", NULL },
{ "SocketPlugin", "primitiveSocketSendDone", NULL },
{ "SocketPlugin", "primitiveSocketAccept", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "MiscPrimitivePlugin", "primitiveDecompressFromByteArray", NULL },
{ "MiscPrimitivePlugin", "primitiveCompareString", NULL },
{ "MiscPrimitivePlugin", "primitiveConvert8BitSigned", NULL },
{ "MiscPrimitivePlugin", "primitiveCompressToByteArray", NULL },
{ "SerialPlugin", "primitiveSerialPortOpen", NULL },
{ "SerialPlugin", "primitiveSerialPortClose", NULL },
{ "SerialPlugin", "primitiveSerialPortWrite", NULL },
{ "SerialPlugin", "primitiveSerialPortRead", NULL },
{ NULL, NULL, NULL },
{ "MiscPrimitivePlugin", "primitiveTranslateStringWithTable", NULL },
{ "MiscPrimitivePlugin", "primitiveFindFirstInString", NULL },
{ "MiscPrimitivePlugin", "primitiveIndexOfAsciiInString", NULL },
{ "MiscPrimitivePlugin", "primitiveFindSubstring", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "MIDIPlugin", "primitiveMIDIClosePort", NULL },
{ "MIDIPlugin", "primitiveMIDIGetClock", NULL },
{ "MIDIPlugin", "primitiveMIDIGetPortCount", NULL },
{ "MIDIPlugin", "primitiveMIDIGetPortDirectionality", NULL },
{ "MIDIPlugin", "primitiveMIDIGetPortName", NULL },
{ "MIDIPlugin", "primitiveMIDIOpenPort", NULL },
{ "MIDIPlugin", "primitiveMIDIParameterGetOrSet", NULL },
{ "MIDIPlugin", "primitiveMIDIRead", NULL },
{ "MIDIPlugin", "primitiveMIDIWrite", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "AsynchFilePlugin", "primitiveAsyncFileClose", NULL },
{ "AsynchFilePlugin", "primitiveAsyncFileOpen", NULL },
{ "AsynchFilePlugin", "primitiveAsyncFileReadResult", NULL },
{ "AsynchFilePlugin", "primitiveAsyncFileReadStart", NULL },
{ "AsynchFilePlugin", "primitiveAsyncFileWriteResult", NULL },
{ "AsynchFilePlugin", "primitiveAsyncFileWriteStart", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ "JoystickTabletPlugin", "primitiveGetTabletParameters", NULL },
{ "JoystickTabletPlugin", "primitiveReadTablet", NULL },
{ "ADPCMCodecPlugin", "primitiveDecodeMono", NULL },
{ "ADPCMCodecPlugin", "primitiveDecodeStereo", NULL },
{ "ADPCMCodecPlugin", "primitiveEncodeMono", NULL },
{ "ADPCMCodecPlugin", "primitiveEncodeStereo", NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL },
{ NULL, NULL, NULL }
};
const char* obsoleteNamedPrimitiveTable[][3] = {
{ "gePrimitiveMergeFillFrom", "B2DPlugin", "primitiveMergeFillFrom" },
{ "gePrimitiveSetClipRect", "B2DPlugin", "primitiveSetClipRect" },
{ "gePrimitiveDoProfileStats", "B2DPlugin", "primitiveDoProfileStats" },
{ "gePrimitiveAddCompressedShape", "B2DPlugin", "primitiveAddCompressedShape" },
{ "gePrimitiveFinishedProcessing", "B2DPlugin", "primitiveFinishedProcessing" },
{ "gePrimitiveGetBezierStats", "B2DPlugin", "primitiveGetBezierStats" },
{ "gePrimitiveSetDepth", "B2DPlugin", "primitiveSetDepth" },
{ "gePrimitiveAbortProcessing", "B2DPlugin", "primitiveAbortProcessing" },
{ "gePrimitiveGetTimes", "B2DPlugin", "primitiveGetTimes" },
{ "gePrimitiveNextActiveEdgeEntry", "B2DPlugin", "primitiveNextActiveEdgeEntry" },
{ "gePrimitiveAddBezier", "B2DPlugin", "primitiveAddBezier" },
{ "gePrimitiveRenderScanline", "B2DPlugin", "primitiveRenderScanline" },
{ "gePrimitiveAddBezierShape", "B2DPlugin", "primitiveAddBezierShape" },
{ "gePrimitiveAddLine", "B2DPlugin", "primitiveAddLine" },
{ "gePrimitiveRenderImage", "B2DPlugin", "primitiveRenderImage" },
{ "gePrimitiveGetAALevel", "B2DPlugin", "primitiveGetAALevel" },
{ "gePrimitiveRegisterExternalEdge", "B2DPlugin", "primitiveRegisterExternalEdge" },
{ "gePrimitiveInitializeBuffer", "B2DPlugin", "primitiveInitializeBuffer" },
{ "gePrimitiveAddRect", "B2DPlugin", "primitiveAddRect" },
{ "gePrimitiveInitializeProcessing", "B2DPlugin", "primitiveInitializeProcessing" },
{ "gePrimitiveAddBitmapFill", "B2DPlugin", "primitiveAddBitmapFill" },
{ "gePrimitiveGetClipRect", "B2DPlugin", "primitiveGetClipRect" },
{ "gePrimitiveGetFailureReason", "B2DPlugin", "primitiveGetFailureReason" },
{ "gePrimitiveNextGlobalEdgeEntry", "B2DPlugin", "primitiveNextGlobalEdgeEntry" },
{ "gePrimitiveNextFillEntry", "B2DPlugin", "primitiveNextFillEntry" },
{ "gePrimitiveSetColorTransform", "B2DPlugin", "primitiveSetColorTransform" },
{ "gePrimitiveDisplaySpanBuffer", "B2DPlugin", "primitiveDisplaySpanBuffer" },
{ "gePrimitiveGetOffset", "B2DPlugin", "primitiveGetOffset" },
{ "gePrimitiveAddPolygon", "B2DPlugin", "primitiveAddPolygon" },
{ "gePrimitiveNeedsFlush", "B2DPlugin", "primitiveNeedsFlush" },
{ "gePrimitiveAddOval", "B2DPlugin", "primitiveAddOval" },
{ "gePrimitiveSetAALevel", "B2DPlugin", "primitiveSetAALevel" },
{ "gePrimitiveCopyBuffer", "B2DPlugin", "primitiveCopyBuffer" },
{ "gePrimitiveAddActiveEdgeEntry", "B2DPlugin", "primitiveAddActiveEdgeEntry" },
{ "gePrimitiveGetCounts", "B2DPlugin", "primitiveGetCounts" },
{ "gePrimitiveSetOffset", "B2DPlugin", "primitiveSetOffset" },
{ "gePrimitiveAddGradientFill", "B2DPlugin", "primitiveAddGradientFill" },
{ "gePrimitiveChangedActiveEdgeEntry", "B2DPlugin", "primitiveChangedActiveEdgeEntry" },
{ "gePrimitiveRegisterExternalFill", "B2DPlugin", "primitiveRegisterExternalFill" },
{ "gePrimitiveGetDepth", "B2DPlugin", "primitiveGetDepth" },
{ "gePrimitiveSetEdgeTransform", "B2DPlugin", "primitiveSetEdgeTransform" },
{ "gePrimitiveNeedsFlushPut", "B2DPlugin", "primitiveNeedsFlushPut" },
{ "primitiveFloatArrayAt", "FloatArrayPlugin", "primitiveAt" },
{ "primitiveFloatArrayMulFloatArray", "FloatArrayPlugin", "primitiveMulFloatArray" },
{ "primitiveFloatArrayAddScalar", "FloatArrayPlugin", "primitiveAddScalar" },
{ "primitiveFloatArrayDivFloatArray", "FloatArrayPlugin", "primitiveDivFloatArray" },
{ "primitiveFloatArrayDivScalar", "FloatArrayPlugin", "primitiveDivScalar" },
{ "primitiveFloatArrayHash", "FloatArrayPlugin", "primitiveHashArray" },
{ "primitiveFloatArrayAtPut", "FloatArrayPlugin", "primitiveAtPut" },
{ "primitiveFloatArrayMulScalar", "FloatArrayPlugin", "primitiveMulScalar" },
{ "primitiveFloatArrayAddFloatArray", "FloatArrayPlugin", "primitiveAddFloatArray" },
{ "primitiveFloatArraySubScalar", "FloatArrayPlugin", "primitiveSubScalar" },
{ "primitiveFloatArraySubFloatArray", "FloatArrayPlugin", "primitiveSubFloatArray" },
{ "primitiveFloatArrayEqual", "FloatArrayPlugin", "primitiveEqual" },
{ "primitiveFloatArrayDotProduct", "FloatArrayPlugin", "primitiveDotProduct" },
{ "m23PrimitiveInvertRectInto", "Matrix2x3Plugin", "primitiveInvertRectInto" },
{ "m23PrimitiveTransformPoint", "Matrix2x3Plugin", "primitiveTransformPoint" },
{ "m23PrimitiveIsPureTranslation", "Matrix2x3Plugin", "primitiveIsPureTranslation" },
{ "m23PrimitiveComposeMatrix", "Matrix2x3Plugin", "primitiveComposeMatrix" },
{ "m23PrimitiveTransformRectInto", "Matrix2x3Plugin", "primitiveTransformRectInto" },
{ "m23PrimitiveIsIdentity", "Matrix2x3Plugin", "primitiveIsIdentity" },
{ "m23PrimitiveInvertPoint", "Matrix2x3Plugin", "primitiveInvertPoint" },
{ "primitiveDeflateBlock", "ZipPlugin", "primitiveDeflateBlock" },
{ "primitiveDeflateUpdateHashTable", "ZipPlugin", "primitiveDeflateUpdateHashTable" },
{ "primitiveUpdateGZipCrc32", "ZipPlugin", "primitiveUpdateGZipCrc32" },
{ "primitiveInflateDecompressBlock", "ZipPlugin", "primitiveInflateDecompressBlock" },
{ "primitiveZipSendBlock", "ZipPlugin", "primitiveZipSendBlock" },
{ "primitiveFFTTransformData", "FFTPlugin", "primitiveFFTTransformData" },
{ "primitiveFFTScaleData", "FFTPlugin", "primitiveFFTScaleData" },
{ "primitiveFFTPermuteData", "FFTPlugin", "primitiveFFTPermuteData" },
{ NULL, NULL, NULL }
};
sqInt pendingFinalizationSignals;
void *primitiveFunctionPointer;
sqInt primitiveIndex;
void *primitiveTable[577] = {
	/* 0*/ (void *)primitiveFail,
	/* 1*/ (void *)primitiveAdd,
	/* 2*/ (void *)primitiveSubtract,
	/* 3*/ (void *)primitiveLessThan,
	/* 4*/ (void *)primitiveGreaterThan,
	/* 5*/ (void *)primitiveLessOrEqual,
	/* 6*/ (void *)primitiveGreaterOrEqual,
	/* 7*/ (void *)primitiveEqual,
	/* 8*/ (void *)primitiveNotEqual,
	/* 9*/ (void *)primitiveMultiply,
	/* 10*/ (void *)primitiveDivide,
	/* 11*/ (void *)primitiveMod,
	/* 12*/ (void *)primitiveDiv,
	/* 13*/ (void *)primitiveQuo,
	/* 14*/ (void *)primitiveBitAnd,
	/* 15*/ (void *)primitiveBitOr,
	/* 16*/ (void *)primitiveBitXor,
	/* 17*/ (void *)primitiveBitShift,
	/* 18*/ (void *)primitiveMakePoint,
	/* 19*/ (void *)primitiveFail,
	/* 20*/ (void *)primitiveFail,
	/* 21*/ (void *)primitiveFail,
	/* 22*/ (void *)primitiveFail,
	/* 23*/ (void *)primitiveFail,
	/* 24*/ (void *)primitiveFail,
	/* 25*/ (void *)primitiveFail,
	/* 26*/ (void *)primitiveFail,
	/* 27*/ (void *)primitiveFail,
	/* 28*/ (void *)primitiveFail,
	/* 29*/ (void *)primitiveFail,
	/* 30*/ (void *)primitiveFail,
	/* 31*/ (void *)primitiveFail,
	/* 32*/ (void *)primitiveFail,
	/* 33*/ (void *)primitiveFail,
	/* 34*/ (void *)primitiveFail,
	/* 35*/ (void *)primitiveFail,
	/* 36*/ (void *)primitiveFail,
	/* 37*/ (void *)primitiveFail,
	/* 38*/ (void *)primitiveFail,
	/* 39*/ (void *)primitiveFail,
	/* 40*/ (void *)primitiveAsFloat,
	/* 41*/ (void *)primitiveFloatAdd,
	/* 42*/ (void *)primitiveFloatSubtract,
	/* 43*/ (void *)primitiveFloatLessThan,
	/* 44*/ (void *)primitiveFloatGreaterThan,
	/* 45*/ (void *)primitiveFloatLessOrEqual,
	/* 46*/ (void *)primitiveFloatGreaterOrEqual,
	/* 47*/ (void *)primitiveFloatEqual,
	/* 48*/ (void *)primitiveFloatNotEqual,
	/* 49*/ (void *)primitiveFloatMultiply,
	/* 50*/ (void *)primitiveFloatDivide,
	/* 51*/ (void *)primitiveTruncated,
	/* 52*/ (void *)primitiveFractionalPart,
	/* 53*/ (void *)primitiveExponent,
	/* 54*/ (void *)primitiveTimesTwoPower,
	/* 55*/ (void *)primitiveSquareRoot,
	/* 56*/ (void *)primitiveSine,
	/* 57*/ (void *)primitiveArctan,
	/* 58*/ (void *)primitiveLogN,
	/* 59*/ (void *)primitiveExp,
	/* 60*/ (void *)primitiveAt,
	/* 61*/ (void *)primitiveAtPut,
	/* 62*/ (void *)primitiveSize,
	/* 63*/ (void *)primitiveStringAt,
	/* 64*/ (void *)primitiveStringAtPut,
	/* 65*/ (void *)primitiveNext,
	/* 66*/ (void *)primitiveNextPut,
	/* 67*/ (void *)primitiveAtEnd,
	/* 68*/ (void *)primitiveObjectAt,
	/* 69*/ (void *)primitiveObjectAtPut,
	/* 70*/ (void *)primitiveNew,
	/* 71*/ (void *)primitiveNewWithArg,
	/* 72*/ (void *)primitiveArrayBecomeOneWay,
	/* 73*/ (void *)primitiveInstVarAt,
	/* 74*/ (void *)primitiveInstVarAtPut,
	/* 75*/ (void *)primitiveAsOop,
	/* 76*/ (void *)primitiveStoreStackp,
	/* 77*/ (void *)primitiveSomeInstance,
	/* 78*/ (void *)primitiveNextInstance,
	/* 79*/ (void *)primitiveNewMethod,
	/* 80*/ (void *)primitiveBlockCopy,
	/* 81*/ (void *)primitiveValue,
	/* 82*/ (void *)primitiveValueWithArgs,
	/* 83*/ (void *)primitivePerform,
	/* 84*/ (void *)primitivePerformWithArgs,
	/* 85*/ (void *)primitiveSignal,
	/* 86*/ (void *)primitiveWait,
	/* 87*/ (void *)primitiveResume,
	/* 88*/ (void *)primitiveSuspend,
	/* 89*/ (void *)primitiveFlushCache,
	/* 90*/ (void *)primitiveMousePoint,
	/* 91*/ (void *)primitiveTestDisplayDepth,
	/* 92*/ (void *)primitiveSetDisplayMode,
	/* 93*/ (void *)primitiveInputSemaphore,
	/* 94*/ (void *)primitiveGetNextEvent,
	/* 95*/ (void *)primitiveInputWord,
	/* 96*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 97*/ (void *)primitiveSnapshot,
	/* 98*/ (void *)primitiveStoreImageSegment,
	/* 99*/ (void *)primitiveLoadImageSegment,
	/* 100*/ (void *)primitivePerformInSuperclass,
	/* 101*/ (void *)primitiveBeCursor,
	/* 102*/ (void *)primitiveBeDisplay,
	/* 103*/ (void *)primitiveScanCharacters,
	/* 104*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 105*/ (void *)primitiveStringReplace,
	/* 106*/ (void *)primitiveScreenSize,
	/* 107*/ (void *)primitiveMouseButtons,
	/* 108*/ (void *)primitiveKbdNext,
	/* 109*/ (void *)primitiveKbdPeek,
	/* 110*/ (void *)primitiveEquivalent,
	/* 111*/ (void *)primitiveClass,
	/* 112*/ (void *)primitiveBytesLeft,
	/* 113*/ (void *)primitiveQuit,
	/* 114*/ (void *)primitiveExitToDebugger,
	/* 115*/ (void *)primitiveChangeClass,
	/* 116*/ (void *)primitiveFlushCacheByMethod,
	/* 117*/ (void *)primitiveExternalCall,
	/* 118*/ (void *)primitiveDoPrimitiveWithArgs,
	/* 119*/ (void *)primitiveFlushCacheSelective,
	/* 120*/ (void *)primitiveCalloutToFFI,
	/* 121*/ (void *)primitiveImageName,
	/* 122*/ (void *)primitiveNoop,
	/* 123*/ (void *)primitiveValueUninterruptably,
	/* 124*/ (void *)primitiveLowSpaceSemaphore,
	/* 125*/ (void *)primitiveSignalAtBytesLeft,
	/* 126*/ (void *)primitiveDeferDisplayUpdates,
	/* 127*/ (void *)primitiveShowDisplayRect,
	/* 128*/ (void *)primitiveArrayBecome,
	/* 129*/ (void *)primitiveSpecialObjectsOop,
	/* 130*/ (void *)primitiveFullGC,
	/* 131*/ (void *)primitiveIncrementalGC,
	/* 132*/ (void *)primitiveObjectPointsTo,
	/* 133*/ (void *)primitiveSetInterruptKey,
	/* 134*/ (void *)primitiveInterruptSemaphore,
	/* 135*/ (void *)primitiveMillisecondClock,
	/* 136*/ (void *)primitiveSignalAtMilliseconds,
	/* 137*/ (void *)primitiveSecondsClock,
	/* 138*/ (void *)primitiveSomeObject,
	/* 139*/ (void *)primitiveNextObject,
	/* 140*/ (void *)primitiveBeep,
	/* 141*/ (void *)primitiveClipboardText,
	/* 142*/ (void *)primitiveVMPath,
	/* 143*/ (void *)primitiveShortAt,
	/* 144*/ (void *)primitiveShortAtPut,
	/* 145*/ (void *)primitiveConstantFill,
	/* 146*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 147*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 148*/ (void *)primitiveClone,
	/* 149*/ (void *)primitiveGetAttribute,
	/* 150*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 151*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 152*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 153*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 154*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 155*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 156*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 157*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 158*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 159*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 160*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 161*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 162*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 163*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 164*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 165*/ (void *)primitiveIntegerAt,
	/* 166*/ (void *)primitiveIntegerAtPut,
	/* 167*/ (void *)primitiveYield,
	/* 168*/ (void *)primitiveCopyObject,
	/* 169*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 170*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 171*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 172*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 173*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 174*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 175*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 176*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 177*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 178*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 179*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 180*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 181*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 182*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 183*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 184*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 185*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 186*/ (void *)primitiveFail,
	/* 187*/ (void *)primitiveFail,
	/* 188*/ (void *)primitiveExecuteMethodArgsArray,
	/* 189*/ (void *)primitiveExecuteMethod,
	/* 190*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 191*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 192*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 193*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 194*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 195*/ (void *)primitiveFindNextUnwindContext,
	/* 196*/ (void *)primitiveTerminateTo,
	/* 197*/ (void *)primitiveFindHandlerContext,
	/* 198*/ (void *)primitiveMarkUnwindMethod,
	/* 199*/ (void *)primitiveMarkHandlerMethod,
	/* 200*/ (void *)primitiveClosureCopyWithCopiedValues,
	/* 201*/ (void *)primitiveClosureValue,
	/* 202*/ (void *)primitiveClosureValue,
	/* 203*/ (void *)primitiveClosureValue,
	/* 204*/ (void *)primitiveClosureValue,
	/* 205*/ (void *)primitiveClosureValue,
	/* 206*/ (void *)primitiveClosureValueWithArgs,
	/* 207*/ (void *)primitiveFail,
	/* 208*/ (void *)primitiveFail,
	/* 209*/ (void *)primitiveFail,
	/* 210*/ (void *)primitiveAt,
	/* 211*/ (void *)primitiveAtPut,
	/* 212*/ (void *)primitiveSize,
	/* 213*/ (void *)primitiveFail,
	/* 214*/ (void *)primitiveFail,
	/* 215*/ (void *)primitiveFail,
	/* 216*/ (void *)primitiveFail,
	/* 217*/ (void *)primitiveFail,
	/* 218*/ (void *)primitiveDoNamedPrimitiveWithArgs,
	/* 219*/ (void *)primitiveFail,
	/* 220*/ (void *)primitiveFail,
	/* 221*/ (void *)primitiveClosureValueNoContextSwitch,
	/* 222*/ (void *)primitiveClosureValueNoContextSwitch,
	/* 223*/ (void *)primitiveFail,
	/* 224*/ (void *)primitiveFail,
	/* 225*/ (void *)primitiveFail,
	/* 226*/ (void *)primitiveFail,
	/* 227*/ (void *)primitiveFail,
	/* 228*/ (void *)primitiveFail,
	/* 229*/ (void *)primitiveFail,
	/* 230*/ (void *)primitiveRelinquishProcessor,
	/* 231*/ (void *)primitiveForceDisplayUpdate,
	/* 232*/ (void *)primitiveFormPrint,
	/* 233*/ (void *)primitiveSetFullScreen,
	/* 234*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 235*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 236*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 237*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 238*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 239*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 240*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 241*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 242*/ (void *)primitiveFail,
	/* 243*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 244*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 245*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 246*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 247*/ (void *)primitiveSnapshotEmbedded,
	/* 248*/ (void *)primitiveInvokeObjectAsMethod,
	/* 249*/ (void *)primitiveArrayBecomeOneWayCopyHash,
	/* 250*/ (void *)clearProfile,
	/* 251*/ (void *)dumpProfile,
	/* 252*/ (void *)startProfiling,
	/* 253*/ (void *)stopProfiling,
	/* 254*/ (void *)primitiveVMParameter,
	/* 255*/ (void *)primitiveInstVarsPutFromStack,
	/* 256*/ (void *)primitivePushSelf,
	/* 257*/ (void *)primitivePushTrue,
	/* 258*/ (void *)primitivePushFalse,
	/* 259*/ (void *)primitivePushNil,
	/* 260*/ (void *)primitivePushMinusOne,
	/* 261*/ (void *)primitivePushZero,
	/* 262*/ (void *)primitivePushOne,
	/* 263*/ (void *)primitivePushTwo,
	/* 264*/ (void *)primitiveLoadInstVar,
	/* 265*/ (void *)primitiveLoadInstVar,
	/* 266*/ (void *)primitiveLoadInstVar,
	/* 267*/ (void *)primitiveLoadInstVar,
	/* 268*/ (void *)primitiveLoadInstVar,
	/* 269*/ (void *)primitiveLoadInstVar,
	/* 270*/ (void *)primitiveLoadInstVar,
	/* 271*/ (void *)primitiveLoadInstVar,
	/* 272*/ (void *)primitiveLoadInstVar,
	/* 273*/ (void *)primitiveLoadInstVar,
	/* 274*/ (void *)primitiveLoadInstVar,
	/* 275*/ (void *)primitiveLoadInstVar,
	/* 276*/ (void *)primitiveLoadInstVar,
	/* 277*/ (void *)primitiveLoadInstVar,
	/* 278*/ (void *)primitiveLoadInstVar,
	/* 279*/ (void *)primitiveLoadInstVar,
	/* 280*/ (void *)primitiveLoadInstVar,
	/* 281*/ (void *)primitiveLoadInstVar,
	/* 282*/ (void *)primitiveLoadInstVar,
	/* 283*/ (void *)primitiveLoadInstVar,
	/* 284*/ (void *)primitiveLoadInstVar,
	/* 285*/ (void *)primitiveLoadInstVar,
	/* 286*/ (void *)primitiveLoadInstVar,
	/* 287*/ (void *)primitiveLoadInstVar,
	/* 288*/ (void *)primitiveLoadInstVar,
	/* 289*/ (void *)primitiveLoadInstVar,
	/* 290*/ (void *)primitiveLoadInstVar,
	/* 291*/ (void *)primitiveLoadInstVar,
	/* 292*/ (void *)primitiveLoadInstVar,
	/* 293*/ (void *)primitiveLoadInstVar,
	/* 294*/ (void *)primitiveLoadInstVar,
	/* 295*/ (void *)primitiveLoadInstVar,
	/* 296*/ (void *)primitiveLoadInstVar,
	/* 297*/ (void *)primitiveLoadInstVar,
	/* 298*/ (void *)primitiveLoadInstVar,
	/* 299*/ (void *)primitiveLoadInstVar,
	/* 300*/ (void *)primitiveLoadInstVar,
	/* 301*/ (void *)primitiveLoadInstVar,
	/* 302*/ (void *)primitiveLoadInstVar,
	/* 303*/ (void *)primitiveLoadInstVar,
	/* 304*/ (void *)primitiveLoadInstVar,
	/* 305*/ (void *)primitiveLoadInstVar,
	/* 306*/ (void *)primitiveLoadInstVar,
	/* 307*/ (void *)primitiveLoadInstVar,
	/* 308*/ (void *)primitiveLoadInstVar,
	/* 309*/ (void *)primitiveLoadInstVar,
	/* 310*/ (void *)primitiveLoadInstVar,
	/* 311*/ (void *)primitiveLoadInstVar,
	/* 312*/ (void *)primitiveLoadInstVar,
	/* 313*/ (void *)primitiveLoadInstVar,
	/* 314*/ (void *)primitiveLoadInstVar,
	/* 315*/ (void *)primitiveLoadInstVar,
	/* 316*/ (void *)primitiveLoadInstVar,
	/* 317*/ (void *)primitiveLoadInstVar,
	/* 318*/ (void *)primitiveLoadInstVar,
	/* 319*/ (void *)primitiveLoadInstVar,
	/* 320*/ (void *)primitiveLoadInstVar,
	/* 321*/ (void *)primitiveLoadInstVar,
	/* 322*/ (void *)primitiveLoadInstVar,
	/* 323*/ (void *)primitiveLoadInstVar,
	/* 324*/ (void *)primitiveLoadInstVar,
	/* 325*/ (void *)primitiveLoadInstVar,
	/* 326*/ (void *)primitiveLoadInstVar,
	/* 327*/ (void *)primitiveLoadInstVar,
	/* 328*/ (void *)primitiveLoadInstVar,
	/* 329*/ (void *)primitiveLoadInstVar,
	/* 330*/ (void *)primitiveLoadInstVar,
	/* 331*/ (void *)primitiveLoadInstVar,
	/* 332*/ (void *)primitiveLoadInstVar,
	/* 333*/ (void *)primitiveLoadInstVar,
	/* 334*/ (void *)primitiveLoadInstVar,
	/* 335*/ (void *)primitiveLoadInstVar,
	/* 336*/ (void *)primitiveLoadInstVar,
	/* 337*/ (void *)primitiveLoadInstVar,
	/* 338*/ (void *)primitiveLoadInstVar,
	/* 339*/ (void *)primitiveLoadInstVar,
	/* 340*/ (void *)primitiveLoadInstVar,
	/* 341*/ (void *)primitiveLoadInstVar,
	/* 342*/ (void *)primitiveLoadInstVar,
	/* 343*/ (void *)primitiveLoadInstVar,
	/* 344*/ (void *)primitiveLoadInstVar,
	/* 345*/ (void *)primitiveLoadInstVar,
	/* 346*/ (void *)primitiveLoadInstVar,
	/* 347*/ (void *)primitiveLoadInstVar,
	/* 348*/ (void *)primitiveLoadInstVar,
	/* 349*/ (void *)primitiveLoadInstVar,
	/* 350*/ (void *)primitiveLoadInstVar,
	/* 351*/ (void *)primitiveLoadInstVar,
	/* 352*/ (void *)primitiveLoadInstVar,
	/* 353*/ (void *)primitiveLoadInstVar,
	/* 354*/ (void *)primitiveLoadInstVar,
	/* 355*/ (void *)primitiveLoadInstVar,
	/* 356*/ (void *)primitiveLoadInstVar,
	/* 357*/ (void *)primitiveLoadInstVar,
	/* 358*/ (void *)primitiveLoadInstVar,
	/* 359*/ (void *)primitiveLoadInstVar,
	/* 360*/ (void *)primitiveLoadInstVar,
	/* 361*/ (void *)primitiveLoadInstVar,
	/* 362*/ (void *)primitiveLoadInstVar,
	/* 363*/ (void *)primitiveLoadInstVar,
	/* 364*/ (void *)primitiveLoadInstVar,
	/* 365*/ (void *)primitiveLoadInstVar,
	/* 366*/ (void *)primitiveLoadInstVar,
	/* 367*/ (void *)primitiveLoadInstVar,
	/* 368*/ (void *)primitiveLoadInstVar,
	/* 369*/ (void *)primitiveLoadInstVar,
	/* 370*/ (void *)primitiveLoadInstVar,
	/* 371*/ (void *)primitiveLoadInstVar,
	/* 372*/ (void *)primitiveLoadInstVar,
	/* 373*/ (void *)primitiveLoadInstVar,
	/* 374*/ (void *)primitiveLoadInstVar,
	/* 375*/ (void *)primitiveLoadInstVar,
	/* 376*/ (void *)primitiveLoadInstVar,
	/* 377*/ (void *)primitiveLoadInstVar,
	/* 378*/ (void *)primitiveLoadInstVar,
	/* 379*/ (void *)primitiveLoadInstVar,
	/* 380*/ (void *)primitiveLoadInstVar,
	/* 381*/ (void *)primitiveLoadInstVar,
	/* 382*/ (void *)primitiveLoadInstVar,
	/* 383*/ (void *)primitiveLoadInstVar,
	/* 384*/ (void *)primitiveLoadInstVar,
	/* 385*/ (void *)primitiveLoadInstVar,
	/* 386*/ (void *)primitiveLoadInstVar,
	/* 387*/ (void *)primitiveLoadInstVar,
	/* 388*/ (void *)primitiveLoadInstVar,
	/* 389*/ (void *)primitiveLoadInstVar,
	/* 390*/ (void *)primitiveLoadInstVar,
	/* 391*/ (void *)primitiveLoadInstVar,
	/* 392*/ (void *)primitiveLoadInstVar,
	/* 393*/ (void *)primitiveLoadInstVar,
	/* 394*/ (void *)primitiveLoadInstVar,
	/* 395*/ (void *)primitiveLoadInstVar,
	/* 396*/ (void *)primitiveLoadInstVar,
	/* 397*/ (void *)primitiveLoadInstVar,
	/* 398*/ (void *)primitiveLoadInstVar,
	/* 399*/ (void *)primitiveLoadInstVar,
	/* 400*/ (void *)primitiveLoadInstVar,
	/* 401*/ (void *)primitiveLoadInstVar,
	/* 402*/ (void *)primitiveLoadInstVar,
	/* 403*/ (void *)primitiveLoadInstVar,
	/* 404*/ (void *)primitiveLoadInstVar,
	/* 405*/ (void *)primitiveLoadInstVar,
	/* 406*/ (void *)primitiveLoadInstVar,
	/* 407*/ (void *)primitiveLoadInstVar,
	/* 408*/ (void *)primitiveLoadInstVar,
	/* 409*/ (void *)primitiveLoadInstVar,
	/* 410*/ (void *)primitiveLoadInstVar,
	/* 411*/ (void *)primitiveLoadInstVar,
	/* 412*/ (void *)primitiveLoadInstVar,
	/* 413*/ (void *)primitiveLoadInstVar,
	/* 414*/ (void *)primitiveLoadInstVar,
	/* 415*/ (void *)primitiveLoadInstVar,
	/* 416*/ (void *)primitiveLoadInstVar,
	/* 417*/ (void *)primitiveLoadInstVar,
	/* 418*/ (void *)primitiveLoadInstVar,
	/* 419*/ (void *)primitiveLoadInstVar,
	/* 420*/ (void *)primitiveLoadInstVar,
	/* 421*/ (void *)primitiveLoadInstVar,
	/* 422*/ (void *)primitiveLoadInstVar,
	/* 423*/ (void *)primitiveLoadInstVar,
	/* 424*/ (void *)primitiveLoadInstVar,
	/* 425*/ (void *)primitiveLoadInstVar,
	/* 426*/ (void *)primitiveLoadInstVar,
	/* 427*/ (void *)primitiveLoadInstVar,
	/* 428*/ (void *)primitiveLoadInstVar,
	/* 429*/ (void *)primitiveLoadInstVar,
	/* 430*/ (void *)primitiveLoadInstVar,
	/* 431*/ (void *)primitiveLoadInstVar,
	/* 432*/ (void *)primitiveLoadInstVar,
	/* 433*/ (void *)primitiveLoadInstVar,
	/* 434*/ (void *)primitiveLoadInstVar,
	/* 435*/ (void *)primitiveLoadInstVar,
	/* 436*/ (void *)primitiveLoadInstVar,
	/* 437*/ (void *)primitiveLoadInstVar,
	/* 438*/ (void *)primitiveLoadInstVar,
	/* 439*/ (void *)primitiveLoadInstVar,
	/* 440*/ (void *)primitiveLoadInstVar,
	/* 441*/ (void *)primitiveLoadInstVar,
	/* 442*/ (void *)primitiveLoadInstVar,
	/* 443*/ (void *)primitiveLoadInstVar,
	/* 444*/ (void *)primitiveLoadInstVar,
	/* 445*/ (void *)primitiveLoadInstVar,
	/* 446*/ (void *)primitiveLoadInstVar,
	/* 447*/ (void *)primitiveLoadInstVar,
	/* 448*/ (void *)primitiveLoadInstVar,
	/* 449*/ (void *)primitiveLoadInstVar,
	/* 450*/ (void *)primitiveLoadInstVar,
	/* 451*/ (void *)primitiveLoadInstVar,
	/* 452*/ (void *)primitiveLoadInstVar,
	/* 453*/ (void *)primitiveLoadInstVar,
	/* 454*/ (void *)primitiveLoadInstVar,
	/* 455*/ (void *)primitiveLoadInstVar,
	/* 456*/ (void *)primitiveLoadInstVar,
	/* 457*/ (void *)primitiveLoadInstVar,
	/* 458*/ (void *)primitiveLoadInstVar,
	/* 459*/ (void *)primitiveLoadInstVar,
	/* 460*/ (void *)primitiveLoadInstVar,
	/* 461*/ (void *)primitiveLoadInstVar,
	/* 462*/ (void *)primitiveLoadInstVar,
	/* 463*/ (void *)primitiveLoadInstVar,
	/* 464*/ (void *)primitiveLoadInstVar,
	/* 465*/ (void *)primitiveLoadInstVar,
	/* 466*/ (void *)primitiveLoadInstVar,
	/* 467*/ (void *)primitiveLoadInstVar,
	/* 468*/ (void *)primitiveLoadInstVar,
	/* 469*/ (void *)primitiveLoadInstVar,
	/* 470*/ (void *)primitiveLoadInstVar,
	/* 471*/ (void *)primitiveLoadInstVar,
	/* 472*/ (void *)primitiveLoadInstVar,
	/* 473*/ (void *)primitiveLoadInstVar,
	/* 474*/ (void *)primitiveLoadInstVar,
	/* 475*/ (void *)primitiveLoadInstVar,
	/* 476*/ (void *)primitiveLoadInstVar,
	/* 477*/ (void *)primitiveLoadInstVar,
	/* 478*/ (void *)primitiveLoadInstVar,
	/* 479*/ (void *)primitiveLoadInstVar,
	/* 480*/ (void *)primitiveLoadInstVar,
	/* 481*/ (void *)primitiveLoadInstVar,
	/* 482*/ (void *)primitiveLoadInstVar,
	/* 483*/ (void *)primitiveLoadInstVar,
	/* 484*/ (void *)primitiveLoadInstVar,
	/* 485*/ (void *)primitiveLoadInstVar,
	/* 486*/ (void *)primitiveLoadInstVar,
	/* 487*/ (void *)primitiveLoadInstVar,
	/* 488*/ (void *)primitiveLoadInstVar,
	/* 489*/ (void *)primitiveLoadInstVar,
	/* 490*/ (void *)primitiveLoadInstVar,
	/* 491*/ (void *)primitiveLoadInstVar,
	/* 492*/ (void *)primitiveLoadInstVar,
	/* 493*/ (void *)primitiveLoadInstVar,
	/* 494*/ (void *)primitiveLoadInstVar,
	/* 495*/ (void *)primitiveLoadInstVar,
	/* 496*/ (void *)primitiveLoadInstVar,
	/* 497*/ (void *)primitiveLoadInstVar,
	/* 498*/ (void *)primitiveLoadInstVar,
	/* 499*/ (void *)primitiveLoadInstVar,
	/* 500*/ (void *)primitiveLoadInstVar,
	/* 501*/ (void *)primitiveLoadInstVar,
	/* 502*/ (void *)primitiveLoadInstVar,
	/* 503*/ (void *)primitiveLoadInstVar,
	/* 504*/ (void *)primitiveLoadInstVar,
	/* 505*/ (void *)primitiveLoadInstVar,
	/* 506*/ (void *)primitiveLoadInstVar,
	/* 507*/ (void *)primitiveLoadInstVar,
	/* 508*/ (void *)primitiveLoadInstVar,
	/* 509*/ (void *)primitiveLoadInstVar,
	/* 510*/ (void *)primitiveLoadInstVar,
	/* 511*/ (void *)primitiveLoadInstVar,
	/* 512*/ (void *)primitiveLoadInstVar,
	/* 513*/ (void *)primitiveLoadInstVar,
	/* 514*/ (void *)primitiveLoadInstVar,
	/* 515*/ (void *)primitiveLoadInstVar,
	/* 516*/ (void *)primitiveLoadInstVar,
	/* 517*/ (void *)primitiveLoadInstVar,
	/* 518*/ (void *)primitiveLoadInstVar,
	/* 519*/ (void *)primitiveLoadInstVar,
	/* 520*/ (void *)primitiveFail,
	/* 521*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 522*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 523*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 524*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 525*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 526*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 527*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 528*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 529*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 530*/ (void *)primitiveFail,
	/* 531*/ (void *)primitiveFail,
	/* 532*/ (void *)primitiveFail,
	/* 533*/ (void *)primitiveFail,
	/* 534*/ (void *)primitiveFail,
	/* 535*/ (void *)primitiveFail,
	/* 536*/ (void *)primitiveFail,
	/* 537*/ (void *)primitiveFail,
	/* 538*/ (void *)primitiveFail,
	/* 539*/ (void *)primitiveFail,
	/* 540*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 541*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 542*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 543*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 544*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 545*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 546*/ (void *)primitiveFail,
	/* 547*/ (void *)primitiveFail,
	/* 548*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 549*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 550*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 551*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 552*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 553*/ (void *)primitiveObsoleteIndexedPrimitive,
	/* 554*/ (void *)primitiveFail,
	/* 555*/ (void *)primitiveFail,
	/* 556*/ (void *)primitiveFail,
	/* 557*/ (void *)primitiveFail,
	/* 558*/ (void *)primitiveFail,
	/* 559*/ (void *)primitiveFail,
	/* 560*/ (void *)primitiveFail,
	/* 561*/ (void *)primitiveFail,
	/* 562*/ (void *)primitiveFail,
	/* 563*/ (void *)primitiveFail,
	/* 564*/ (void *)primitiveFail,
	/* 565*/ (void *)primitiveFail,
	/* 566*/ (void *)primitiveFail,
	/* 567*/ (void *)primitiveFail,
	/* 568*/ (void *)primitiveFail,
	/* 569*/ (void *)primitiveFail,
	/* 570*/ (void *)primitiveFlushExternalPrimitives,
	/* 571*/ (void *)primitiveUnloadModule,
	/* 572*/ (void *)primitiveListBuiltinModule,
	/* 573*/ (void *)primitiveListExternalModule,
	/* 574*/ (void *)primitiveFail,
	/* 575*/ (void *)primitiveFail,
 0 };
sqInt processSignalingLowSpace;
sqInt receiver;
sqInt receiverClass;
sqInt reclaimableContextCount;
sqInt remapBuffer[26];
sqInt remapBufferCount;
sqInt rootTable[2501];
sqInt rootTableCount;
sqInt savedWindowSize;
sqInt semaphoresToSignalA[501];
sqInt semaphoresToSignalB[501];
sqInt semaphoresToSignalCountA;
sqInt semaphoresToSignalCountB;
sqInt semaphoresUseBufferA;
void* showSurfaceFn;
sqInt shrinkThreshold;
sqInt signalLowSpace;
sqInt specialObjectsOop;
usqInt stackPointer;
sqInt statAllocationCount;
sqInt statCompMoveCount;
sqInt statFullGCMSecs;
sqInt statFullGCs;
sqInt statGCTime;
sqInt statGrowMemory;
sqInt statIGCDeltaTime;
sqInt statIncrGCMSecs;
sqInt statIncrGCs;
sqInt statMarkCount;
sqInt statMkFwdCount;
sqInt statRootTableCount;
sqInt statRootTableOverflows;
sqInt statShrinkMemory;
sqInt statSpecialMarkCount;
sqInt statSurvivorCount;
sqInt statSweepCount;
sqInt statTenures;
sqInt statpendingFinalizationSignals;
sqInt successFlag;
sqInt suspendedCallbacks[33];
sqInt suspendedMethods[33];
sqInt tenuringThreshold;
usqInt theHomeContext;
sqInt totalObjectCount;
sqInt trueObj;
sqInt vmRecursionDepth;
sqInt weakRootCount;
sqInt weakRoots[2625];
usqInt youngStart;



/*	Return the accessible object following the given object or 
	free chunk in the heap. Return nil when heap is exhausted. */

sqInt accessibleObjectAfter(sqInt oop) {
    sqInt obj;
    sqInt sz;
    sqInt header;
    sqInt sz1;
    sqInt header1;

	/* begin objectAfter: */
	if (DoAssertionChecks) {
		if ((((usqInt) oop)) >= (((usqInt) endOfMemory))) {
			error("no objects after the end of memory");
		}
	}
	if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
		sz1 = (longAt(oop)) & AllButTypeMask;
	} else {
		/* begin sizeBitsOf: */
		header1 = longAt(oop);
		if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
			sz1 = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
			goto l2;
		} else {
			sz1 = header1 & SizeMask;
			goto l2;
		}
	l2:	/* end sizeBitsOf: */;
	}
	obj = (oop + sz1) + (headerTypeBytes[(longAt(oop + sz1)) & TypeMask]);
	while ((((usqInt) obj)) < (((usqInt) endOfMemory))) {
		if (!(((longAt(obj)) & TypeMask) == HeaderTypeFree)) {
			return obj;
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) obj)) >= (((usqInt) endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(obj)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(obj)) & AllButTypeMask;
		} else {
			/* begin sizeBitsOf: */
			header = longAt(obj);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(obj - (BytesPerWord * 2))) & LongSizeMask;
				goto l1;
			} else {
				sz = header & SizeMask;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		obj = (obj + sz) + (headerTypeBytes[(longAt(obj + sz)) & TypeMask]);
	}
	return null;
}


/*	Similar to activateNewMethod but for Closure and newMethod. */

sqInt activateNewClosureMethod(sqInt blockClosure) {
    sqInt numCopied;
    sqInt where;
    sqInt i;
    sqInt theBlockClosure;
    sqInt closureMethod;
    sqInt newContext;
    sqInt methodHeader;
    sqInt outerContext;
    sqInt oop;
    sqInt tmp;

	if (DoAssertionChecks) {
		okayOop(blockClosure);
	}
	outerContext = longAt((blockClosure + BaseHeaderSize) + (ClosureOuterContextIndex << ShiftForWord));
	if (DoAssertionChecks) {
		okayOop(outerContext);
	}
	closureMethod = longAt((outerContext + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	methodHeader = longAt((closureMethod + BaseHeaderSize) + (HeaderIndex << ShiftForWord));
	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = blockClosure;

	/* All for one, and one for all! */
	/* allocateOrRecycleContext: may cause a GC; restore blockClosure and refetch outerContext et al */

	newContext = allocateOrRecycleContext(methodHeader & LargeContextBit);
	/* begin popRemappableOop */
	oop = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	theBlockClosure = oop;
	outerContext = longAt((theBlockClosure + BaseHeaderSize) + (ClosureOuterContextIndex << ShiftForWord));

	/* Assume: newContext will be recorded as a root if necessary by the
	 call to newActiveContext: below, so we can use unchecked stores. */

	numCopied = (fetchWordLengthOf(theBlockClosure)) - ClosureFirstCopiedValueIndex;
	where = newContext + BaseHeaderSize;
	longAtput(where + (SenderIndex << ShiftForWord), activeContext);
	longAtput(where + (InstructionPointerIndex << ShiftForWord), longAt((theBlockClosure + BaseHeaderSize) + (ClosureStartPCIndex << ShiftForWord)));
	longAtput(where + (StackPointerIndex << ShiftForWord), (((argumentCount + numCopied) << 1) | 1));
	longAtput(where + (MethodIndex << ShiftForWord), longAt((outerContext + BaseHeaderSize) + (MethodIndex << ShiftForWord)));
	longAtput(where + (ClosureIndex << ShiftForWord), theBlockClosure);
	longAtput(where + (ReceiverIndex << ShiftForWord), longAt((outerContext + BaseHeaderSize) + (ReceiverIndex << ShiftForWord)));
	for (i = 1; i <= argumentCount; i += 1) {
		longAtput(where + ((ReceiverIndex + i) << ShiftForWord), longAt(stackPointer - ((argumentCount - i) * BytesPerWord)));
	}
	where = (newContext + BaseHeaderSize) + (((ReceiverIndex + 1) + argumentCount) << ShiftForWord);
	for (i = 0; i <= (numCopied - 1); i += 1) {
		longAtput(where + (i << ShiftForWord), longAt((theBlockClosure + BaseHeaderSize) + ((i + ClosureFirstCopiedValueIndex) << ShiftForWord)));
	}
	/* begin pop: */
	stackPointer -= (argumentCount + 1) * BytesPerWord;
	/* begin newActiveContext: */
	/* begin storeContextRegisters: */
	longAtput((activeContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord), ((((instructionPointer - method) - (BaseHeaderSize - 2)) << 1) | 1));
	longAtput((activeContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord), (((((((usqInt) ((stackPointer - activeContext) - BaseHeaderSize)) >> ShiftForWord) - TempFrameStart) + 1) << 1) | 1));
	if ((((usqInt) newContext)) < (((usqInt) youngStart))) {
		beRootIfOld(newContext);
	}
	activeContext = newContext;
	/* begin fetchContextRegisters: */
	tmp = longAt((newContext + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	if ((tmp & 1)) {
		tmp = longAt((newContext + BaseHeaderSize) + (HomeIndex << ShiftForWord));
		if ((((usqInt) tmp)) < (((usqInt) youngStart))) {
			beRootIfOld(tmp);
		}
	} else {
		tmp = newContext;
	}
	theHomeContext = tmp;
	receiver = longAt((tmp + BaseHeaderSize) + (ReceiverIndex << ShiftForWord));
	method = longAt((tmp + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	tmp = ((longAt((newContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord))) >> 1);
	instructionPointer = ((method + tmp) + BaseHeaderSize) - 2;
	tmp = ((longAt((newContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord))) >> 1);
	stackPointer = (newContext + BaseHeaderSize) + (((TempFrameStart + tmp) - 1) * BytesPerWord);
}

sqInt activateNewMethod(void) {
    sqInt tempCount;
    sqInt nilOop;
    sqInt where;
    sqInt initialIP;
    sqInt i;
    sqInt newContext;
    sqInt methodHeader;
    sqInt tmp;

	methodHeader = longAt((newMethod + BaseHeaderSize) + (HeaderIndex << ShiftForWord));
	newContext = allocateOrRecycleContext(methodHeader & LargeContextBit);
	initialIP = ((LiteralStart + ((((usqInt) methodHeader) >> 10) & 255)) * BytesPerWord) + 1;

	/* Assume: newContext will be recorded as a root if necessary by the
	 call to newActiveContext: below, so we can use unchecked stores. */

	tempCount = (((usqInt) methodHeader) >> 19) & 63;
	where = newContext + BaseHeaderSize;
	longAtput(where + (SenderIndex << ShiftForWord), activeContext);
	longAtput(where + (InstructionPointerIndex << ShiftForWord), ((initialIP << 1) | 1));
	longAtput(where + (StackPointerIndex << ShiftForWord), ((tempCount << 1) | 1));
	longAtput(where + (MethodIndex << ShiftForWord), newMethod);
	longAtput(where + (ClosureIndex << ShiftForWord), nilObj);
	for (i = 0; i <= argumentCount; i += 1) {
		longAtput(where + ((ReceiverIndex + i) << ShiftForWord), longAt(stackPointer - ((argumentCount - i) * BytesPerWord)));
	}
	nilOop = nilObj;
	for (i = ((argumentCount + 1) + ReceiverIndex); i <= (tempCount + ReceiverIndex); i += 1) {
		longAtput(where + (i << ShiftForWord), nilOop);
	}
	/* begin pop: */
	stackPointer -= (argumentCount + 1) * BytesPerWord;
	reclaimableContextCount += 1;
	/* begin newActiveContext: */
	/* begin storeContextRegisters: */
	longAtput((activeContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord), ((((instructionPointer - method) - (BaseHeaderSize - 2)) << 1) | 1));
	longAtput((activeContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord), (((((((usqInt) ((stackPointer - activeContext) - BaseHeaderSize)) >> ShiftForWord) - TempFrameStart) + 1) << 1) | 1));
	if ((((usqInt) newContext)) < (((usqInt) youngStart))) {
		beRootIfOld(newContext);
	}
	activeContext = newContext;
	/* begin fetchContextRegisters: */
	tmp = longAt((newContext + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	if ((tmp & 1)) {
		tmp = longAt((newContext + BaseHeaderSize) + (HomeIndex << ShiftForWord));
		if ((((usqInt) tmp)) < (((usqInt) youngStart))) {
			beRootIfOld(tmp);
		}
	} else {
		tmp = newContext;
	}
	theHomeContext = tmp;
	receiver = longAt((tmp + BaseHeaderSize) + (ReceiverIndex << ShiftForWord));
	method = longAt((tmp + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	tmp = ((longAt((newContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord))) >> 1);
	instructionPointer = ((method + tmp) + BaseHeaderSize) - 2;
	tmp = ((longAt((newContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord))) >> 1);
	stackPointer = (newContext + BaseHeaderSize) + (((TempFrameStart + tmp) - 1) * BytesPerWord);
}


/*	Add the given variable location to the extra roots table */

EXPORT(sqInt) addGCRoot(sqInt *varLoc) {
	if (extraRootCount >= ExtraRootSize) {
		return 0;
	}
	extraRoots[extraRootCount += 1] = varLoc;
	return 1;
}


/*	Add the given entry to the method cache.
	The policy is as follows:
		Look for an empty entry anywhere in the reprobe chain.
		If found, install the new entry there.
		If not found, then install the new entry at the first probe position
			and delete the entries in the rest of the reprobe chain.
		This has two useful purposes:
			If there is active contention over the first slot, the second
				or third will likely be free for reentry after ejection.
			Also, flushing is good when reprobe chains are getting full. */

sqInt addNewMethodToCache(void) {
    sqInt hash;
    sqInt p;
    sqInt probe;

	compilerInitialized && (compilerTranslateMethod());

	/* drop low-order zeros from addresses */

	hash = messageSelector ^ lkupClass;
	primitiveFunctionPointer = primitiveTable[primitiveIndex];
	for (p = 0; p <= (CacheProbeMax - 1); p += 1) {
		probe = (((usqInt) hash) >> p) & MethodCacheMask;
		if ((methodCache[probe + MethodCacheSelector]) == 0) {
			methodCache[probe + MethodCacheSelector] = messageSelector;
			methodCache[probe + MethodCacheClass] = lkupClass;
			methodCache[probe + MethodCacheMethod] = newMethod;
			methodCache[probe + MethodCachePrim] = primitiveIndex;
			methodCache[probe + MethodCacheNative] = newNativeMethod;
			methodCache[probe + MethodCachePrimFunction] = (((long) primitiveFunctionPointer));
			return null;
		}
	}

	/* first probe */

	probe = hash & MethodCacheMask;
	methodCache[probe + MethodCacheSelector] = messageSelector;
	methodCache[probe + MethodCacheClass] = lkupClass;
	methodCache[probe + MethodCacheMethod] = newMethod;
	methodCache[probe + MethodCachePrim] = primitiveIndex;
	methodCache[probe + MethodCacheNative] = newNativeMethod;
	methodCache[probe + MethodCachePrimFunction] = (((long) primitiveFunctionPointer));
	for (p = 1; p <= (CacheProbeMax - 1); p += 1) {
		probe = (((usqInt) hash) >> p) & MethodCacheMask;
		methodCache[probe + MethodCacheSelector] = 0;
	}
}


/*	Add the given function address to the external primitive table and return the index where it's stored. This function doesn't need to be fast since it is only called when an external primitive has been looked up (which takes quite a bit of time itself). So there's nothing specifically complicated here.
	Note: Return index will be one-based (ST convention) */

sqInt addToExternalPrimitiveTable(void *functionAddress) {
    sqInt i;

	for (i = 0; i <= (MaxExternalPrimitiveTableSize - 1); i += 1) {
		if ((externalPrimitiveTable[i]) == 0) {
			externalPrimitiveTable[i] = functionAddress;
			return i + 1;
		}
	}
	return 0;
}


/*	Adjust all oop references by the given number of bytes. This 
	is done just after reading in an image when the new base 
	address of the object heap is different from the base address 
	in the image. */
/*	di 11/18/2000 - return number of objects found */

sqInt adjustAllOopsBy(sqInt bytesToShift) {
    sqInt oop;
    sqInt totalObjects;
    sqInt fieldAddr;
    sqInt classHeader;
    sqInt fieldOop;
    sqInt newClassOop;
    sqInt sz;
    sqInt header;

	if (bytesToShift == 0) {
		return 300000;
	}
	totalObjects = 0;
	oop = memory + (headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) endOfMemory))) {
		if (!(((longAt(oop)) & TypeMask) == HeaderTypeFree)) {
			totalObjects += 1;
			/* begin adjustFieldsAndClassOf:by: */
			if (bytesToShift == 0) {
				goto l1;
			}
			fieldAddr = oop + (lastPointerOf(oop));
			while ((((usqInt) fieldAddr)) > (((usqInt) oop))) {
				fieldOop = longAt(fieldAddr);
				if (!((fieldOop & 1))) {
					longAtput(fieldAddr, fieldOop + bytesToShift);
				}
				fieldAddr -= BytesPerWord;
			}
			if (((longAt(oop)) & TypeMask) != HeaderTypeShort) {
				classHeader = longAt(oop - BytesPerWord);
				newClassOop = (classHeader & AllButTypeMask) + bytesToShift;
				longAtput(oop - BytesPerWord, newClassOop | (classHeader & TypeMask));
			}
		l1:	/* end adjustFieldsAndClassOf:by: */;
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) oop)) >= (((usqInt) endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(oop)) & AllButTypeMask;
		} else {
			/* begin sizeBitsOf: */
			header = longAt(oop);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
				goto l2;
			} else {
				sz = header & SizeMask;
				goto l2;
			}
		l2:	/* end sizeBitsOf: */;
		}
		oop = (oop + sz) + (headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	}
	return totalObjects;
}


/*	Return true if all the oops in both arrays, and the arrays 
	themselves, are in the young object space. */

sqInt allYoungand(sqInt array1, sqInt array2) {
    sqInt fieldOffset;
    sqInt sz;
    sqInt header;
    sqInt contextSize;
    sqInt fmt;
    sqInt methodHeader;
    sqInt sp;
    sqInt header1;
    sqInt type;

	if ((((usqInt) array1)) < (((usqInt) youngStart))) {
		return 0;
	}
	if ((((usqInt) array2)) < (((usqInt) youngStart))) {
		return 0;
	}
	/* begin lastPointerOf: */
	header = longAt(array1);
	fmt = (((usqInt) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && ((((((usqInt) header) >> 12) & 31) == 13) || ((((((usqInt) header) >> 12) & 31) == 14) || (((((usqInt) header) >> 12) & 31) == 4)))) {
			/* begin fetchStackPointerOf: */
			sp = longAt((array1 + BaseHeaderSize) + (StackPointerIndex << ShiftForWord));
			if (!((sp & 1))) {
				contextSize = 0;
				goto l2;
			}
			contextSize = (sp >> 1);
		l2:	/* end fetchStackPointerOf: */;
			fieldOffset = (CtxtTempFrameStart + contextSize) * BytesPerWord;
			goto l1;
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(array1);
		/* begin rightType: */
		if ((header1 & SizeMask) == 0) {
			type = HeaderTypeSizeAndClass;
			goto l3;
		} else {
			if ((header1 & CompactClassMask) == 0) {
				type = HeaderTypeClass;
				goto l3;
			} else {
				type = HeaderTypeShort;
				goto l3;
			}
		}
	l3:	/* end rightType: */;
		if (type == HeaderTypeSizeAndClass) {
			sz = (longAt(array1 - (BytesPerWord * 2))) & AllButTypeMask;
			goto l4;
		} else {
			sz = header1 & SizeMask;
			goto l4;
		}
	l4:	/* end sizeBitsOfSafe: */;
		fieldOffset = sz - BaseHeaderSize;
		goto l1;
	}
	if (fmt < 12) {
		fieldOffset = 0;
		goto l1;
	}
	methodHeader = longAt(array1 + BaseHeaderSize);
	fieldOffset = (((((usqInt) methodHeader) >> 10) & 255) * BytesPerWord) + BaseHeaderSize;
l1:	/* end lastPointerOf: */;
	while (fieldOffset >= BaseHeaderSize) {
		if ((((usqInt) (longAt(array1 + fieldOffset)))) < (((usqInt) youngStart))) {
			return 0;
		}
		if ((((usqInt) (longAt(array2 + fieldOffset)))) < (((usqInt) youngStart))) {
			return 0;
		}
		fieldOffset -= BytesPerWord;
	}
	return 1;
}


/*	Allocate a chunk of the given size. Sender must be sure that  the requested size includes enough space for the header  word(s).  */
/*	Details: To limit the time per incremental GC, do one every so many allocations. The number is settable via primitiveVMParameter to tune your memory system */

sqInt allocateChunk(sqInt byteSize) {
    sqInt newFreeSize;
    sqInt enoughSpace;
    sqInt newChunk;
    usqInt minFree;
    sqInt sched;
    sqInt lastSavedProcess;
    sqInt currentProc;
    sqInt oop;

	if (allocationCount >= allocationsBetweenGCs) {
		incrementalGC();
	}
	/* begin sufficientSpaceToAllocate: */
	minFree = (lowSpaceThreshold + byteSize) + BaseHeaderSize;
	if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) >= (((usqInt) minFree))) {
		enoughSpace = 1;
		goto l1;
	} else {
		enoughSpace = sufficientSpaceAfterGC(minFree);
		goto l1;
	}
l1:	/* end sufficientSpaceToAllocate: */;
	if (!(enoughSpace)) {

		/* signal that space is running low, but proceed with allocation if possible */

		signalLowSpace = 1;

		/* disable additional interrupts until lowSpaceThreshold is reset by image */

		lowSpaceThreshold = 0;
		/* begin saveProcessSignalingLowSpace */
		lastSavedProcess = longAt((specialObjectsOop + BaseHeaderSize) + (ProcessSignalingLowSpace << ShiftForWord));
		if (lastSavedProcess == nilObj) {
			sched = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord));
			currentProc = longAt((sched + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
			/* begin storePointer:ofObject:withValue: */
			oop = specialObjectsOop;
			if ((((usqInt) oop)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(oop, currentProc);
			}
			longAtput((oop + BaseHeaderSize) + (ProcessSignalingLowSpace << ShiftForWord), currentProc);
		}
		/* begin forceInterruptCheck */
		interruptCheckCounter = -1000;
		nextPollTick = 0;
	}
	if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) < (((usqInt) (byteSize + BaseHeaderSize)))) {
		error("out of memory");
	}
	newFreeSize = ((longAt(freeBlock)) & AllButTypeMask) - byteSize;
	newChunk = freeBlock;

	/* Assume: client will initialize object header of free chunk, so following is not needed: */
	/* self setSizeOfFree: newChunk to: byteSize. */

	freeBlock += byteSize;
	/* begin setSizeOfFree:to: */
	longAtput(freeBlock, (newFreeSize & AllButTypeMask) | HeaderTypeFree);
	allocationCount += 1;
	return newChunk;
}


/*	Return a recycled context or a newly allocated one if none is available for recycling. */

sqInt allocateOrRecycleContext(sqInt needsLarge) {
    sqInt cntxt;

	if (needsLarge == 0) {
		if (freeContexts != NilContext) {
			cntxt = freeContexts;
			freeContexts = longAt((cntxt + BaseHeaderSize) + (0 << ShiftForWord));
			return cntxt;
		}
	} else {
		if (freeLargeContexts != NilContext) {
			cntxt = freeLargeContexts;
			freeLargeContexts = longAt((cntxt + BaseHeaderSize) + (0 << ShiftForWord));
			return cntxt;
		}
	}
	if (needsLarge == 0) {
		cntxt = instantiateContextsizeInBytes(longAt((specialObjectsOop + BaseHeaderSize) + (ClassMethodContext << ShiftForWord)), SmallContextSize);
	} else {
		cntxt = instantiateContextsizeInBytes(longAt((specialObjectsOop + BaseHeaderSize) + (ClassMethodContext << ShiftForWord)), LargeContextSize);
	}
	longAtput((cntxt + BaseHeaderSize) + (4 << ShiftForWord), nilObj);
	return cntxt;
}

sqInt argumentCountOf(sqInt methodPointer) {
	return (((usqInt) (longAt((methodPointer + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 25) & 15;
}


/*	Return the address of first indexable field of resulting array object, or fail if the instance variable does not contain an indexable bytes or words object. */
/*	Note: May be called by translated primitive code. */

void * arrayValueOf(sqInt arrayOop) {
	if ((!((arrayOop & 1))) && (((arrayOop & 1) == 0) && (isWordsOrBytesNonInt(arrayOop)))) {
		return pointerForOop(arrayOop + BaseHeaderSize);
	}
	/* begin primitiveFail */
	successFlag = 0;
}


/*	Returns an integer object */

sqInt asciiOfCharacter(sqInt characterObj) {
    sqInt cl;
    sqInt ccIndex;

	/* begin assertClassOf:is: */
	if ((characterObj & 1)) {
		successFlag = 0;
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(characterObj))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(characterObj - BaseHeaderSize)) & AllButTypeMask;
	} else {
		cl = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
	}
	/* begin success: */
	successFlag = (cl == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassCharacter << ShiftForWord)))) && successFlag;
l1:	/* end assertClassOf:is: */;
	if (successFlag) {
		return longAt((characterObj + BaseHeaderSize) + (CharacterValueIndex << ShiftForWord));
	} else {
		return ConstZero;
	}
}


/*	Return true if the stack is still balanced after executing primitive primIndex with nArgs args. Delta is 'stackPointer - activeContext' which is a relative measure for the stack pointer (so we don't have to relocate it during the primitive) */

sqInt balancedStackafterPrimitivewithArgs(sqInt delta, sqInt primIdx, sqInt nArgs) {
	if ((primIdx >= 81) && (primIdx <= 88)) {
		return 1;
	}
	if (successFlag) {
		return ((stackPointer - activeContext) + (nArgs * BytesPerWord)) == delta;
	}
	return (stackPointer - activeContext) == delta;
}


/*	If this object is old, mark it as a root (because a new object 
	may be stored into it) */

sqInt beRootIfOld(sqInt oop) {
    sqInt header;

	if (((((usqInt) oop)) < (((usqInt) youngStart))) && (!((oop & 1)))) {
		/* begin noteAsRoot:headerLoc: */
		header = longAt(oop);
		if ((header & RootBit) == 0) {
			if (rootTableCount < RootTableRedZone) {
				rootTableCount += 1;
				rootTable[rootTableCount] = oop;
				longAtput(oop, header | RootBit);
			} else {
				if (rootTableCount < RootTableSize) {
					rootTableCount += 1;
					rootTable[rootTableCount] = oop;
					longAtput(oop, header | RootBit);
					allocationCount = allocationsBetweenGCs + 1;
				}
			}
		}
	}
}

sqInt becomewith(sqInt array1, sqInt array2) {
	return becomewithtwoWaycopyHash(array1, array2, 1, 1);
}


/*	All references to each object in array1 are swapped with all references to the corresponding object in array2. That is, all pointers to one object are replaced with with pointers to the other. The arguments must be arrays of the same length. 
	Returns true if the primitive succeeds. */
/*	Implementation: Uses forwarding blocks to update references as done in compaction. */

sqInt becomewithtwoWaycopyHash(sqInt array1, sqInt array2, sqInt twoWayFlag, sqInt copyHashFlag) {
    sqInt hdr1;
    sqInt oop1;
    sqInt hdr2;
    sqInt fwdBlock;
    sqInt oop2;
    sqInt fwdBlock1;
    sqInt fwdHeader;
    sqInt hdr11;
    sqInt fieldOffset;
    sqInt oop11;
    sqInt hdr21;
    sqInt oop21;
    sqInt fwdBlock2;
    sqInt fwdHeader2;
    sqInt fwdBlock11;
    sqInt fwdHeader1;
    sqInt sz;
    sqInt header;
    sqInt contextSize;
    sqInt fmt;
    sqInt methodHeader;
    sqInt sp;
    sqInt header1;
    sqInt type;

	if (!(((array1 & 1) == 0) && (((((usqInt) (longAt(array1))) >> 8) & 15) == 2))) {
		return 0;
	}
	if (!(((array2 & 1) == 0) && (((((usqInt) (longAt(array2))) >> 8) & 15) == 2))) {
		return 0;
	}
	if (!((lastPointerOf(array1)) == (lastPointerOf(array2)))) {
		return 0;
	}
	if (!(containOnlyOopsand(array1, array2))) {
		return 0;
	}
	if (!(prepareForwardingTableForBecomingwithtwoWay(array1, array2, twoWayFlag))) {
		return 0;
	}
	if (allYoungand(array1, array2)) {
		mapPointersInObjectsFromto(youngStart, endOfMemory);
	} else {
		mapPointersInObjectsFromto(memory, endOfMemory);
	}
	if (twoWayFlag) {
		/* begin restoreHeadersAfterBecoming:with: */
		/* begin lastPointerOf: */
		header = longAt(array1);
		fmt = (((usqInt) header) >> 8) & 15;
		if (fmt <= 4) {
			if ((fmt == 3) && ((((((usqInt) header) >> 12) & 31) == 13) || ((((((usqInt) header) >> 12) & 31) == 14) || (((((usqInt) header) >> 12) & 31) == 4)))) {
				/* begin fetchStackPointerOf: */
				sp = longAt((array1 + BaseHeaderSize) + (StackPointerIndex << ShiftForWord));
				if (!((sp & 1))) {
					contextSize = 0;
					goto l2;
				}
				contextSize = (sp >> 1);
			l2:	/* end fetchStackPointerOf: */;
				fieldOffset = (CtxtTempFrameStart + contextSize) * BytesPerWord;
				goto l1;
			}
			/* begin sizeBitsOfSafe: */
			header1 = longAt(array1);
			/* begin rightType: */
			if ((header1 & SizeMask) == 0) {
				type = HeaderTypeSizeAndClass;
				goto l3;
			} else {
				if ((header1 & CompactClassMask) == 0) {
					type = HeaderTypeClass;
					goto l3;
				} else {
					type = HeaderTypeShort;
					goto l3;
				}
			}
		l3:	/* end rightType: */;
			if (type == HeaderTypeSizeAndClass) {
				sz = (longAt(array1 - (BytesPerWord * 2))) & AllButTypeMask;
				goto l4;
			} else {
				sz = header1 & SizeMask;
				goto l4;
			}
		l4:	/* end sizeBitsOfSafe: */;
			fieldOffset = sz - BaseHeaderSize;
			goto l1;
		}
		if (fmt < 12) {
			fieldOffset = 0;
			goto l1;
		}
		methodHeader = longAt(array1 + BaseHeaderSize);
		fieldOffset = (((((usqInt) methodHeader) >> 10) & 255) * BytesPerWord) + BaseHeaderSize;
	l1:	/* end lastPointerOf: */;
		while (fieldOffset >= BaseHeaderSize) {
			oop11 = longAt(array1 + fieldOffset);
			oop21 = longAt(array2 + fieldOffset);
			if (!(oop11 == oop21)) {
				/* begin restoreHeaderOf: */
				fwdHeader2 = longAt(oop11);
				fwdBlock2 = (fwdHeader2 & AllButMarkBitAndTypeMask) << 1;
				if (DoAssertionChecks) {
					if ((fwdHeader2 & MarkBit) == 0) {
						error("attempting to restore the header of an object that has no forwarding block");
					}
					/* begin fwdBlockValidate: */
					if (!(((((usqInt) fwdBlock2)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock2)) <= (((usqInt) fwdTableNext))) && ((fwdBlock2 & 3) == 0)))) {
						error("invalid fwd table entry");
					}
				}
				longAtput(oop11, longAt(fwdBlock2 + BytesPerWord));
				/* begin restoreHeaderOf: */
				fwdHeader1 = longAt(oop21);
				fwdBlock11 = (fwdHeader1 & AllButMarkBitAndTypeMask) << 1;
				if (DoAssertionChecks) {
					if ((fwdHeader1 & MarkBit) == 0) {
						error("attempting to restore the header of an object that has no forwarding block");
					}
					/* begin fwdBlockValidate: */
					if (!(((((usqInt) fwdBlock11)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock11)) <= (((usqInt) fwdTableNext))) && ((fwdBlock11 & 3) == 0)))) {
						error("invalid fwd table entry");
					}
				}
				longAtput(oop21, longAt(fwdBlock11 + BytesPerWord));
				hdr11 = longAt(oop11);
				hdr21 = longAt(oop21);
				longAtput(oop11, (hdr11 & AllButHashBits) | (hdr21 & HashBits));
				longAtput(oop21, (hdr21 & AllButHashBits) | (hdr11 & HashBits));
			}
			fieldOffset -= BytesPerWord;
		}
	} else {
		/* begin restoreHeadersAfterForwardBecome: */
		fwdBlock = ((endOfMemory + BaseHeaderSize) + 7) & (WordMask - 7);
		flag("Dan");
		fwdBlock += BytesPerWord * 4;
		while ((((usqInt) fwdBlock)) <= (((usqInt) fwdTableNext))) {
			oop1 = longAt(fwdBlock + (BytesPerWord * 2));
			oop2 = longAt(fwdBlock);
			/* begin restoreHeaderOf: */
			fwdHeader = longAt(oop1);
			fwdBlock1 = (fwdHeader & AllButMarkBitAndTypeMask) << 1;
			if (DoAssertionChecks) {
				if ((fwdHeader & MarkBit) == 0) {
					error("attempting to restore the header of an object that has no forwarding block");
				}
				/* begin fwdBlockValidate: */
				if (!(((((usqInt) fwdBlock1)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock1)) <= (((usqInt) fwdTableNext))) && ((fwdBlock1 & 3) == 0)))) {
					error("invalid fwd table entry");
				}
			}
			longAtput(oop1, longAt(fwdBlock1 + BytesPerWord));
			if (copyHashFlag) {
				hdr1 = longAt(oop1);
				hdr2 = longAt(oop2);
				longAtput(oop2, (hdr2 & AllButHashBits) | (hdr1 & HashBits));
			}
			fwdBlock += BytesPerWord * 4;
		}
	}
	initializeMemoryFirstFree(freeBlock);
	/* begin forceInterruptCheck */
	interruptCheckCounter = -1000;
	nextPollTick = 0;
	return 1;
}

sqInt biasToGrow(void) {
    usqInt growSize;

	growSize = (((sqInt) (growHeadroom * 3) >> 1)) - ((longAt(freeBlock)) & AllButTypeMask);
	if (growSize > 0) {
		growObjectMemory(growSize);
	}
}


/*	convert true and false (Smalltalk) to true or false(C) */

sqInt booleanValueOf(sqInt obj) {
	if (obj == trueObj) {
		return 1;
	}
	if (obj == falseObj) {
		return 0;
	}
	successFlag = 0;
	return null;
}

sqInt byteSizeOf(sqInt oop) {
    sqInt slots;
    sqInt header;
    sqInt sz;

	flag("Dan");
	if ((oop & 1)) {
		return 0;
	}
	/* begin slotSizeOf: */
	if ((oop & 1)) {
		slots = 0;
		goto l1;
	}
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz = header & SizeMask;
	}
	sz -= header & Size4Bit;
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		slots = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
		goto l2;
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		slots = ((usqInt) (sz - BaseHeaderSize)) >> 2;
		goto l2;
	} else {
		slots = (sz - BaseHeaderSize) - (((((usqInt) header) >> 8) & 15) & 3);
		goto l2;
	}
	slots = null;
l2:	/* end lengthOf: */;
l1:	/* end slotSizeOf: */;
	if (((((usqInt) (longAt(oop))) >> 8) & 15) >= 8) {
		return slots;
	} else {
		return slots * 4;
	}
}


/*	Byte-swap the words of all bytes objects in a range of the 
	image, including Strings, ByteArrays, and CompiledMethods. 
	This returns these objects to their original byte ordering 
	after blindly byte-swapping the entire image. For compiled 
	methods, byte-swap only their bytecodes part. */

sqInt byteSwapByteObjectsFromto(sqInt startOop, sqInt stopAddr) {
    sqInt oop;
    sqInt fmt;
    sqInt methodHeader;
    sqInt wordAddr;
    sqInt stopAddr1;
    sqInt addr;
    sqInt stopAddr2;
    sqInt addr1;
    sqInt sz;
    sqInt header;

	oop = startOop;
	while ((((usqInt) oop)) < (((usqInt) stopAddr))) {
		if (!(((longAt(oop)) & TypeMask) == HeaderTypeFree)) {
			fmt = (((usqInt) (longAt(oop))) >> 8) & 15;
			if (fmt >= 8) {

				/* oop contains bytes */

				wordAddr = oop + BaseHeaderSize;
				if (fmt >= 12) {

					/* compiled method; start after methodHeader and literals */

					methodHeader = longAt(oop + BaseHeaderSize);
					wordAddr = (wordAddr + BytesPerWord) + (((((usqInt) methodHeader) >> 10) & 255) * BytesPerWord);
				}
				/* begin reverseBytesFrom:to: */
				stopAddr1 = oop + (sizeBitsOf(oop));
				flag("Dan");
				addr = wordAddr;
				while ((((usqInt) addr)) < (((usqInt) stopAddr1))) {
					longAtput(addr, byteSwapped(longAt(addr)));
					addr += BytesPerWord;
				}
			}
			if ((fmt == 6) && (BytesPerWord == 8)) {

				/* Object contains 32-bit half-words packed into 64-bit machine words. */

				wordAddr = oop + BaseHeaderSize;
				/* begin reverseWordsFrom:to: */
				stopAddr2 = oop + (sizeBitsOf(oop));
				addr1 = wordAddr;
				while ((((usqInt) addr1)) < (((usqInt) stopAddr2))) {
					longAtput(addr1, wordSwapped(longAt(addr1)));
					addr1 += BytesPerWord;
				}
			}
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) oop)) >= (((usqInt) endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(oop)) & AllButTypeMask;
		} else {
			/* begin sizeBitsOf: */
			header = longAt(oop);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
				goto l1;
			} else {
				sz = header & SizeMask;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		oop = (oop + sz) + (headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	}
}


/*	Answer the given integer with its bytes in the reverse order. */

sqInt byteSwapped(sqInt w) {
	if (BytesPerWord == 4) {
		return ((((((usqInt) w >> 24)) & Byte0Mask) + ((((usqInt) w >> 8)) & Byte1Mask)) + ((((usqInt) w << 8)) & Byte2Mask)) + ((((usqInt) w << 24)) & Byte3Mask);
	} else {
		return ((((((((((usqInt) w << 0)) & Byte0Mask) + ((((usqInt) w << 0)) & Byte1Mask)) + ((((usqInt) w >> 24)) & Byte2Mask)) + ((((usqInt) w >> 8)) & Byte3Mask)) + ((((usqInt) w << 8)) & Byte4Mask)) + ((((usqInt) w << 24)) & Byte5Mask)) + ((((usqInt) w << 0)) & Byte6Mask)) + ((((usqInt) w << 0)) & Byte7Mask);
	}
}


/*	Call the external plugin function identified. In the VM this is an address, see 	InterpreterSimulator for it's version.  */

sqInt callExternalPrimitive(void * functionID) {
	dispatchFunctionPointer(functionID);
}


/*	External call into the interpreter */

EXPORT(sqInt) callInterpreter(void) {
	interpret();
}


/*	Do everything necessary to end a callback. */

sqInt callbackEnd(void) {
    sqInt activeProc;
    sqInt fauxContext;
    sqInt activeCntx;
    sqInt tmp;

	if ((vmRecursionDepth -= 1) == 0) {
		return 1;
	}
	activeProc = removeFirstLinkOfList(callbackSemaphore());
	fauxContext = longAt((activeProc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord));
	/* begin storePointer:ofObject:withValue: */
	if ((((usqInt) activeProc)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(activeProc, longAt((fauxContext + BaseHeaderSize) + (SenderIndex << ShiftForWord)));
	}
	longAtput((activeProc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord), longAt((fauxContext + BaseHeaderSize) + (SenderIndex << ShiftForWord)));
	transferTo(activeProc);
	newMethod = longAt((fauxContext + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	argumentCount = (((usqInt) (longAt((newMethod + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 25) & 15;
	activeContext = longAt((fauxContext + BaseHeaderSize) + (SenderIndex << ShiftForWord));
	/* begin fetchContextRegisters: */
	activeCntx = activeContext;
	tmp = longAt((activeCntx + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	if ((tmp & 1)) {
		tmp = longAt((activeCntx + BaseHeaderSize) + (HomeIndex << ShiftForWord));
		if ((((usqInt) tmp)) < (((usqInt) youngStart))) {
			beRootIfOld(tmp);
		}
	} else {
		tmp = activeCntx;
	}
	theHomeContext = tmp;
	receiver = longAt((tmp + BaseHeaderSize) + (ReceiverIndex << ShiftForWord));
	method = longAt((tmp + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	tmp = ((longAt((activeCntx + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord))) >> 1);
	instructionPointer = ((method + tmp) + BaseHeaderSize) - 2;
	tmp = ((longAt((activeCntx + BaseHeaderSize) + (StackPointerIndex << ShiftForWord))) >> 1);
	stackPointer = (activeCntx + BaseHeaderSize) + (((TempFrameStart + tmp) - 1) * BytesPerWord);
	incrementalGC();
}


/*	Re-enter the interpreter for executing a callback */

EXPORT(sqInt) callbackEnter(sqInt *callbackID) {
    sqInt activeProc;
    sqInt result;
    sqInt processLists;
    sqInt priority;
    sqInt processList;
    sqInt myList;
    sqInt lastLink;

	if (primitiveIndex == 0) {
		return 0;
	}
	if (jmpDepth >= jmpMax) {
		return 0;
	}

	/* Suspend the currently active process */

	jmpDepth += 1;
	activeProc = longAt(((longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord))) + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
	suspendedCallbacks[jmpDepth] = activeProc;
	suspendedMethods[jmpDepth] = newMethod;
	transferTo(wakeHighestPriority());
	/* begin forceInterruptCheck */
	interruptCheckCounter = -1000;
	nextPollTick = 0;
	result = setjmp(jmpBuf[jmpDepth]);
	if (result == 0) {
		callbackID[0] = jmpDepth;
		interpret();
	}
	activeProc = longAt(((longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord))) + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
	/* begin putToSleep: */
	myList = longAt((activeProc + BaseHeaderSize) + (MyListIndex << ShiftForWord));
	if (myList == nilObj) {
		priority = ((longAt((activeProc + BaseHeaderSize) + (PriorityIndex << ShiftForWord))) >> 1);
		processLists = longAt(((longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord))) + BaseHeaderSize) + (ProcessListsIndex << ShiftForWord));
		processList = longAt((processLists + BaseHeaderSize) + ((priority - 1) << ShiftForWord));
		/* begin addLastLink:toList: */
		if ((longAt((processList + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord))) == nilObj) {
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) processList)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(processList, activeProc);
			}
			longAtput((processList + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord), activeProc);
		} else {
			lastLink = longAt((processList + BaseHeaderSize) + (LastLinkIndex << ShiftForWord));
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) lastLink)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(lastLink, activeProc);
			}
			longAtput((lastLink + BaseHeaderSize) + (NextLinkIndex << ShiftForWord), activeProc);
		}
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) processList)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(processList, activeProc);
		}
		longAtput((processList + BaseHeaderSize) + (LastLinkIndex << ShiftForWord), activeProc);
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) activeProc)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(activeProc, processList);
		}
		longAtput((activeProc + BaseHeaderSize) + (MyListIndex << ShiftForWord), processList);
	}
	activeProc = suspendedCallbacks[jmpDepth];

	/* see comment above */

	newMethod = suspendedMethods[jmpDepth];
	transferTo(activeProc);
	jmpDepth -= 1;
	return 1;
}


/*	Leave from a previous callback */

EXPORT(sqInt) callbackLeave(sqInt cbID) {
	if (primitiveIndex == 0) {
		return 0;
	}
	if (!(cbID == jmpDepth)) {
		return 0;
	}
	if (cbID < 1) {
		return 0;
	}
	longjmp(jmpBuf[jmpDepth], 1);
}


/*	Semaphore for storing suspended callback processes. */

sqInt callbackSemaphore(void) {
    sqInt callbackSema;

	if (!((stSizeOf(specialObjectsOop)) > CallbackSemaphoreIndex)) {
		return null;
	}
	callbackSema = longAt((specialObjectsOop + BaseHeaderSize) + (CallbackSemaphoreIndex << ShiftForWord));
	if (!((fetchClassOf(callbackSema)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassSemaphore << ShiftForWord))))) {
		return null;
	}
	return callbackSema;
}


/*	Do everything necessary to start a callback. */
/*	Verify presence of callback semaphore */

sqInt callbackStart(void) {
    sqInt activeProc;
    sqInt initialIP;
    sqInt fauxContext;
    sqInt valuePointer;
    sqInt valuePointer1;
    sqInt valuePointer2;
    sqInt valuePointer3;
    sqInt activeCntx;
    sqInt tmp;
    sqInt valuePointer4;
    sqInt aList;
    sqInt firstLink;
    sqInt callbackSema;

	if ((callbackSemaphore()) == null) {
		printf("No callback semaphore\n");
		return 0;
	}
	/* begin storeContextRegisters: */
	longAtput((activeContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord), ((((instructionPointer - method) - (BaseHeaderSize - 2)) << 1) | 1));
	longAtput((activeContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord), (((((((usqInt) ((stackPointer - activeContext) - BaseHeaderSize)) >> ShiftForWord) - TempFrameStart) + 1) << 1) | 1));
	fauxContext = allocateOrRecycleContext(0);
	initialIP = ((LiteralStart + ((((usqInt) (longAt((newMethod + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 10) & 255)) * BytesPerWord) + 1;
	/* begin storePointer:ofObject:withValue: */
	valuePointer = activeContext;
	if ((((usqInt) fauxContext)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(fauxContext, valuePointer);
	}
	longAtput((fauxContext + BaseHeaderSize) + (SenderIndex << ShiftForWord), valuePointer);
	/* begin storePointer:ofObject:withValue: */
	valuePointer1 = newMethod;
	if ((((usqInt) fauxContext)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(fauxContext, valuePointer1);
	}
	longAtput((fauxContext + BaseHeaderSize) + (MethodIndex << ShiftForWord), valuePointer1);
	/* begin storePointer:ofObject:withValue: */
	if ((((usqInt) fauxContext)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(fauxContext, ((0 << 1) | 1));
	}
	longAtput((fauxContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord), ((0 << 1) | 1));
	/* begin storePointer:ofObject:withValue: */
	valuePointer2 = nilObj;
	if ((((usqInt) fauxContext)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(fauxContext, valuePointer2);
	}
	longAtput((fauxContext + BaseHeaderSize) + (ClosureIndex << ShiftForWord), valuePointer2);
	/* begin storePointer:ofObject:withValue: */
	if ((((usqInt) fauxContext)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(fauxContext, ((initialIP << 1) | 1));
	}
	longAtput((fauxContext + BaseHeaderSize) + (InitialIPIndex << ShiftForWord), ((initialIP << 1) | 1));
	/* begin storePointer:ofObject:withValue: */
	valuePointer3 = longAt(stackPointer - (argumentCount * BytesPerWord));
	if ((((usqInt) fauxContext)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(fauxContext, valuePointer3);
	}
	longAtput((fauxContext + BaseHeaderSize) + (ReceiverIndex << ShiftForWord), valuePointer3);
	activeContext = fauxContext;
	/* begin fetchContextRegisters: */
	activeCntx = activeContext;
	tmp = longAt((activeCntx + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	if ((tmp & 1)) {
		tmp = longAt((activeCntx + BaseHeaderSize) + (HomeIndex << ShiftForWord));
		if ((((usqInt) tmp)) < (((usqInt) youngStart))) {
			beRootIfOld(tmp);
		}
	} else {
		tmp = activeCntx;
	}
	theHomeContext = tmp;
	receiver = longAt((tmp + BaseHeaderSize) + (ReceiverIndex << ShiftForWord));
	method = longAt((tmp + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	tmp = ((longAt((activeCntx + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord))) >> 1);
	instructionPointer = ((method + tmp) + BaseHeaderSize) - 2;
	tmp = ((longAt((activeCntx + BaseHeaderSize) + (StackPointerIndex << ShiftForWord))) >> 1);
	stackPointer = (activeCntx + BaseHeaderSize) + (((TempFrameStart + tmp) - 1) * BytesPerWord);
	activeProc = longAt(((longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord))) + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
	/* begin storePointer:ofObject:withValue: */
	valuePointer4 = activeContext;
	if ((((usqInt) activeProc)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(activeProc, valuePointer4);
	}
	longAtput((activeProc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord), valuePointer4);
	/* begin addFirstLink:toList: */
	/* begin callbackSemaphore */
	if (!((stSizeOf(specialObjectsOop)) > CallbackSemaphoreIndex)) {
		aList = null;
		goto l1;
	}
	callbackSema = longAt((specialObjectsOop + BaseHeaderSize) + (CallbackSemaphoreIndex << ShiftForWord));
	if (!((fetchClassOf(callbackSema)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassSemaphore << ShiftForWord))))) {
		aList = null;
		goto l1;
	}
	aList = callbackSema;
l1:	/* end callbackSemaphore */;
	if ((longAt((aList + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord))) == nilObj) {
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) aList)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(aList, activeProc);
		}
		longAtput((aList + BaseHeaderSize) + (LastLinkIndex << ShiftForWord), activeProc);
	} else {
		firstLink = longAt((aList + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord));
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) activeProc)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(activeProc, firstLink);
		}
		longAtput((activeProc + BaseHeaderSize) + (NextLinkIndex << ShiftForWord), firstLink);
	}
	/* begin storePointer:ofObject:withValue: */
	if ((((usqInt) aList)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(aList, activeProc);
	}
	longAtput((aList + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord), activeProc);
	/* begin storePointer:ofObject:withValue: */
	if ((((usqInt) activeProc)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(activeProc, aList);
	}
	longAtput((activeProc + BaseHeaderSize) + (MyListIndex << ShiftForWord), aList);
	return 1;
}


/*	Change the class of the receiver into the class specified by the argument given that the format of the receiver matches the format of the argument. Fail if receiver or argument are SmallIntegers, or the receiver is an instance of a compact class and the argument isn't, or when the argument's class is compact and the receiver isn't, or when the format of the receiver is different from the format of the argument's class, or when the arguments class is fixed and the receiver's size differs from the size that an instance of the argument's class should have. */
/*	Check what the format of the class says */

sqInt changeClassOfto(sqInt rcvr, sqInt argClass) {
    sqInt argFormat;
    sqInt sizeHiBits;
    sqInt rcvrFormat;
    sqInt classHdr;
    sqInt byteSize;
    sqInt ccIndex;
    sqInt i;


	/* Low 2 bits are 0 */
	/* Compute the size of instances of the class (used for fixed field classes only) */

	classHdr = (longAt((argClass + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1;
	sizeHiBits = ((usqInt) (classHdr & 393216)) >> 9;
	classHdr = classHdr & 131071;

	/* size in bytes -- low 2 bits are 0 */
	/* Check the receiver's format against that of the class */

	byteSize = (classHdr & SizeMask) + sizeHiBits;
	argFormat = (((usqInt) classHdr) >> 8) & 15;
	rcvrFormat = (((usqInt) (longAt(rcvr))) >> 8) & 15;
	if (!(argFormat == rcvrFormat)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (argFormat < 2) {
		if (!((byteSize - BaseHeaderSize) == (byteSizeOf(rcvr)))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	if (((longAt(rcvr)) & TypeMask) == HeaderTypeShort) {

		/* Compact classes. Check if the arg's class is compact and exchange ccIndex */

		ccIndex = classHdr & CompactClassMask;
		if (ccIndex == 0) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		longAtput(rcvr, ((longAt(rcvr)) & (~CompactClassMask)) | ccIndex);
	} else {
		longAtput(rcvr - BaseHeaderSize, argClass | ((longAt(rcvr)) & TypeMask));
		if ((((usqInt) rcvr)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(rcvr, argClass);
		}
	}
	/* begin flushMethodCache */
	for (i = 1; i <= MethodCacheSize; i += 1) {
		methodCache[i] = 0;
	}
	for (i = 1; i <= AtCacheTotalSize; i += 1) {
		atCache[i] = 0;
	}
}


/*	Arg must lie in range 0-255! */

sqInt characterForAscii(sqInt ascii) {
	return longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CharacterTable << ShiftForWord))) + BaseHeaderSize) + (ascii << ShiftForWord));
}

sqInt characterTable(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (CharacterTable << ShiftForWord));
}


/*	Check for possible interrupts and handle one if necessary. */

sqInt checkForInterrupts(void) {
    sqInt now;
    sqInt sema;
    sqInt i;
    sqInt xArray;
    sqInt xSize;
    sqInt index;
    sqInt sema1;

	now = (ioMSecs()) & MillisecondClockMask;
	if (!(interruptCheckCounter < -100)) {
		if ((now - lastTick) < interruptChecksEveryNms) {

			/* don't play with the feedback if we forced a check. It only makes life difficult */
			/* wrapping is not a concern, it'll get caught quickly  
				enough. This clause is trying to keep a reasonable  
				guess of how many times per 	interruptChecksEveryNms we are calling  
				quickCheckForInterrupts. Not sure how effective it really is. */

			interruptCheckCounterFeedBackReset += 10;
		} else {
			if (interruptCheckCounterFeedBackReset <= 1000) {
				interruptCheckCounterFeedBackReset = 1000;
			} else {
				interruptCheckCounterFeedBackReset -= 12;
			}
		}
	}
	interruptCheckCounter = interruptCheckCounterFeedBackReset;
	if (signalLowSpace) {

		/* reset flag */

		signalLowSpace = 0;
		sema = longAt((specialObjectsOop + BaseHeaderSize) + (TheLowSpaceSemaphore << ShiftForWord));
		if (!(sema == nilObj)) {
			synchronousSignal(sema);
		}
	}
	if (now < lastTick) {

		/* millisecond clock wrapped so correct the nextPollTick */

		nextPollTick = (nextPollTick - MillisecondClockMask) - 1;
	}
	if (now >= nextPollTick) {
		ioProcessEvents();

		/* msecs to wait before next call to ioProcessEvents.  
			Note that strictly speaking we might need to update  
			'now' at this point since ioProcessEvents could take a  
			very long time on some platforms */

		nextPollTick = now + 200;
	}
	if (interruptPending) {

		/* reset interrupt flag */

		interruptPending = 0;
		sema = longAt((specialObjectsOop + BaseHeaderSize) + (TheInterruptSemaphore << ShiftForWord));
		if (!(sema == nilObj)) {
			synchronousSignal(sema);
		}
	}
	if (nextWakeupTick != 0) {
		if (now < lastTick) {

			/* the clock has wrapped. Subtract the wrap  
					interval from nextWakeupTick - this might just  
					possibly result in 0. Since this is used as a flag  
					value for 'no timer' we do the 0 check above */

			nextWakeupTick = (nextWakeupTick - MillisecondClockMask) - 1;
		}
		if (now >= nextWakeupTick) {

			/* set timer interrupt to 0 for 'no timer' */

			nextWakeupTick = 0;
			sema = longAt((specialObjectsOop + BaseHeaderSize) + (TheTimerSemaphore << ShiftForWord));
			if (!(sema == nilObj)) {
				synchronousSignal(sema);
			}
		}
	}
	if (pendingFinalizationSignals > 0) {
		sema = longAt((specialObjectsOop + BaseHeaderSize) + (TheFinalizationSemaphore << ShiftForWord));
		if ((fetchClassOf(sema)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassSemaphore << ShiftForWord)))) {
			synchronousSignal(sema);
		}
		pendingFinalizationSignals = 0;
	}
	if ((semaphoresToSignalCountA > 0) || (semaphoresToSignalCountB > 0)) {
		/* begin signalExternalSemaphores */
		semaphoresUseBufferA = !semaphoresUseBufferA;
		xArray = longAt((specialObjectsOop + BaseHeaderSize) + (ExternalObjectsArray << ShiftForWord));
		xSize = stSizeOf(xArray);
		if (semaphoresUseBufferA) {
			for (i = 1; i <= semaphoresToSignalCountB; i += 1) {
				index = semaphoresToSignalB[i];
				if (index <= xSize) {
					sema1 = longAt((xArray + BaseHeaderSize) + ((index - 1) << ShiftForWord));
					if ((fetchClassOf(sema1)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassSemaphore << ShiftForWord)))) {
						synchronousSignal(sema1);
					}
				}
			}
			semaphoresToSignalCountB = 0;
		} else {
			for (i = 1; i <= semaphoresToSignalCountA; i += 1) {
				index = semaphoresToSignalA[i];
				if (index <= xSize) {
					sema1 = longAt((xArray + BaseHeaderSize) + ((index - 1) << ShiftForWord));
					if ((fetchClassOf(sema1)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassSemaphore << ShiftForWord)))) {
						synchronousSignal(sema1);
					}
				}
			}
			semaphoresToSignalCountA = 0;
		}
	}
	lastTick = now;
}


/*	Read and verify the image file version number and return true if the the given image file needs to be byte-swapped. As a side effect, position the file stream just after the version number of the image header. This code prints a warning and does a hard-exit if it cannot find a valid version number. */
/*	This code is based on C code by Ian Piumarta. */

sqInt checkImageVersionFromstartingAt(sqImageFile  f, squeakFileOffsetType  imageOffset) {
    sqInt version;
    sqInt firstVersion;

	sqImageFileSeek(f, imageOffset);
	version = firstVersion = getLongFromFileswap(f, 0);
	if ((version == imageFormatVersionNumber) || (version == (imageFormatForwardCompatibilityVersion()))) {
		return 0;
	}
	sqImageFileSeek(f, imageOffset);
	version = getLongFromFileswap(f, 1);
	if ((version == imageFormatVersionNumber) || (version == (imageFormatForwardCompatibilityVersion()))) {
		return 1;
	}
	if (imageOffset == 0) {
		sqImageFileSeek(f, 512);
		version = getLongFromFileswap(f, 0);
		if ((version == imageFormatVersionNumber) || (version == (imageFormatForwardCompatibilityVersion()))) {
			return 0;
		}
		sqImageFileSeek(f, 512);
		version = getLongFromFileswap(f, 1);
		if ((version == imageFormatVersionNumber) || (version == (imageFormatForwardCompatibilityVersion()))) {
			return 1;
		}
	}
	print("This interpreter (vers. ");
	printNum(imageFormatVersionNumber);
	print(") cannot read image file (vers. ");
	printNum(firstVersion);
	print(").");
	/* begin cr */
	printf("\n");
	print("Press CR to quit...");
	getchar();
	ioExit();
}


/*	Note: May be called by translated primitive code. */

sqInt checkedIntegerValueOf(sqInt intOop) {
	if ((intOop & 1)) {
		return (intOop >> 1);
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		return 0;
	}
}


/*	Assumes zero-based array indexing. For testing in Smalltalk, this method should be overridden in a subclass. */

sqInt checkedLongAt(sqInt byteAddress) {
	/* begin checkAddress: */
	if ((((usqInt) byteAddress)) < (((usqInt) memory))) {
		error("bad address: negative");
	}
	if ((((usqInt) byteAddress)) >= (((usqInt) memoryLimit))) {
		error("bad address: past end of heap");
	}
	/* begin checkAddress: */
	if ((((usqInt) (byteAddress + 3))) < (((usqInt) memory))) {
		error("bad address: negative");
	}
	if ((((usqInt) (byteAddress + 3))) >= (((usqInt) memoryLimit))) {
		error("bad address: past end of heap");
	}
	return longAt(byteAddress);
}

sqInt classArray(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (ClassArray << ShiftForWord));
}

sqInt classBitmap(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (ClassBitmap << ShiftForWord));
}

sqInt classByteArray(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (ClassByteArray << ShiftForWord));
}

sqInt classCharacter(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (ClassCharacter << ShiftForWord));
}

sqInt classExternalAddress(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (ClassExternalAddress << ShiftForWord));
}

sqInt classExternalData(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (ClassExternalData << ShiftForWord));
}

sqInt classExternalFunction(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (ClassExternalFunction << ShiftForWord));
}

sqInt classExternalLibrary(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (ClassExternalLibrary << ShiftForWord));
}

sqInt classExternalStructure(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (ClassExternalStructure << ShiftForWord));
}

sqInt classFloat(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord));
}

sqInt classLargeNegativeInteger(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (ClassLargeNegativeInteger << ShiftForWord));
}

sqInt classLargePositiveInteger(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (ClassLargePositiveInteger << ShiftForWord));
}


/*	Check if aClass's name is className */

sqInt classNameOfIs(sqInt aClass, char * className) {
    sqInt length;
    sqInt name;
    sqInt i;
    char * srcName;

	if ((lengthOf(aClass)) <= 6) {
		return 0;
	}
	name = longAt((aClass + BaseHeaderSize) + (6 << ShiftForWord));
	if (!(((name & 1) == 0) && (((((usqInt) (longAt(name))) >> 8) & 15) >= 8))) {
		return 0;
	}
	length = stSizeOf(name);
	srcName = ((char *) (arrayValueOf(name)));
	for (i = 0; i <= (length - 1); i += 1) {
		if (!((srcName[i]) == (className[i]))) {
			return 0;
		}
	}
	return (className[length]) == 0;
}

sqInt classPoint(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (ClassPoint << ShiftForWord));
}

sqInt classSemaphore(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (ClassSemaphore << ShiftForWord));
}

sqInt classSmallInteger(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
}

sqInt classString(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (ClassString << ShiftForWord));
}


/*	Return a shallow copy of the given object. May cause GC */
/*	Assume: Oop is a real object, not a small integer. */

sqInt clone(sqInt oop) {
    sqInt newOop;
    sqInt hash;
    usqInt fromIndex;
    sqInt header;
    sqInt remappedOop;
    sqInt extraHdrBytes;
    usqInt bytes;
    sqInt newChunk;
    usqInt lastFrom;
    sqInt toIndex;
    sqInt header1;
    sqInt oop1;
    sqInt newFreeSize;
    sqInt enoughSpace;
    sqInt newChunk1;
    usqInt minFree;
    sqInt sched;
    sqInt lastSavedProcess;
    sqInt currentProc;
    sqInt oop2;

	extraHdrBytes = headerTypeBytes[(longAt(oop)) & TypeMask];
	/* begin sizeBitsOf: */
	header1 = longAt(oop);
	if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
		bytes = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
		goto l1;
	} else {
		bytes = header1 & SizeMask;
		goto l1;
	}
l1:	/* end sizeBitsOf: */;

	/* allocate space for the copy, remapping oop in case of a GC */

	bytes += extraHdrBytes;
	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = oop;
	if (!(sufficientSpaceToAllocate(2500 + bytes))) {
		return 0;
	}
	/* begin allocateChunk: */
	if (allocationCount >= allocationsBetweenGCs) {
		incrementalGC();
	}
	/* begin sufficientSpaceToAllocate: */
	minFree = (lowSpaceThreshold + bytes) + BaseHeaderSize;
	if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) >= (((usqInt) minFree))) {
		enoughSpace = 1;
		goto l2;
	} else {
		enoughSpace = sufficientSpaceAfterGC(minFree);
		goto l2;
	}
l2:	/* end sufficientSpaceToAllocate: */;
	if (!(enoughSpace)) {
		signalLowSpace = 1;
		lowSpaceThreshold = 0;
		/* begin saveProcessSignalingLowSpace */
		lastSavedProcess = longAt((specialObjectsOop + BaseHeaderSize) + (ProcessSignalingLowSpace << ShiftForWord));
		if (lastSavedProcess == nilObj) {
			sched = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord));
			currentProc = longAt((sched + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
			/* begin storePointer:ofObject:withValue: */
			oop2 = specialObjectsOop;
			if ((((usqInt) oop2)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(oop2, currentProc);
			}
			longAtput((oop2 + BaseHeaderSize) + (ProcessSignalingLowSpace << ShiftForWord), currentProc);
		}
		/* begin forceInterruptCheck */
		interruptCheckCounter = -1000;
		nextPollTick = 0;
	}
	if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) < (((usqInt) (bytes + BaseHeaderSize)))) {
		error("out of memory");
	}
	newFreeSize = ((longAt(freeBlock)) & AllButTypeMask) - bytes;
	newChunk1 = freeBlock;
	freeBlock += bytes;
	/* begin setSizeOfFree:to: */
	longAtput(freeBlock, (newFreeSize & AllButTypeMask) | HeaderTypeFree);
	allocationCount += 1;
	newChunk = newChunk1;
	/* begin popRemappableOop */
	oop1 = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	remappedOop = oop1;

	/* loop below uses pre-increment */

	toIndex = newChunk - BytesPerWord;
	fromIndex = (remappedOop - extraHdrBytes) - BytesPerWord;
	lastFrom = fromIndex + bytes;
	while (fromIndex < lastFrom) {
		longAtput(toIndex += BytesPerWord, longAt(fromIndex += BytesPerWord));
	}

	/* convert from chunk to oop */
	/* fix base header: compute new hash and clear Mark and Root bits */

	newOop = newChunk + extraHdrBytes;
	/* begin newObjectHash */
	lastHash = (13849 + (27181 * lastHash)) & 65535;
	hash = lastHash;

	/* use old ccIndex, format, size, and header-type fields */

	header = (longAt(newOop)) & 131071;
	header = header | ((hash << 17) & 536739840);
	longAtput(newOop, header);
	return newOop;
}


/*	This code is called if the receiver responds primitively to at:.
	If this is so, it will be installed in the atCache so that subsequent calls of at:
	or next may be handled immediately in bytecode primitive routines. */

sqInt commonAt(sqInt stringy) {
    sqInt result;
    sqInt atIx;
    sqInt rcvr;
    sqInt index;
    sqInt sp;
    sqInt sp1;


	/* Sets successFlag */

	index = positive32BitValueOf(longAt(stackPointer));
	rcvr = longAt(stackPointer - (1 * BytesPerWord));
	if (!(successFlag && (!((rcvr & 1))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((messageSelector == (longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((16 * 2) << ShiftForWord)))) && (lkupClass == (fetchClassOfNonInt(rcvr)))) {

		/* OK -- look in the at-cache */
		/* Index into atCache = 4N, for N = 0 ... 7 */

		atIx = rcvr & AtCacheMask;
		if (!((atCache[atIx + AtCacheOop]) == rcvr)) {
			installinAtCacheatstring(rcvr, atCache, atIx, stringy);
		}
		if (successFlag) {
			result = commonVariableatcacheIndex(rcvr, index, atIx);
		}
		if (successFlag) {
			/* begin pop:thenPush: */
			longAtput(sp = stackPointer - (((argumentCount + 1) - 1) * BytesPerWord), result);
			stackPointer = sp;
			return null;
		}
	}
	successFlag = 1;
	result = stObjectat(rcvr, index);
	if (successFlag) {
		if (stringy) {
			result = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CharacterTable << ShiftForWord))) + BaseHeaderSize) + (((result >> 1)) << ShiftForWord));
		}
		/* begin pop:thenPush: */
		longAtput(sp1 = stackPointer - (((argumentCount + 1) - 1) * BytesPerWord), result);
		stackPointer = sp1;
		return null;
	}
}


/*	This code is called if the receiver responds primitively to at:Put:.
	If this is so, it will be installed in the atPutCache so that subsequent calls of at:
	or  next may be handled immediately in bytecode primitive routines. */

sqInt commonAtPut(sqInt stringy) {
    sqInt value;
    sqInt atIx;
    sqInt rcvr;
    sqInt index;
    sqInt valToPut;
    sqInt fmt;
    sqInt fixedFields;
    sqInt stSize;
    sqInt sp;
    sqInt sp1;

	value = longAt(stackPointer);

	/* Sets successFlag */

	index = positive32BitValueOf(longAt(stackPointer - (1 * BytesPerWord)));
	rcvr = longAt(stackPointer - (2 * BytesPerWord));
	if (!(successFlag && (!((rcvr & 1))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((messageSelector == (longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((17 * 2) << ShiftForWord)))) && (lkupClass == (fetchClassOfNonInt(rcvr)))) {

		/* OK -- look in the at-cache */
		/* Index into atPutCache */

		atIx = (rcvr & AtCacheMask) + AtPutBase;
		if (!((atCache[atIx + AtCacheOop]) == rcvr)) {
			installinAtCacheatstring(rcvr, atCache, atIx, stringy);
		}
		if (successFlag) {
			/* begin commonVariable:at:put:cacheIndex: */
			stSize = atCache[atIx + AtCacheSize];
			if (((((usqInt) index)) >= (((usqInt) 1))) && ((((usqInt) index)) <= (((usqInt) stSize)))) {
				fmt = atCache[atIx + AtCacheFmt];
				if (fmt <= 4) {
					fixedFields = atCache[atIx + AtCacheFixedFields];
					/* begin storePointer:ofObject:withValue: */
					if ((((usqInt) rcvr)) < (((usqInt) youngStart))) {
						possibleRootStoreIntovalue(rcvr, value);
					}
					longAtput((rcvr + BaseHeaderSize) + (((index + fixedFields) - 1) << ShiftForWord), value);
					goto l1;
				}
				if (fmt < 8) {
					valToPut = positive32BitValueOf(value);
					if (successFlag) {
						long32Atput((rcvr + BaseHeaderSize) + ((index - 1) << 2), valToPut);
					}
					goto l1;
				}
				if (fmt >= 16) {
					valToPut = asciiOfCharacter(value);
					if (!(successFlag)) {
						goto l1;
					}
				} else {
					valToPut = value;
				}
				if ((valToPut & 1)) {
					valToPut = (valToPut >> 1);
					if (!((valToPut >= 0) && (valToPut <= 255))) {
						/* begin primitiveFail */
						successFlag = 0;
						goto l1;
					}
					byteAtput((rcvr + BaseHeaderSize) + (index - 1), valToPut);
					goto l1;
				}
			}
			/* begin primitiveFail */
			successFlag = 0;
		l1:	/* end commonVariable:at:put:cacheIndex: */;
		}
		if (successFlag) {
			/* begin pop:thenPush: */
			longAtput(sp = stackPointer - (((argumentCount + 1) - 1) * BytesPerWord), value);
			stackPointer = sp;
			return null;
		}
	}
	successFlag = 1;
	if (stringy) {
		stObjectatput(rcvr, index, asciiOfCharacter(value));
	} else {
		stObjectatput(rcvr, index, value);
	}
	if (successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp1 = stackPointer - (((argumentCount + 1) - 1) * BytesPerWord), value);
		stackPointer = sp1;
		return null;
	}
}


/*	This code assumes the receiver has been identified at location atIx in the atCache. */

sqInt commonVariableatcacheIndex(sqInt rcvr, sqInt index, sqInt atIx) {
    sqInt result;
    sqInt fmt;
    sqInt fixedFields;
    sqInt stSize;

	stSize = atCache[atIx + AtCacheSize];
	if (((((usqInt) index)) >= (((usqInt) 1))) && ((((usqInt) index)) <= (((usqInt) stSize)))) {
		fmt = atCache[atIx + AtCacheFmt];
		if (fmt <= 4) {
			fixedFields = atCache[atIx + AtCacheFixedFields];
			return longAt((rcvr + BaseHeaderSize) + (((index + fixedFields) - 1) << ShiftForWord));
		}
		if (fmt < 8) {

			/* Bitmap */

			result = long32At((rcvr + BaseHeaderSize) + ((index - 1) << 2));
			result = positive32BitIntegerFor(result);
			return result;
		}
		if (fmt >= 16) {
			return longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CharacterTable << ShiftForWord))) + BaseHeaderSize) + ((byteAt((rcvr + BaseHeaderSize) + (index - 1))) << ShiftForWord));
		} else {
			return (((byteAt((rcvr + BaseHeaderSize) + (index - 1))) << 1) | 1);
		}
	}
	/* begin primitiveFail */
	successFlag = 0;
}


/*	May set success to false */
/*	First compare two ST integers... */

sqInt compare31or32Bitsequal(sqInt obj1, sqInt obj2) {
	if (((obj1 & 1)) && ((obj2 & 1))) {
		return obj1 == obj2;
	}
	return (positive32BitValueOf(obj1)) == (positive32BitValueOf(obj2));
}

sqInt compilerCreateActualMessagestoringArgs(sqInt aMessage, sqInt argArray) {
	return compilerHooks[14](aMessage, argArray);
}

sqInt compilerFlushCache(sqInt aCompiledMethod) {
	return compilerHooks[2](aCompiledMethod);
}

sqInt compilerMapFromto(sqInt memStart, sqInt memEnd) {
	return compilerHooks[4](memStart, memEnd);
}

sqInt compilerMark(void) {
	return compilerHooks[9]();
}

sqInt compilerPostGC(void) {
	return compilerHooks[5]();
}

sqInt compilerPostSnapshot(void) {
	return compilerHooks[8]();
}

sqInt compilerPreGC(sqInt fullGCFlag) {
	return compilerHooks[3](fullGCFlag);
}

sqInt compilerPreSnapshot(void) {
	return compilerHooks[7]();
}

sqInt compilerProcessChange(void) {
	return compilerHooks[6]();
}

sqInt compilerProcessChangeto(sqInt oldProc, sqInt newProc) {
	return compilerHooks[6](oldProc, newProc);
}

sqInt compilerTranslateMethod(void) {
	return compilerHooks[1]();
}


/*	Return true if neither array contains a small integer. You 
	can't become: integers! */

sqInt containOnlyOopsand(sqInt array1, sqInt array2) {
    sqInt fieldOffset;
    sqInt sz;
    sqInt header;
    sqInt contextSize;
    sqInt fmt;
    sqInt methodHeader;
    sqInt sp;
    sqInt header1;
    sqInt type;

	/* begin lastPointerOf: */
	header = longAt(array1);
	fmt = (((usqInt) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && ((((((usqInt) header) >> 12) & 31) == 13) || ((((((usqInt) header) >> 12) & 31) == 14) || (((((usqInt) header) >> 12) & 31) == 4)))) {
			/* begin fetchStackPointerOf: */
			sp = longAt((array1 + BaseHeaderSize) + (StackPointerIndex << ShiftForWord));
			if (!((sp & 1))) {
				contextSize = 0;
				goto l2;
			}
			contextSize = (sp >> 1);
		l2:	/* end fetchStackPointerOf: */;
			fieldOffset = (CtxtTempFrameStart + contextSize) * BytesPerWord;
			goto l1;
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(array1);
		/* begin rightType: */
		if ((header1 & SizeMask) == 0) {
			type = HeaderTypeSizeAndClass;
			goto l3;
		} else {
			if ((header1 & CompactClassMask) == 0) {
				type = HeaderTypeClass;
				goto l3;
			} else {
				type = HeaderTypeShort;
				goto l3;
			}
		}
	l3:	/* end rightType: */;
		if (type == HeaderTypeSizeAndClass) {
			sz = (longAt(array1 - (BytesPerWord * 2))) & AllButTypeMask;
			goto l4;
		} else {
			sz = header1 & SizeMask;
			goto l4;
		}
	l4:	/* end sizeBitsOfSafe: */;
		fieldOffset = sz - BaseHeaderSize;
		goto l1;
	}
	if (fmt < 12) {
		fieldOffset = 0;
		goto l1;
	}
	methodHeader = longAt(array1 + BaseHeaderSize);
	fieldOffset = (((((usqInt) methodHeader) >> 10) & 255) * BytesPerWord) + BaseHeaderSize;
l1:	/* end lastPointerOf: */;
	while (fieldOffset >= BaseHeaderSize) {
		if (((longAt(array1 + fieldOffset)) & 1)) {
			return 0;
		}
		if (((longAt(array2 + fieldOffset)) & 1)) {
			return 0;
		}
		fieldOffset -= BytesPerWord;
	}
	return 1;
}


/*	Does thisCntx have aContext in its sender chain? */

sqInt contexthasSender(sqInt thisCntx, sqInt aContext) {
    sqInt nilOop;
    sqInt s;

	if (thisCntx == aContext) {
		return 0;
	}
	nilOop = nilObj;
	s = longAt((thisCntx + BaseHeaderSize) + (SenderIndex << ShiftForWord));
	while (!(s == nilOop)) {
		if (s == aContext) {
			return 1;
		}
		s = longAt((s + BaseHeaderSize) + (SenderIndex << ShiftForWord));
	}
	return 0;
}


/*	This entry point needs to be implemented for the interpreter proxy.
	Since BitBlt is now a plugin we need to look up BitBltPlugin:=copyBits
	and call it. This entire mechanism should eventually go away and be
	replaced with a dynamic lookup from BitBltPlugin itself but for backward
	compatibility this stub is provided */

sqInt copyBits(void) {
    void * fn;

	fn = ioLoadFunctionFrom("copyBits", "BitBltPlugin");
	if (fn == 0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	return ((sqInt (*)(void))fn)();
}


/*	This entry point needs to be implemented for the interpreter proxy.
	Since BitBlt is now a plugin we need to look up BitBltPlugin:=copyBitsFrom:to:at:
	and call it. This entire mechanism should eventually go away and be
	replaced with a dynamic lookup from BitBltPlugin itself but for backward
	compatibility this stub is provided */

sqInt copyBitsFromtoat(sqInt x0, sqInt x1, sqInt y) {
    void * fn;

	fn = ioLoadFunctionFrom("copyBitsFromtoat", "BitBltPlugin");
	if (fn == 0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	return ((sqInt (*)(sqInt, sqInt, sqInt))fn)(x0, x1, y);
}


/*	Copy this object into the segment beginning at lastSeg.
	Install a forwarding pointer, and save oop and header.
	Fail if out of space.  Return the next segmentAddr if successful. */
/*	Copy the object... */

sqInt copyObjtoSegmentaddrstopAtsaveOopAtheaderAt(sqInt oop, sqInt segmentWordArray, sqInt lastSeg, sqInt stopAddr, sqInt oopPtr, sqInt hdrPtr) {
    sqInt bodySize;
    sqInt extraSize;
    sqInt hdrAddr;
    sqInt header;
    sqInt in;
    sqInt lastIn;
    sqInt out;

	flag("Dan");
	if (!(successFlag)) {
		return lastSeg;
	}
	extraSize = headerTypeBytes[(longAt(oop)) & TypeMask];
	/* begin sizeBitsOf: */
	header = longAt(oop);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		bodySize = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
		goto l1;
	} else {
		bodySize = header & SizeMask;
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	if ((((usqInt) ((lastSeg + extraSize) + bodySize))) >= (((usqInt) stopAddr))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin transfer:from:to: */
	flag("Dan");
	in = (oop - extraSize) - BytesPerWord;
	lastIn = in + ((((sqInt) (extraSize + bodySize) >> 2)) * BytesPerWord);
	out = (lastSeg + BytesPerWord) - BytesPerWord;
	while ((((usqInt) in)) < (((usqInt) lastIn))) {
		longAtput(out += BytesPerWord, longAt(in += BytesPerWord));
	}
	hdrAddr = (lastSeg + BytesPerWord) + extraSize;
	longAtput(hdrAddr, (longAt(hdrAddr)) & (AllButRootBit - MarkBit));
	/* begin forward:to:savingOopAt:andHeaderAt: */
	longAtput(oopPtr, oop);
	longAtput(hdrPtr, longAt(oop));
	longAtput(oop, (((lastSeg + BytesPerWord) + extraSize) - segmentWordArray) + HeaderTypeFree);
	return (lastSeg + extraSize) + bodySize;
}


/*	Bundle up the selector, arguments and lookupClass into a Message object. 
	In the process it pops the arguments off the stack, and pushes the message object. 
	This can then be presented as the argument of e.g. #doesNotUnderstand:. 
	ikp 11/20/1999 03:59 -- added hook for external runtime compilers. */
/*	remap lookupClass in case GC happens during allocation */

sqInt createActualMessageTo(sqInt aClass) {
    sqInt message;
    sqInt argumentArray;
    sqInt lookupClass;
    sqInt count;
    sqInt src;
    sqInt in;
    sqInt lastIn;
    sqInt out;
    sqInt sp;
    sqInt oop;
    sqInt oop1;
    sqInt valuePointer;

	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = aClass;

	/* remap argumentArray in case GC happens during allocation */

	argumentArray = instantiateClassindexableSize(longAt((specialObjectsOop + BaseHeaderSize) + (ClassArray << ShiftForWord)), argumentCount);
	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = argumentArray;
	message = instantiateClassindexableSize(longAt((specialObjectsOop + BaseHeaderSize) + (ClassMessage << ShiftForWord)), 0);
	/* begin popRemappableOop */
	oop = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	argumentArray = oop;
	/* begin popRemappableOop */
	oop1 = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	lookupClass = oop1;
	beRootIfOld(argumentArray);
	if (compilerInitialized) {
		compilerCreateActualMessagestoringArgs(message, argumentArray);
	} else {
		/* begin transfer:from:to: */
		count = argumentCount;
		src = stackPointer - ((argumentCount - 1) * BytesPerWord);
		flag("Dan");
		in = src - BytesPerWord;
		lastIn = in + (count * BytesPerWord);
		out = (argumentArray + BaseHeaderSize) - BytesPerWord;
		while ((((usqInt) in)) < (((usqInt) lastIn))) {
			longAtput(out += BytesPerWord, longAt(in += BytesPerWord));
		}
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((argumentCount - 1) * BytesPerWord), message);
		stackPointer = sp;
	}
	argumentCount = 1;
	/* begin storePointer:ofObject:withValue: */
	valuePointer = messageSelector;
	if ((((usqInt) message)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(message, valuePointer);
	}
	longAtput((message + BaseHeaderSize) + (MessageSelectorIndex << ShiftForWord), valuePointer);
	/* begin storePointer:ofObject:withValue: */
	if ((((usqInt) message)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(message, argumentArray);
	}
	longAtput((message + BaseHeaderSize) + (MessageArgumentsIndex << ShiftForWord), argumentArray);
	if ((lastPointerOf(message)) >= ((MessageLookupClassIndex * BytesPerWord) + BaseHeaderSize)) {
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) message)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(message, lookupClass);
		}
		longAtput((message + BaseHeaderSize) + (MessageLookupClassIndex << ShiftForWord), lookupClass);
	}
}

sqInt dispatchFunctionPointer(void * aFunctionPointer) {
	((void (*)(void))aFunctionPointer)();
}


/*	Call the primitive at index primIdx in the primitiveTable. */

sqInt dispatchFunctionPointerOnin(sqInt primIdx, void *primTable[]) {
	return dispatchFunctionPointer(primTable[primIdx]);
}


/*	Repaint the portion of the Smalltalk screen bounded by the affected rectangle. Used to synchronize the screen after a Bitblt to the Smalltalk Display object. */

sqInt displayBitsOfLeftTopRightBottom(sqInt aForm, sqInt l, sqInt t, sqInt r, sqInt b) {
    sqInt displayObj;
    sqInt d;
    sqInt right;
    sqInt dispBits;
    sqInt bottom;
    sqInt h;
    sqInt top;
    sqInt left;
    sqInt surfaceHandle;
    sqInt w;
    sqInt dispBitsIndex;
    sqInt successValue;

	displayObj = longAt((specialObjectsOop + BaseHeaderSize) + (TheDisplay << ShiftForWord));
	if (!(aForm == displayObj)) {
		return null;
	}
	/* begin success: */
	successValue = (((displayObj & 1) == 0) && (((((usqInt) (longAt(displayObj))) >> 8) & 15) <= 4)) && ((lengthOf(displayObj)) >= 4);
	successFlag = successValue && successFlag;
	if (successFlag) {
		dispBits = longAt((displayObj + BaseHeaderSize) + (0 << ShiftForWord));
		w = fetchIntegerofObject(1, displayObj);
		h = fetchIntegerofObject(2, displayObj);
		d = fetchIntegerofObject(3, displayObj);
	}
	if (l < 0) {
		left = 0;
	} else {
		left = l;
	}
	if (r > w) {
		right = w;
	} else {
		right = r;
	}
	if (t < 0) {
		top = 0;
	} else {
		top = t;
	}
	if (b > h) {
		bottom = h;
	} else {
		bottom = b;
	}
	if (!((left <= right) && (top <= bottom))) {
		return null;
	}
	if (successFlag) {
		if ((dispBits & 1)) {
			surfaceHandle = (dispBits >> 1);
			if (showSurfaceFn == 0) {
				showSurfaceFn = ioLoadFunctionFrom("ioShowSurface", "SurfacePlugin");
				if (showSurfaceFn == 0) {
					/* begin success: */
					successFlag = 0 && successFlag;
					return null;
				}
			}
			((sqInt (*)(sqInt, sqInt, sqInt, sqInt, sqInt))showSurfaceFn)(surfaceHandle, left, top, right-left, bottom-top);
		} else {

			/* index in memory byte array */

			dispBitsIndex = dispBits + BaseHeaderSize;
			ioShowDisplay(dispBitsIndex, w, h, d, left, right, top, bottom);
		}
	}
}

sqInt displayObject(void) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (TheDisplay << ShiftForWord));
}


/*	Rounds negative results towards negative infinity, rather than zero. */

sqInt doPrimitiveDivby(sqInt rcvr, sqInt arg) {
    sqInt integerArg;
    sqInt result;
    sqInt integerRcvr;
    sqInt posRcvr;
    sqInt posArg;
    sqInt successValue;

	if (((rcvr & arg) & 1) != 0) {
		integerRcvr = (rcvr >> 1);
		integerArg = (arg >> 1);
		/* begin success: */
		successFlag = (integerArg != 0) && successFlag;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	if (!(successFlag)) {
		return 1;
	}
	if (integerRcvr > 0) {
		if (integerArg > 0) {
			result = integerRcvr / integerArg;
		} else {

			/* round negative result toward negative infinity */

			posArg = 0 - integerArg;
			result = 0 - ((integerRcvr + (posArg - 1)) / posArg);
		}
	} else {
		posRcvr = 0 - integerRcvr;
		if (integerArg > 0) {

			/* round negative result toward negative infinity */

			result = 0 - ((posRcvr + (integerArg - 1)) / integerArg);
		} else {
			posArg = 0 - integerArg;
			result = posRcvr / posArg;
		}
	}
	/* begin success: */
	successValue = 
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) result)) ^ ((((int) result)) << 1)) >= 0)
# else
		((result >= -1073741824) && (result <= 1073741823))
# endif  // SQ_HOST32
	;
	successFlag = successValue && successFlag;
	return result;
}

sqInt doPrimitiveModby(sqInt rcvr, sqInt arg) {
    sqInt integerArg;
    sqInt integerResult;
    sqInt integerRcvr;
    sqInt successValue;

	if (((rcvr & arg) & 1) != 0) {
		integerRcvr = (rcvr >> 1);
		integerArg = (arg >> 1);
		/* begin success: */
		successFlag = (integerArg != 0) && successFlag;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	if (!(successFlag)) {
		return 1;
	}

	/* ensure that the result has the same sign as the integerArg */

	integerResult = integerRcvr % integerArg;
	if (integerArg < 0) {
		if (integerResult > 0) {
			integerResult += integerArg;
		}
	} else {
		if (integerResult < 0) {
			integerResult += integerArg;
		}
	}
	/* begin success: */
	successValue = 
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) integerResult)) ^ ((((int) integerResult)) << 1)) >= 0)
# else
		((integerResult >= -1073741824) && (integerResult <= 1073741823))
# endif  // SQ_HOST32
	;
	successFlag = successValue && successFlag;
	return integerResult;
}

sqInt dummyReferToProxy(void) {
	interpreterProxy = interpreterProxy;
}


/*	Dump the entire image out to the given file. Intended for debugging only. */

EXPORT(sqInt) dumpImage(sqInt fileName) {
    sqInt result;
    sqInt dataSize;
    sqImageFile f;

	f = sqImageFileOpen(fileName, "wb");
	if (f == null) {
		return -1;
	}
	dataSize = endOfMemory - memory;
	result = sqImageFileWrite(pointerForOop(memory), sizeof(unsigned char), dataSize, f);
	sqImageFileClose(f);
	return result;
}


/*	execute a method found in the mCache - which means that 
	primitiveIndex & primitiveFunctionPointer are already set. Any sender 
	needs to have previously sent findMethodInClass: or equivalent */

sqInt executeNewMethodFromCache(void) {
    sqInt delta;
    sqInt nArgs;

	if (primitiveIndex > 0) {
		if (DoBalanceChecks) {

			/* check stack balance */

			nArgs = argumentCount;
			delta = stackPointer - activeContext;
		}
		successFlag = 1;
		dispatchFunctionPointer(primitiveFunctionPointer);
		if (DoBalanceChecks) {
			if (!(balancedStackafterPrimitivewithArgs(delta, primitiveIndex, nArgs))) {
				printUnbalancedStack(primitiveIndex);
			}
		}
		if (successFlag) {
			return null;
		}
	}
	activateNewMethod();
	/* begin quickCheckForInterrupts */
	if ((interruptCheckCounter -= 1) <= 0) {
		checkForInterrupts();
	}
}

sqInt failed(void) {
	return !successFlag;
}

sqInt falseObject(void) {
	return falseObj;
}


/*	Fetch the instance variable at the given index of the given object. Return the address of first indexable field of resulting array object, or fail if the instance variable does not contain an indexable bytes or words object. */
/*	Note: May be called by translated primitive code. */

void * fetchArrayofObject(sqInt fieldIndex, sqInt objectPointer) {
    sqInt arrayOop;

	arrayOop = longAt((objectPointer + BaseHeaderSize) + (fieldIndex << ShiftForWord));
	/* begin arrayValueOf: */
	if ((!((arrayOop & 1))) && (((arrayOop & 1) == 0) && (isWordsOrBytesNonInt(arrayOop)))) {
		return pointerForOop(arrayOop + BaseHeaderSize);
	}
	/* begin primitiveFail */
	successFlag = 0;
	return null;
}

sqInt fetchClassOf(sqInt oop) {
    sqInt ccIndex;

	if ((oop & 1)) {
		return longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		return (longAt(oop - BaseHeaderSize)) & AllButTypeMask;
	} else {
		return longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
	}
}

sqInt fetchClassOfNonInt(sqInt oop) {
    sqInt ccIndex;

	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		return (longAt(oop - BaseHeaderSize)) & AllButTypeMask;
	} else {
		return longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
	}
}


/*	Fetch the instance variable at the given index of the given object. Return the C double precision floating point value of that instance variable, or fail if it is not a Float. */
/*	Note: May be called by translated primitive code. */

double fetchFloatofObject(sqInt fieldIndex, sqInt objectPointer) {
    sqInt floatOop;

	floatOop = longAt((objectPointer + BaseHeaderSize) + (fieldIndex << ShiftForWord));
	return floatValueOf(floatOop);
}


/*	Note: May be called by translated primitive code. */

sqInt fetchIntegerofObject(sqInt fieldIndex, sqInt objectPointer) {
    sqInt intOop;

	intOop = longAt((objectPointer + BaseHeaderSize) + (fieldIndex << ShiftForWord));
	/* begin checkedIntegerValueOf: */
	if ((intOop & 1)) {
		return (intOop >> 1);
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		return 0;
	}
	return null;
}


/*	 index by 32-bit units, and return a 32-bit value. Intended to replace fetchWord:ofObject: */

sqInt fetchLong32ofObject(sqInt fieldIndex, sqInt oop) {
	return long32At((oop + BaseHeaderSize) + (fieldIndex << 2));
}


/*	index by word size, and return a pointer as long as the word size */

sqInt fetchPointerofObject(sqInt fieldIndex, sqInt oop) {
	return longAt((oop + BaseHeaderSize) + (fieldIndex << ShiftForWord));
}


/*	Return the stackPointer of a Context or BlockContext. */

sqInt fetchStackPointerOf(sqInt aContext) {
    sqInt sp;

	sp = longAt((aContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord));
	if (!((sp & 1))) {
		return 0;
	}
	return (sp >> 1);
}


/*	NOTE: this gives size appropriate for fetchPointer: n, but not in general for, eg, fetchLong32, etc. */

sqInt fetchWordLengthOf(sqInt objectPointer) {
    sqInt sz;
    sqInt header;

	/* begin sizeBitsOf: */
	header = longAt(objectPointer);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(objectPointer - (BytesPerWord * 2))) & LongSizeMask;
		goto l1;
	} else {
		sz = header & SizeMask;
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	return ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
}


/*	During sweep phase we have encountered a weak reference. 
	Check if  its object has gone away (or is about to) and if so, signal a 
	semaphore.  */
/*	Do *not* inline this in sweepPhase - it is quite an unlikely 
	case to run into a weak reference */

sqInt finalizeReference(usqInt oop) {
    sqInt chunk;
    sqInt lastField;
    sqInt oopGone;
    sqInt firstField;
    usqInt weakOop;
    sqInt i;
    sqInt sz;
    sqInt header;
    sqInt contextSize;
    sqInt fmt;
    sqInt methodHeader;
    sqInt sp;
    sqInt header1;
    sqInt type;

	firstField = BaseHeaderSize + ((nonWeakFieldsOf(oop)) << ShiftForWord);
	/* begin lastPointerOf: */
	header = longAt(oop);
	fmt = (((usqInt) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && ((((((usqInt) header) >> 12) & 31) == 13) || ((((((usqInt) header) >> 12) & 31) == 14) || (((((usqInt) header) >> 12) & 31) == 4)))) {
			/* begin fetchStackPointerOf: */
			sp = longAt((oop + BaseHeaderSize) + (StackPointerIndex << ShiftForWord));
			if (!((sp & 1))) {
				contextSize = 0;
				goto l2;
			}
			contextSize = (sp >> 1);
		l2:	/* end fetchStackPointerOf: */;
			lastField = (CtxtTempFrameStart + contextSize) * BytesPerWord;
			goto l1;
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(oop);
		/* begin rightType: */
		if ((header1 & SizeMask) == 0) {
			type = HeaderTypeSizeAndClass;
			goto l3;
		} else {
			if ((header1 & CompactClassMask) == 0) {
				type = HeaderTypeClass;
				goto l3;
			} else {
				type = HeaderTypeShort;
				goto l3;
			}
		}
	l3:	/* end rightType: */;
		if (type == HeaderTypeSizeAndClass) {
			sz = (longAt(oop - (BytesPerWord * 2))) & AllButTypeMask;
			goto l4;
		} else {
			sz = header1 & SizeMask;
			goto l4;
		}
	l4:	/* end sizeBitsOfSafe: */;
		lastField = sz - BaseHeaderSize;
		goto l1;
	}
	if (fmt < 12) {
		lastField = 0;
		goto l1;
	}
	methodHeader = longAt(oop + BaseHeaderSize);
	lastField = (((((usqInt) methodHeader) >> 10) & 255) * BytesPerWord) + BaseHeaderSize;
l1:	/* end lastPointerOf: */;
	for (i = firstField; i <= lastField; i += BytesPerWord) {

		/* ar 1/18/2005: Added oop < youngStart test to make sure we're not testing
			objects in non-GCable region. This could lead to a forward reference in
			old space with the oop pointed to not being marked and thus treated as free. */

		weakOop = longAt(oop + i);
		if (!((weakOop == nilObj) || (((weakOop & 1)) || (weakOop < youngStart)))) {
			if (weakOop < oop) {

				/* Check if the object is being collected. 
					If the weak reference points  
					* backward: check if the weakOops chunk is free
					* forward: check if the weakOoop has been marked by GC */

				chunk = weakOop - (headerTypeBytes[(longAt(weakOop)) & TypeMask]);
				oopGone = ((longAt(chunk)) & TypeMask) == HeaderTypeFree;
			} else {
				oopGone = ((longAt(weakOop)) & MarkBit) == 0;
			}
			if (oopGone) {
				longAtput(oop + i, nilObj);
				/* begin signalFinalization: */
				/* begin forceInterruptCheck */
				interruptCheckCounter = -1000;
				nextPollTick = 0;
				pendingFinalizationSignals += 1;
			}
		}
	}
}

sqInt findClassOfMethodforReceiver(sqInt meth, sqInt rcvr) {
    sqInt done;
    sqInt classDict;
    sqInt classDictSize;
    sqInt i;
    sqInt currClass;
    sqInt methodArray;
    sqInt sz;
    sqInt header;
    sqInt ccIndex;
    sqInt ccIndex1;

	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		currClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l2;
	}
	ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		currClass = (longAt(rcvr - BaseHeaderSize)) & AllButTypeMask;
		goto l2;
	} else {
		currClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l2;
	}
l2:	/* end fetchClassOf: */;
	done = 0;
	while (!(done)) {
		classDict = longAt((currClass + BaseHeaderSize) + (MessageDictionaryIndex << ShiftForWord));
		/* begin fetchWordLengthOf: */
		/* begin sizeBitsOf: */
		header = longAt(classDict);
		if ((header & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(classDict - (BytesPerWord * 2))) & LongSizeMask;
			goto l1;
		} else {
			sz = header & SizeMask;
			goto l1;
		}
	l1:	/* end sizeBitsOf: */;
		classDictSize = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
		methodArray = longAt((classDict + BaseHeaderSize) + (MethodArrayIndex << ShiftForWord));
		i = 0;
		while (i < (classDictSize - SelectorStart)) {
			if (meth == (longAt((methodArray + BaseHeaderSize) + (i << ShiftForWord)))) {
				return currClass;
			}
			i += 1;
		}
		currClass = longAt((currClass + BaseHeaderSize) + (SuperclassIndex << ShiftForWord));
		done = currClass == nilObj;
	}
	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		return longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
	}
	ccIndex1 = (((usqInt) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex1 == 0) {
		return (longAt(rcvr - BaseHeaderSize)) & AllButTypeMask;
	} else {
		return longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex1 - 1) << ShiftForWord));
	}
	return null;
}


/*	Find the compiled method to be run when the current 
	messageSelector is sent to the given class, setting the values 
	of 'newMethod' and 'primitiveIndex'. */

sqInt findNewMethodInClass(sqInt class) {
    sqInt ok;
    sqInt hash;
    sqInt probe;

	/* begin lookupInMethodCacheSel:class: */
	hash = messageSelector ^ class;
	probe = hash & MethodCacheMask;
	if (((methodCache[probe + MethodCacheSelector]) == messageSelector) && ((methodCache[probe + MethodCacheClass]) == class)) {
		newMethod = methodCache[probe + MethodCacheMethod];
		primitiveIndex = methodCache[probe + MethodCachePrim];
		newNativeMethod = methodCache[probe + MethodCacheNative];
		primitiveFunctionPointer = ((void *) (methodCache[probe + MethodCachePrimFunction]));
		ok = 1;
		goto l1;
	}
	probe = (((usqInt) hash) >> 1) & MethodCacheMask;
	if (((methodCache[probe + MethodCacheSelector]) == messageSelector) && ((methodCache[probe + MethodCacheClass]) == class)) {
		newMethod = methodCache[probe + MethodCacheMethod];
		primitiveIndex = methodCache[probe + MethodCachePrim];
		newNativeMethod = methodCache[probe + MethodCacheNative];
		primitiveFunctionPointer = ((void *) (methodCache[probe + MethodCachePrimFunction]));
		ok = 1;
		goto l1;
	}
	probe = (((usqInt) hash) >> 2) & MethodCacheMask;
	if (((methodCache[probe + MethodCacheSelector]) == messageSelector) && ((methodCache[probe + MethodCacheClass]) == class)) {
		newMethod = methodCache[probe + MethodCacheMethod];
		primitiveIndex = methodCache[probe + MethodCachePrim];
		newNativeMethod = methodCache[probe + MethodCacheNative];
		primitiveFunctionPointer = ((void *) (methodCache[probe + MethodCachePrimFunction]));
		ok = 1;
		goto l1;
	}
	ok = 0;
l1:	/* end lookupInMethodCacheSel:class: */;
	if (!(ok)) {
		lookupMethodInClass(class);
		lkupClass = class;
		addNewMethodToCache();
	}
}


/*	Search the obsolete named primitive table for the given function.
	Return the index if it's found, -1 otherwise. */

sqInt findObsoleteNamedPrimitivelength(char * functionName, sqInt functionLength) {
    sqInt chIndex;
    sqInt index;
    const char * entry;

	index = 0;
	while (1) {
		entry = obsoleteNamedPrimitiveTable[index][0];
		if (entry == null) {
			return -1;
		}
		;
		chIndex = 0;
		while (((entry[chIndex]) == (functionName[chIndex])) && (chIndex < functionLength)) {
			chIndex += 1;
		}
		if ((chIndex == functionLength) && ((entry[chIndex]) == 0)) {
			return index;
		}
		index += 1;
	}
}

sqInt findSelectorOfMethodforReceiver(sqInt meth, sqInt rcvr) {
    sqInt done;
    sqInt classDict;
    sqInt classDictSize;
    sqInt i;
    sqInt currClass;
    sqInt methodArray;
    sqInt sz;
    sqInt header;
    sqInt ccIndex;

	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		currClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l2;
	}
	ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		currClass = (longAt(rcvr - BaseHeaderSize)) & AllButTypeMask;
		goto l2;
	} else {
		currClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l2;
	}
l2:	/* end fetchClassOf: */;
	done = 0;
	while (!(done)) {
		classDict = longAt((currClass + BaseHeaderSize) + (MessageDictionaryIndex << ShiftForWord));
		/* begin fetchWordLengthOf: */
		/* begin sizeBitsOf: */
		header = longAt(classDict);
		if ((header & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(classDict - (BytesPerWord * 2))) & LongSizeMask;
			goto l1;
		} else {
			sz = header & SizeMask;
			goto l1;
		}
	l1:	/* end sizeBitsOf: */;
		classDictSize = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
		methodArray = longAt((classDict + BaseHeaderSize) + (MethodArrayIndex << ShiftForWord));
		i = 0;
		while (i <= (classDictSize - SelectorStart)) {
			if (meth == (longAt((methodArray + BaseHeaderSize) + (i << ShiftForWord)))) {
				return longAt((classDict + BaseHeaderSize) + ((i + SelectorStart) << ShiftForWord));
			}
			i += 1;
		}
		currClass = longAt((currClass + BaseHeaderSize) + (SuperclassIndex << ShiftForWord));
		done = currClass == nilObj;
	}
	return nilObj;
}


/*	Return the first accessible object in the heap. */

sqInt firstAccessibleObject(void) {
    sqInt obj;
    sqInt sz;
    sqInt header;

	obj = memory + (headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) obj)) < (((usqInt) endOfMemory))) {
		if (!(((longAt(obj)) & TypeMask) == HeaderTypeFree)) {
			return obj;
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) obj)) >= (((usqInt) endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(obj)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(obj)) & AllButTypeMask;
		} else {
			/* begin sizeBitsOf: */
			header = longAt(obj);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(obj - (BytesPerWord * 2))) & LongSizeMask;
				goto l1;
			} else {
				sz = header & SizeMask;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		obj = (obj + sz) + (headerTypeBytes[(longAt(obj + sz)) & TypeMask]);
	}
	error("heap is empty");
}

char * firstFixedField(sqInt oop) {
	return pointerForOop(oop + BaseHeaderSize);
}


/*	NOTE: copied in InterpreterSimulator, so please duplicate any changes */

char * firstIndexableField(sqInt oop) {
    sqInt totalLength;
    sqInt fmt;
    sqInt fixedFields;
    sqInt hdr;
    sqInt sz;
    sqInt classFormat;
    sqInt class;
    sqInt ccIndex;

	hdr = longAt(oop);
	fmt = (((usqInt) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz = hdr & SizeMask;
	}
	sz -= hdr & Size4Bit;
	if (fmt <= 4) {
		totalLength = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
		goto l1;
	}
	if (fmt < 8) {
		totalLength = ((usqInt) (sz - BaseHeaderSize)) >> 2;
		goto l1;
	} else {
		totalLength = (sz - BaseHeaderSize) - (fmt & 3);
		goto l1;
	}
l1:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l2;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l2;
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		class = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l3;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(oop - BaseHeaderSize)) & AllButTypeMask;
		goto l3;
	} else {
		class = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	classFormat = (longAt((class + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1;
	fixedFields = (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
l2:	/* end fixedFieldsOf:format:length: */;
	if (fmt < 8) {
		if (fmt == 6) {
			return pointerForOop((oop + BaseHeaderSize) + (fixedFields << 2));
		}
		return pointerForOop((oop + BaseHeaderSize) + (fixedFields << ShiftForWord));
	} else {
		return pointerForOop((oop + BaseHeaderSize) + fixedFields);
	}
}

sqInt floatObjectOf(double  aFloat) {
    sqInt newFloatObj;

	flag("Dan");
	newFloatObj = instantiateSmallClasssizeInBytes(longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)), 8 + BaseHeaderSize);
	storeFloatAtfrom(newFloatObj + BaseHeaderSize, aFloat);
	return newFloatObj;
}


/*	Fetch the instance variable at the given index of the given object. Return the C double precision floating point value of that instance variable, or fail if it is not a Float. */
/*	Note: May be called by translated primitive code. */

double floatValueOf(sqInt oop) {
    double  result;
    sqInt cl;
    sqInt ccIndex;

	flag("Dan");
	/* begin assertClassOf:is: */
	if ((oop & 1)) {
		successFlag = 0;
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(oop - BaseHeaderSize)) & AllButTypeMask;
	} else {
		cl = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
	}
	/* begin success: */
	successFlag = (cl == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) && successFlag;
l1:	/* end assertClassOf:is: */;
	if (successFlag) {
		;
		fetchFloatAtinto(oop + BaseHeaderSize, result);
	} else {
		result = 0.0;
	}
	return result;
}


/*	methodPtr is a CompiledMethod containing an external primitive. Flush the function address and session ID of the CM */

sqInt flushExternalPrimitiveOf(sqInt methodPtr) {
    sqInt lit;

	if (!(((((usqInt) (longAt((methodPtr + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 10) & 255) > 0)) {
		return null;
	}
	lit = longAt((methodPtr + BaseHeaderSize) + ((0 + LiteralStart) << ShiftForWord));
	if (!((((lit & 1) == 0) && (((((usqInt) (longAt(lit))) >> 8) & 15) == 2)) && ((lengthOf(lit)) == 4))) {
		return null;
	}
	longAtput((lit + BaseHeaderSize) + (2 << ShiftForWord), ConstZero);
	longAtput((lit + BaseHeaderSize) + (3 << ShiftForWord), ConstZero);
}


/*	Flush the references to external functions from plugin 
	primitives. This will force a reload of those primitives when 
	accessed next. 
	Note: We must flush the method cache here so that any 
	failed primitives are looked up again. */

sqInt flushExternalPrimitives(void) {
    sqInt oop;
    sqInt primIdx;
    sqInt primBits;
    sqInt sz;
    sqInt header;
    sqInt i;
    sqInt i1;
    sqInt i2;

	oop = memory + (headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) endOfMemory))) {
		if (!(((longAt(oop)) & TypeMask) == HeaderTypeFree)) {
			if (((((usqInt) (longAt(oop))) >> 8) & 15) >= 12) {
				/* begin primitiveIndexOf: */
				primBits = (((usqInt) (longAt((oop + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 1) & 268435967;
				primIdx = (primBits & 511) + (((usqInt) primBits) >> 19);
				if (primIdx == PrimitiveExternalCallIndex) {
					flushExternalPrimitiveOf(oop);
				}
			}
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) oop)) >= (((usqInt) endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(oop)) & AllButTypeMask;
		} else {
			/* begin sizeBitsOf: */
			header = longAt(oop);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
				goto l1;
			} else {
				sz = header & SizeMask;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		oop = (oop + sz) + (headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	}
	/* begin flushMethodCache */
	for (i = 1; i <= MethodCacheSize; i += 1) {
		methodCache[i] = 0;
	}
	for (i = 1; i <= AtCacheTotalSize; i += 1) {
		atCache[i] = 0;
	}
	/* begin flushObsoleteIndexedPrimitives */
	for (i1 = 1; i1 <= MaxPrimitiveIndex; i1 += 1) {
		(obsoleteIndexedPrimitiveTable[i1])[2] = null;
	}
	/* begin flushExternalPrimitiveTable */
	for (i2 = 0; i2 <= (MaxExternalPrimitiveTableSize - 1); i2 += 1) {
		externalPrimitiveTable[i2] = 0;
	}
}


/*	force an interrupt check ASAP - setting interruptCheckCounter to a large -ve number is used as a flag to skip messing with the feedback mechanism and nextPollTick resetting makes sure that ioProcess gets called as near immediately as we can manage */

sqInt forceInterruptCheck(void) {
	interruptCheckCounter = -1000;
	nextPollTick = 0;
}


/*	Repaint the entire smalltalk screen, ignoring the affected rectangle. Used in some platform's code when the Smalltalk window is brought to the front or uncovered. */

sqInt fullDisplayUpdate(void) {
    sqInt displayObj;
    sqInt h;
    sqInt w;

	displayObj = longAt((specialObjectsOop + BaseHeaderSize) + (TheDisplay << ShiftForWord));
	if ((((displayObj & 1) == 0) && (((((usqInt) (longAt(displayObj))) >> 8) & 15) <= 4)) && ((lengthOf(displayObj)) >= 4)) {
		w = fetchIntegerofObject(1, displayObj);
		h = fetchIntegerofObject(2, displayObj);
		displayBitsOfLeftTopRightBottom(displayObj, 0, 0, w, h);
		ioForceDisplayUpdate();
	}
}


/*	Do a mark/sweep garbage collection of the entire object memory. Free inaccessible objects but do not move them. */

sqInt fullGC(void) {
    sqInt startTime;
    sqInt oop;
    sqInt i;
    sqInt sz;

	if (DoAssertionChecks) {
		reverseDisplayFromto(0, 7);
	}
	/* begin preGCAction: */
	if (compilerInitialized) {
		compilerPreGC(1);
	} else {
		/* begin storeContextRegisters: */
		longAtput((activeContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord), ((((instructionPointer - method) - (BaseHeaderSize - 2)) << 1) | 1));
		longAtput((activeContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord), (((((((usqInt) ((stackPointer - activeContext) - BaseHeaderSize)) >> ShiftForWord) - TempFrameStart) + 1) << 1) | 1));
	}
	startTime = ioMicroMSecs();
	statSweepCount = statMarkCount = statMkFwdCount = statCompMoveCount = 0;
	/* begin clearRootsTable */
	for (i = 1; i <= rootTableCount; i += 1) {
		oop = rootTable[i];
		longAtput(oop, (longAt(oop)) & AllButRootBit);
		rootTable[i] = 0;
	}
	rootTableCount = 0;

	/* process all of memory */

	youngStart = memory;
	markPhase();
	totalObjectCount = sweepPhase();
	/* begin fullCompaction */
	compStart = lowestFreeAfter(memory);
	if (compStart == freeBlock) {
		initializeMemoryFirstFree(freeBlock);
		goto l1;
	}
	if ((sz = fwdTableSize(8)) < totalObjectCount) {
		growObjectMemory(((totalObjectCount - sz) + 10000) * 8);
	}
	while (compStart < freeBlock) {
		compStart = incCompBody();
	}
l1:	/* end fullCompaction */;
	allocationCount = 0;
	statFullGCs += 1;
	statGCTime = ioMicroMSecs();
	statFullGCMSecs += statGCTime - startTime;
	/* begin capturePendingFinalizationSignals */
	statpendingFinalizationSignals = pendingFinalizationSignals;

	/* reset the young object boundary */

	youngStart = freeBlock;
	postGCAction();
	if (DoAssertionChecks) {
		reverseDisplayFromto(0, 7);
	}
}


/*	Set the limits for a table of two- or three-word forwarding blocks above the last used oop. The pointer fwdTableNext moves up to fwdTableLast. Used for compaction of memory and become-ing objects. Returns the number of forwarding blocks available. */

sqInt fwdTableInit(sqInt blkSize) {
	/* begin setSizeOfFree:to: */
	longAtput(freeBlock, (BaseHeaderSize & AllButTypeMask) | HeaderTypeFree);

	/* make a fake free chunk at endOfMemory for use as a sentinal in memory scans */

	endOfMemory = freeBlock + BaseHeaderSize;
	/* begin setSizeOfFree:to: */
	longAtput(endOfMemory, (BaseHeaderSize & AllButTypeMask) | HeaderTypeFree);
	fwdTableNext = ((endOfMemory + BaseHeaderSize) + 7) & (WordMask - 7);
	flag("Dan");

	/* last forwarding table entry */
	/* return the number of forwarding blocks available */

	fwdTableLast = memoryLimit - blkSize;
	return (fwdTableLast - fwdTableNext) / blkSize;
}


/*	Estimate the number of forwarding blocks available for compaction */

sqInt fwdTableSize(sqInt blkSize) {
    sqInt fwdLast;
    sqInt eom;
    sqInt fwdFirst;


	/* use all memory free between freeBlock and memoryLimit for forwarding table */
	/* Note: Forward blocks must be quadword aligned. */

	eom = freeBlock + BaseHeaderSize;
	fwdFirst = ((eom + BaseHeaderSize) + 7) & (WordMask - 7);
	flag("Dan");

	/* last forwarding table entry */
	/* return the number of forwarding blocks available */

	fwdLast = memoryLimit - blkSize;
	return (fwdLast - fwdFirst) / blkSize;
}


/*	currentBytecode will be private to the main dispatch loop in the generated code. This method allows the currentBytecode to be retrieved from global variables. */

sqInt getCurrentBytecode(void) {
	return byteAt(instructionPointer);
}

sqInt getFullScreenFlag(void) {
	return fullScreenFlag;
}

sqInt getInterruptCheckCounter(void) {
	return interruptCheckCounter;
}

sqInt getInterruptKeycode(void) {
	return interruptKeycode;
}

sqInt getInterruptPending(void) {
	return interruptPending;
}


/*	Answer the next word read from aFile, byte-swapped according to the swapFlag. */

sqInt getLongFromFileswap(sqImageFile  aFile, sqInt swapFlag) {
    sqInt w;

	w = 0;
	sqImageFileRead(&w, sizeof(w), 1, aFile);
	if (swapFlag) {
		return byteSwapped(w);
	} else {
		return w;
	}
}

sqInt getNextWakeupTick(void) {
	return nextWakeupTick;
}

sqInt getSavedWindowSize(void) {
	return savedWindowSize;
}


/*	return the global session ID value */

sqInt getThisSessionID(void) {
	return globalSessionID;
}


/*	Attempt to grow the object memory by the given delta 
	amount  */

sqInt growObjectMemory(usqInt delta) {
    usqInt limit;

	if (!(isExcessiveAllocationRequestshift(delta, 0))) {
		statGrowMemory += 1;
		limit = sqGrowMemoryBy(memoryLimit, delta);
		if (!(limit == memoryLimit)) {

			/* remove a tad for safety */

			memoryLimit = limit - 24;
			initializeMemoryFirstFree(freeBlock);
		}
	}
}


/*	This VM is forwards-compatible with the immediately following closure version, and
	 will write the new version number in snapshots if the closure creation bytecode is used. */

sqInt imageFormatForwardCompatibilityVersion(void) {
	if (BytesPerWord == 4) {
		return 6504;
	} else {
		return 68002;
	}
}


/*	a more complex version that tells both the word reversal and the endianness of the machine it came from.  Low half of word is 6502.  Top byte is top byte of #doesNotUnderstand: on this machine. ($d on the Mac or $s on the PC) */

sqInt imageSegmentVersion(void) {
    sqInt wholeWord;


	/* first data word, 'does'  */

	wholeWord = longAt((longAt((specialObjectsOop + BaseHeaderSize) + (SelectorDoesNotUnderstand << ShiftForWord))) + BaseHeaderSize);
	return imageFormatVersionNumber | (wholeWord & 4278190080U);
}


/*	Move objects to consolidate free space into one big chunk. Return the newly created free chunk. */

sqInt incCompBody(void) {
    sqInt bytesFreed;

	fwdTableInit(BytesPerWord * 2);

	/* update pointers to point at new oops */

	bytesFreed = incCompMakeFwd();
	mapPointersInObjectsFromto(youngStart, endOfMemory);
	return incCompMove(bytesFreed);
}


/*	Create and initialize forwarding blocks for all non-free objects  
	following compStart. If the supply of forwarding blocks is exhausted,  
	set compEnd to the first chunk above the area to be 
	compacted; otherwise, set it to endOfMemory. Return the number of 
	bytes to be freed. */

sqInt incCompMakeFwd(void) {
    sqInt oop;
    sqInt newOop;
    sqInt fwdBlock;
    sqInt bytesFreed;
    sqInt originalHeader;
    sqInt originalHeaderType;
    sqInt sz;
    sqInt header;
    sqInt fwdBlock1;
    sqInt realHeader;
    sqInt sz1;
    sqInt header1;

	bytesFreed = 0;
	oop = compStart + (headerTypeBytes[(longAt(compStart)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) endOfMemory))) {
		statMkFwdCount += 1;
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			bytesFreed += (longAt(oop)) & AllButTypeMask;
		} else {
			/* begin fwdBlockGet: */
			fwdTableNext += BytesPerWord * 2;
			if (fwdTableNext <= fwdTableLast) {
				fwdBlock = fwdTableNext;
				goto l1;
			} else {
				fwdBlock = null;
				goto l1;
			}
		l1:	/* end fwdBlockGet: */;
			if (fwdBlock == null) {

				/* stop; we have used all available forwarding blocks */

				compEnd = oop - (headerTypeBytes[(longAt(oop)) & TypeMask]);
				return bytesFreed;
			}
			newOop = oop - bytesFreed;
			/* begin initForwardBlock:mapping:to:withBackPtr: */
			originalHeader = longAt(oop);
			if (DoAssertionChecks) {
				if (fwdBlock == null) {
					error("ran out of forwarding blocks in become");
				}
				if ((originalHeader & MarkBit) != 0) {
					error("object already has a forwarding table entry");
				}
			}
			originalHeaderType = originalHeader & TypeMask;
			longAtput(fwdBlock, newOop);
			longAtput(fwdBlock + BytesPerWord, originalHeader);
			if (0) {
				longAtput(fwdBlock + (BytesPerWord * 2), oop);
			}
			longAtput(oop, (((usqInt) fwdBlock) >> 1) | (MarkBit | originalHeaderType));
		}
		/* begin objectAfterWhileForwarding: */
		header = longAt(oop);
		if ((header & MarkBit) == 0) {
			/* begin objectAfter: */
			if (DoAssertionChecks) {
				if ((((usqInt) oop)) >= (((usqInt) endOfMemory))) {
					error("no objects after the end of memory");
				}
			}
			if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
				sz1 = (longAt(oop)) & AllButTypeMask;
			} else {
				/* begin sizeBitsOf: */
				header1 = longAt(oop);
				if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
					sz1 = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
					goto l2;
				} else {
					sz1 = header1 & SizeMask;
					goto l2;
				}
			l2:	/* end sizeBitsOf: */;
			}
			oop = (oop + sz1) + (headerTypeBytes[(longAt(oop + sz1)) & TypeMask]);
			goto l3;
		}
		fwdBlock1 = (header & AllButMarkBitAndTypeMask) << 1;
		if (DoAssertionChecks) {
			/* begin fwdBlockValidate: */
			if (!(((((usqInt) fwdBlock1)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock1)) <= (((usqInt) fwdTableNext))) && ((fwdBlock1 & 3) == 0)))) {
				error("invalid fwd table entry");
			}
		}
		realHeader = longAt(fwdBlock1 + BytesPerWord);
		if ((realHeader & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
		} else {
			sz = realHeader & SizeMask;
		}
		oop = (oop + sz) + (headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	l3:	/* end objectAfterWhileForwarding: */;
	}
	compEnd = endOfMemory;
	return bytesFreed;
}


/*	Move all non-free objects between compStart and compEnd to their new  
	locations, restoring their headers in the process. Create a new free  
	block at the end of memory. Return the newly created free chunk.  */
/*	Note: The free block used by the allocator always must be the last free  
	block in memory. It may take several compaction passes to make all  
	free space bubble up to the end of memory. */

sqInt incCompMove(sqInt bytesFreed) {
    usqInt w;
    usqInt lastWord;
    sqInt oop;
    sqInt target;
    sqInt newOop;
    sqInt sz;
    sqInt next;
    sqInt fwdBlock;
    sqInt header;
    sqInt bytesToMove;
    sqInt newFreeChunk;
    usqInt firstWord;
    sqInt header1;
    sqInt sz2;
    sqInt header2;
    sqInt fwdBlock1;
    sqInt realHeader;
    sqInt sz1;
    sqInt header11;

	newOop = null;
	oop = compStart + (headerTypeBytes[(longAt(compStart)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) compEnd))) {
		statCompMoveCount += 1;
		/* begin objectAfterWhileForwarding: */
		header2 = longAt(oop);
		if ((header2 & MarkBit) == 0) {
			/* begin objectAfter: */
			if (DoAssertionChecks) {
				if ((((usqInt) oop)) >= (((usqInt) endOfMemory))) {
					error("no objects after the end of memory");
				}
			}
			if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
				sz1 = (longAt(oop)) & AllButTypeMask;
			} else {
				/* begin sizeBitsOf: */
				header11 = longAt(oop);
				if ((header11 & TypeMask) == HeaderTypeSizeAndClass) {
					sz1 = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
					goto l2;
				} else {
					sz1 = header11 & SizeMask;
					goto l2;
				}
			l2:	/* end sizeBitsOf: */;
			}
			next = (oop + sz1) + (headerTypeBytes[(longAt(oop + sz1)) & TypeMask]);
			goto l3;
		}
		fwdBlock1 = (header2 & AllButMarkBitAndTypeMask) << 1;
		if (DoAssertionChecks) {
			/* begin fwdBlockValidate: */
			if (!(((((usqInt) fwdBlock1)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock1)) <= (((usqInt) fwdTableNext))) && ((fwdBlock1 & 3) == 0)))) {
				error("invalid fwd table entry");
			}
		}
		realHeader = longAt(fwdBlock1 + BytesPerWord);
		if ((realHeader & TypeMask) == HeaderTypeSizeAndClass) {
			sz2 = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
		} else {
			sz2 = realHeader & SizeMask;
		}
		next = (oop + sz2) + (headerTypeBytes[(longAt(oop + sz2)) & TypeMask]);
	l3:	/* end objectAfterWhileForwarding: */;
		if (!(((longAt(oop)) & TypeMask) == HeaderTypeFree)) {

			/* a moving object; unwind its forwarding block */

			fwdBlock = ((longAt(oop)) & AllButMarkBitAndTypeMask) << 1;
			if (DoAssertionChecks) {
				/* begin fwdBlockValidate: */
				if (!(((((usqInt) fwdBlock)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock)) <= (((usqInt) fwdTableNext))) && ((fwdBlock & 3) == 0)))) {
					error("invalid fwd table entry");
				}
			}
			newOop = longAt(fwdBlock);
			header = longAt(fwdBlock + BytesPerWord);
			longAtput(oop, header);

			/* move the oop (including any extra header words)  */

			bytesToMove = oop - newOop;
			/* begin sizeBitsOf: */
			header1 = longAt(oop);
			if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
				goto l1;
			} else {
				sz = header1 & SizeMask;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
			firstWord = oop - (headerTypeBytes[(longAt(oop)) & TypeMask]);
			lastWord = (oop + sz) - BaseHeaderSize;
			target = firstWord - bytesToMove;
			for (w = firstWord; w <= lastWord; w += BytesPerWord) {
				longAtput(target, longAt(w));
				target += BytesPerWord;
			}
		}
		oop = next;
	}
	if (newOop == null) {

		/* no objects moved */

		oop = compStart + (headerTypeBytes[(longAt(compStart)) & TypeMask]);
		if ((((longAt(oop)) & TypeMask) == HeaderTypeFree) && ((objectAfter(oop)) == (compEnd + (headerTypeBytes[(longAt(compEnd)) & TypeMask])))) {
			newFreeChunk = oop;
		} else {
			newFreeChunk = freeBlock;
		}
	} else {

		/* initialize the newly freed memory chunk */
		/* newOop is the last object moved; free chunk starts 
			right after it */

		newFreeChunk = newOop + (sizeBitsOf(newOop));
		/* begin setSizeOfFree:to: */
		longAtput(newFreeChunk, (bytesFreed & AllButTypeMask) | HeaderTypeFree);
	}
	if (DoAssertionChecks) {
		if (!((objectAfter(newFreeChunk)) == (compEnd + (headerTypeBytes[(longAt(compEnd)) & TypeMask])))) {
			error("problem creating free chunk after compaction");
		}
	}
	if ((objectAfter(newFreeChunk)) == endOfMemory) {
		initializeMemoryFirstFree(newFreeChunk);
	} else {
		initializeMemoryFirstFree(freeBlock);
	}
	return newFreeChunk;
}


/*	Return the equivalent of 
		aClass includesBehavior: aSuperclass.
	Note: written for efficiency and better inlining (only 1 temp) */

sqInt includesBehaviorThatOf(sqInt aClass, sqInt aSuperclass) {
    sqInt theClass;

	if (((theClass = aClass) == aSuperclass) || (aSuperclass == nilObj)) {
		return 1;
	}
	do {
		if ((theClass = longAt((theClass + BaseHeaderSize) + (SuperclassIndex << ShiftForWord))) == aSuperclass) {
			return 1;
		}
	} while(theClass != nilObj);
	return 0;
}


/*	Do a mark/sweep garbage collection of just the young object 
	area of object memory (i.e., objects above youngStart), using 
	the root table to identify objects containing pointers to 
	young objects from the old object area. */

sqInt incrementalGC(void) {
    sqInt weDidGrow;
    sqInt startTime;
    sqInt survivorCount;
    sqInt i;
    sqInt oop;
    sqInt i1;
    sqInt growth;

	if (rootTableCount >= RootTableSize) {

		/* root table overflow; cannot do an incremental GC (this should be very rare) */

		statRootTableOverflows += 1;
		return fullGC();
	}
	if (DoAssertionChecks) {
		reverseDisplayFromto(8, 15);
		validateRoots();
		/* begin validate */
	}
	/* begin preGCAction: */
	if (compilerInitialized) {
		compilerPreGC(0);
	} else {
		/* begin storeContextRegisters: */
		longAtput((activeContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord), ((((instructionPointer - method) - (BaseHeaderSize - 2)) << 1) | 1));
		longAtput((activeContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord), (((((((usqInt) ((stackPointer - activeContext) - BaseHeaderSize)) >> ShiftForWord) - TempFrameStart) + 1) << 1) | 1));
	}
	startTime = ioMicroMSecs();
	weakRootCount = 0;
	statSweepCount = statMarkCount = statMkFwdCount = statCompMoveCount = 0;
	markPhase();
	for (i = 1; i <= weakRootCount; i += 1) {
		finalizeReference(weakRoots[i]);
	}
	survivorCount = sweepPhase();
	/* begin incrementalCompaction */
	if (compStart == freeBlock) {
		initializeMemoryFirstFree(freeBlock);
	} else {
		incCompBody();
	}
	statAllocationCount = allocationCount;
	allocationCount = 0;
	statIncrGCs += 1;
	statGCTime = ioMicroMSecs();
	statIGCDeltaTime = statGCTime - startTime;
	statIncrGCMSecs += statIGCDeltaTime;
	/* begin capturePendingFinalizationSignals */
	statpendingFinalizationSignals = pendingFinalizationSignals;
	/* begin forceInterruptCheck */
	interruptCheckCounter = -1000;
	nextPollTick = 0;
	statRootTableCount = rootTableCount;
	statSurvivorCount = survivorCount;
	weDidGrow = 0;
	if (((survivorCount > tenuringThreshold) || (rootTableCount >= RootTableRedZone)) || (forceTenureFlag == 1)) {

		/* move up the young space boundary if 
			* there are too many survivors: 
			this limits the number of objects that must be 
			processed on future incremental GC's 
			* we're about to overflow the roots table 
			this limits the number of full GCs that may be caused 
			by root table overflows in the near future */

		forceTenureFlag = 0;
		statTenures += 1;
		/* begin clearRootsTable */
		for (i1 = 1; i1 <= rootTableCount; i1 += 1) {
			oop = rootTable[i1];
			longAtput(oop, (longAt(oop)) & AllButRootBit);
			rootTable[i1] = 0;
		}
		rootTableCount = 0;
		if ((freeBlock < growHeadroom) && (gcBiasToGrow > 0)) {
			biasToGrow();
			weDidGrow = 1;
		}
		youngStart = freeBlock;
	}
	postGCAction();
	if (DoAssertionChecks) {
		validateRoots();
		/* begin validate */
		reverseDisplayFromto(8, 15);
	}
	if (weDidGrow) {
		/* begin biasToGrowCheckGCLimit */
		growth = (youngStart - memory) - gcBiasToGrowThreshold;
		if (growth < 0) {
			gcBiasToGrowThreshold = youngStart - memory;
		}
		if (growth > gcBiasToGrowGCLimit) {
			fullGC();
			gcBiasToGrowThreshold = youngStart - memory;
		}
	}
}


/*	Initialize hooks for the 'null compiler' */

sqInt initCompilerHooks(void) {
	compilerHooks[1]= nullCompilerHook;
	compilerHooks[2]= nullCompilerHook;
	compilerHooks[3]= nullCompilerHook;
	compilerHooks[4]= nullCompilerHook;
	compilerHooks[5]= nullCompilerHook;
	compilerHooks[6]= nullCompilerHook;
	compilerHooks[7]= nullCompilerHook;
	compilerHooks[8]= nullCompilerHook;
	compilerHooks[9]= nullCompilerHook;
	compilerHooks[10]= nullCompilerHook;
	compilerHooks[11]= nullCompilerHook;
	compilerHooks[12]= nullCompilerHook;
	compilerHooks[13]= nullCompilerHook;
	compilerHooks[14]= nullCompilerHook;
	compilerInitialized = 0;
}


/*	Initialize Interpreter state before starting execution of a new image. */

sqInt initializeInterpreter(sqInt bytesToShift) {
    sqInt i;
    sqInt proc;
    sqInt sched;
    sqInt activeCntx;
    sqInt tmp;

	interpreterProxy = sqGetInterpreterProxy();
	dummyReferToProxy();
	initializeObjectMemory(bytesToShift);
	initCompilerHooks();
	activeContext = nilObj;
	theHomeContext = nilObj;
	method = nilObj;
	receiver = nilObj;
	messageSelector = nilObj;
	newMethod = nilObj;
	methodClass = nilObj;
	lkupClass = nilObj;
	receiverClass = nilObj;
	newNativeMethod = nilObj;
	/* begin flushMethodCache */
	for (i = 1; i <= MethodCacheSize; i += 1) {
		methodCache[i] = 0;
	}
	for (i = 1; i <= AtCacheTotalSize; i += 1) {
		atCache[i] = 0;
	}
	/* begin loadInitialContext */
	sched = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord));
	proc = longAt((sched + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
	activeContext = longAt((proc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord));
	if ((((usqInt) activeContext)) < (((usqInt) youngStart))) {
		beRootIfOld(activeContext);
	}
	/* begin fetchContextRegisters: */
	activeCntx = activeContext;
	tmp = longAt((activeCntx + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	if ((tmp & 1)) {
		tmp = longAt((activeCntx + BaseHeaderSize) + (HomeIndex << ShiftForWord));
		if ((((usqInt) tmp)) < (((usqInt) youngStart))) {
			beRootIfOld(tmp);
		}
	} else {
		tmp = activeCntx;
	}
	theHomeContext = tmp;
	receiver = longAt((tmp + BaseHeaderSize) + (ReceiverIndex << ShiftForWord));
	method = longAt((tmp + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	tmp = ((longAt((activeCntx + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord))) >> 1);
	instructionPointer = ((method + tmp) + BaseHeaderSize) - 2;
	tmp = ((longAt((activeCntx + BaseHeaderSize) + (StackPointerIndex << ShiftForWord))) >> 1);
	stackPointer = (activeCntx + BaseHeaderSize) + (((TempFrameStart + tmp) - 1) * BytesPerWord);
	reclaimableContextCount = 0;
	/* begin initialCleanup */
	if (((longAt(activeContext)) & RootBit) == 0) {
		goto l1;
	}
	longAtput(activeContext, (longAt(activeContext)) & AllButRootBit);
	flushExternalPrimitives();
l1:	/* end initialCleanup */;
	interruptCheckCounter = 0;
	interruptCheckCounterFeedBackReset = 1000;
	interruptChecksEveryNms = 1;
	nextPollTick = 0;
	nextWakeupTick = 0;
	lastTick = 0;

	/* cmd-. as used for Mac but no other OS */

	interruptKeycode = 2094;
	interruptPending = 0;
	semaphoresUseBufferA = 1;
	semaphoresToSignalCountA = 0;
	semaphoresToSignalCountB = 0;
	deferDisplayUpdates = 0;
	pendingFinalizationSignals = 0;
	globalSessionID = 0;
	while (globalSessionID == 0) {
		globalSessionID = time(NULL) + ioMSecs();
	}
	jmpDepth = 0;
	jmpMax = MaxJumpBuf;
}


/*	Initialize endOfMemory to the top of oop storage space, reserving some space for forwarding blocks, and create the freeBlock from which space is allocated. Also create a fake free chunk at endOfMemory to act as a sentinal for memory scans.  */
/*	Note: The amount of space reserved for forwarding blocks should be chosen to ensure that incremental compactions can usually be done in a single pass. However, there should be enough forwarding blocks so a full compaction can be done in a reasonable number of passes, say ten. (A full compaction requires N object-moving passes, where N = number of non-garbage objects / number of forwarding blocks). 
	di 11/18/2000 Re totalObjectCount: Provide a margin of one byte per object to be used for forwarding pointers at GC time. Since fwd blocks are 8 bytes, this means an absolute worst case of 8 passes to compact memory. In most cases it will be adequate to do compaction in a single pass.  */

sqInt initializeMemoryFirstFree(usqInt firstFree) {
    usqInt fwdBlockBytes;

	fwdBlockBytes = totalObjectCount & ((WordMask - BytesPerWord) + 1);
	if (!((((usqInt) (memoryLimit - fwdBlockBytes))) >= (((usqInt) (firstFree + BaseHeaderSize))))) {

		/* reserve enough space for a minimal free block of BaseHeaderSize bytes */

		fwdBlockBytes = memoryLimit - (firstFree + BaseHeaderSize);
	}
	endOfMemory = memoryLimit - fwdBlockBytes;
	freeBlock = firstFree;
	/* begin setSizeOfFree:to: */
	longAtput(freeBlock, ((endOfMemory - firstFree) & AllButTypeMask) | HeaderTypeFree);
	/* begin setSizeOfFree:to: */
	longAtput(endOfMemory, (BaseHeaderSize & AllButTypeMask) | HeaderTypeFree);
	if (DoAssertionChecks) {
		if (!((freeBlock < endOfMemory) && (endOfMemory < memoryLimit))) {
			error("error in free space computation");
		}
		if (!((endOfMemory + (headerTypeBytes[(longAt(endOfMemory)) & TypeMask])) == endOfMemory)) {
			error("header format must have changed");
		}
		if (!((objectAfter(freeBlock)) == endOfMemory)) {
			error("free block not properly initialized");
		}
	}
}


/*	Initialize object memory variables at startup time. Assume endOfMemory is initially set (by the image-reading code) to the end of the last object in the image. Initialization redefines endOfMemory to be the end of the object allocation area based on the total available memory, but reserving some space for forwarding blocks. */
/*	Assume: image reader initializes the following variables:
		memory
		endOfMemory
		memoryLimit
		specialObjectsOop
		lastHash
	 */
/*	di 11/18/2000 fix slow full GC */

sqInt initializeObjectMemory(sqInt bytesToShift) {

	/* image may be at a different address; adjust oops for new location */

	youngStart = endOfMemory;
	totalObjectCount = adjustAllOopsBy(bytesToShift);
	initializeMemoryFirstFree(endOfMemory);

	/* heavily used special objects */

	specialObjectsOop += bytesToShift;
	nilObj = longAt((specialObjectsOop + BaseHeaderSize) + (NilObject << ShiftForWord));
	falseObj = longAt((specialObjectsOop + BaseHeaderSize) + (FalseObject << ShiftForWord));
	trueObj = longAt((specialObjectsOop + BaseHeaderSize) + (TrueObject << ShiftForWord));
	rootTableCount = 0;
	freeContexts = NilContext;
	freeLargeContexts = NilContext;
	allocationCount = 0;
	lowSpaceThreshold = 0;
	signalLowSpace = 0;
	compStart = 0;
	compEnd = 0;
	fwdTableNext = 0;
	fwdTableLast = 0;
	remapBufferCount = 0;

	/* do incremental GC after this many allocations */

	allocationsBetweenGCs = 4000;

	/* tenure all suriving objects if count is over this threshold */

	tenuringThreshold = 2000;

	/* four megabyte of headroom when growing */

	growHeadroom = (4 * 1024) * 1024;

	/* eight megabyte of free space before shrinking */
	/* garbage collection statistics */

	shrinkThreshold = (8 * 1024) * 1024;
	statFullGCs = 0;
	statFullGCMSecs = 0;
	statIncrGCs = 0;
	statIncrGCMSecs = 0;
	statTenures = 0;
	statRootTableOverflows = 0;
	statGrowMemory = 0;
	statShrinkMemory = 0;
	forceTenureFlag = 0;
	gcBiasToGrow = 0;
	gcBiasToGrowGCLimit = 0;
	extraRootCount = 0;
}


/*	Install the oop of this object in the given cache (at or atPut), along with
	its size, format and fixedSize */

sqInt installinAtCacheatstring(sqInt rcvr, sqInt * cache, sqInt atIx, sqInt stringy) {
    sqInt totalLength;
    sqInt fmt;
    sqInt fixedFields;
    sqInt hdr;
    sqInt sz;
    sqInt classFormat;
    sqInt class;
    sqInt ccIndex;

	hdr = longAt(rcvr);
	fmt = (((usqInt) hdr) >> 8) & 15;
	if ((fmt == 3) && ((((((usqInt) hdr) >> 12) & 31) == 13) || ((((((usqInt) hdr) >> 12) & 31) == 14) || (((((usqInt) hdr) >> 12) & 31) == 4)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(rcvr - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz = hdr & SizeMask;
	}
	sz -= hdr & Size4Bit;
	if (fmt <= 4) {
		totalLength = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
		goto l1;
	}
	if (fmt < 8) {
		totalLength = ((usqInt) (sz - BaseHeaderSize)) >> 2;
		goto l1;
	} else {
		totalLength = (sz - BaseHeaderSize) - (fmt & 3);
		goto l1;
	}
l1:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l2;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l2;
	}
	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		class = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l3;
	}
	ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(rcvr - BaseHeaderSize)) & AllButTypeMask;
		goto l3;
	} else {
		class = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	classFormat = (longAt((class + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1;
	fixedFields = (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
l2:	/* end fixedFieldsOf:format:length: */;
	cache[atIx + AtCacheOop] = rcvr;
	if (stringy) {
		cache[atIx + AtCacheFmt] = (fmt + 16);
	} else {
		cache[atIx + AtCacheFmt] = fmt;
	}
	cache[atIx + AtCacheFixedFields] = fixedFields;
	cache[atIx + AtCacheSize] = (totalLength - fixedFields);
}


/*	NOTE: This method supports the backward-compatible split instSize field of the 
	class format word. The sizeHiBits will go away and other shifts change by 2 
	when the split fields get merged in an (incompatible) image change. */

sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size) {
    sqInt header1;
    sqInt binc;
    sqInt byteSize;
    sqInt hash;
    sqInt bm1;
    sqInt classFormat;
    sqInt header2;
    sqInt sizeHiBits;
    sqInt hdrSize;
    sqInt cClass;
    sqInt fillWord;
    sqInt newObj;
    sqInt format;
    sqInt header3;
    usqInt end;
    sqInt remappedClassOop;
    usqInt i;
    sqInt newObj1;
    sqInt oop;
    sqInt newFreeSize;
    sqInt enoughSpace;
    sqInt newChunk;
    usqInt minFree;
    sqInt sched;
    sqInt lastSavedProcess;
    sqInt currentProc;
    sqInt oop1;

	if (DoAssertionChecks) {
		if (size < 0) {
			error("cannot have a negative indexable field count");
		}
	}
	/* begin newObjectHash */
	lastHash = (13849 + (27181 * lastHash)) & 65535;
	hash = lastHash;

	/* Low 2 bits are 0 */

	classFormat = (longAt((classPointer + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1;
	header1 = (classFormat & 130816) | ((hash << HashBitsOffset) & HashBits);
	header2 = classPointer;
	header3 = 0;
	sizeHiBits = ((usqInt) (classFormat & 393216)) >> 9;

	/* compact class field from format word */

	cClass = header1 & CompactClassMask;

	/* size in bytes -- low 2 bits are 0 */
	/* Note this byteSize comes from the format word of the class which is pre-shifted
		to 4 bytes per field.  Need another shift for 8 bytes per word... */

	byteSize = (classFormat & (SizeMask + Size4Bit)) + sizeHiBits;
	byteSize = byteSize << (ShiftForWord - 2);
	format = (((usqInt) classFormat) >> 8) & 15;
	flag("sizeLowBits");
	if (format < 8) {
		if (format == 6) {

			/* long32 bitmaps */

			bm1 = BytesPerWord - 1;

			/* round up */

			byteSize = ((byteSize + (size * 4)) + bm1) & LongSizeMask;

			/* odd bytes */
			/* extra low bit (4) for 64-bit VM goes in 4-bit (betw hdr bits and sizeBits) */

			binc = bm1 - (((size * 4) + bm1) & bm1);
			header1 = header1 | (binc & 4);
		} else {

			/* Arrays and 64-bit bitmaps */

			byteSize += size * BytesPerWord;
		}
	} else {

		/* Strings and Methods */

		bm1 = BytesPerWord - 1;

		/* round up */

		byteSize = ((byteSize + size) + bm1) & LongSizeMask;

		/* odd bytes */
		/* low bits of byte size go in format field */

		binc = bm1 - ((size + bm1) & bm1);

		/* extra low bit (4) for 64-bit VM goes in 4-bit (betw hdr bits and sizeBits) */

		header1 = header1 | ((binc & 3) << 8);
		header1 = header1 | (binc & 4);
	}
	if (byteSize > 255) {

		/* requires size header word */

		header3 = byteSize;
		header1 = header1;
	} else {
		header1 = header1 | byteSize;
	}
	if (header3 > 0) {

		/* requires full header */

		hdrSize = 3;
	} else {
		if (cClass == 0) {
			hdrSize = 2;
		} else {
			hdrSize = 1;
		}
	}
	if (format <= 4) {

		/* if pointers, fill with nil oop */

		fillWord = nilObj;
	} else {
		fillWord = 0;
	}
	/* begin allocate:headerSize:h1:h2:h3:doFill:with: */
	if (hdrSize > 1) {
		/* begin pushRemappableOop: */
		remapBuffer[remapBufferCount += 1] = header2;
	}
	/* begin allocateChunk: */
	if (allocationCount >= allocationsBetweenGCs) {
		incrementalGC();
	}
	/* begin sufficientSpaceToAllocate: */
	minFree = (lowSpaceThreshold + (byteSize + ((hdrSize - 1) * BytesPerWord))) + BaseHeaderSize;
	if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) >= (((usqInt) minFree))) {
		enoughSpace = 1;
		goto l1;
	} else {
		enoughSpace = sufficientSpaceAfterGC(minFree);
		goto l1;
	}
l1:	/* end sufficientSpaceToAllocate: */;
	if (!(enoughSpace)) {
		signalLowSpace = 1;
		lowSpaceThreshold = 0;
		/* begin saveProcessSignalingLowSpace */
		lastSavedProcess = longAt((specialObjectsOop + BaseHeaderSize) + (ProcessSignalingLowSpace << ShiftForWord));
		if (lastSavedProcess == nilObj) {
			sched = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord));
			currentProc = longAt((sched + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
			/* begin storePointer:ofObject:withValue: */
			oop1 = specialObjectsOop;
			if ((((usqInt) oop1)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(oop1, currentProc);
			}
			longAtput((oop1 + BaseHeaderSize) + (ProcessSignalingLowSpace << ShiftForWord), currentProc);
		}
		/* begin forceInterruptCheck */
		interruptCheckCounter = -1000;
		nextPollTick = 0;
	}
	if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) < (((usqInt) ((byteSize + ((hdrSize - 1) * BytesPerWord)) + BaseHeaderSize)))) {
		error("out of memory");
	}
	newFreeSize = ((longAt(freeBlock)) & AllButTypeMask) - (byteSize + ((hdrSize - 1) * BytesPerWord));
	newChunk = freeBlock;
	freeBlock += byteSize + ((hdrSize - 1) * BytesPerWord);
	/* begin setSizeOfFree:to: */
	longAtput(freeBlock, (newFreeSize & AllButTypeMask) | HeaderTypeFree);
	allocationCount += 1;
	newObj1 = newChunk;
	if (hdrSize > 1) {
		/* begin popRemappableOop */
		oop = remapBuffer[remapBufferCount];
		remapBufferCount -= 1;
		remappedClassOop = oop;
	}
	if (hdrSize == 3) {
		longAtput(newObj1, header3 | HeaderTypeSizeAndClass);
		longAtput(newObj1 + BytesPerWord, remappedClassOop | HeaderTypeSizeAndClass);
		longAtput(newObj1 + (BytesPerWord * 2), header1 | HeaderTypeSizeAndClass);
		newObj1 += BytesPerWord * 2;
	}
	if (hdrSize == 2) {
		longAtput(newObj1, remappedClassOop | HeaderTypeClass);
		longAtput(newObj1 + BytesPerWord, header1 | HeaderTypeClass);
		newObj1 += BytesPerWord;
	}
	if (hdrSize == 1) {
		longAtput(newObj1, header1 | HeaderTypeShort);
	}
	if (1) {
		end = newObj1 + byteSize;
		i = newObj1 + BytesPerWord;
		while (i < end) {
			longAtput(i, fillWord);
			i += BytesPerWord;
		}
	}
	if (DoAssertionChecks) {
		okayOop(newObj1);
		oopHasOkayClass(newObj1);
		if (!((objectAfter(newObj1)) == freeBlock)) {
			error("allocate bug: did not set header of new oop correctly");
		}
		if (!((objectAfter(freeBlock)) == endOfMemory)) {
			error("allocate bug: did not set header of freeBlock correctly");
		}
	}
	newObj = newObj1;
	return newObj;
}


/*	This version of instantiateClass assumes that the total object 
	size is under 256 bytes, the limit for objects with only one or 
	two header words. Note that the size is specified in bytes 
	and should include four bytes for the base header word. */

sqInt instantiateContextsizeInBytes(sqInt classPointer, sqInt sizeInBytes) {
    sqInt header1;
    sqInt hash;
    sqInt header2;
    sqInt hdrSize;
    usqInt end;
    sqInt remappedClassOop;
    usqInt i;
    sqInt newObj;
    sqInt oop;
    sqInt newFreeSize;
    sqInt enoughSpace;
    sqInt newChunk;
    usqInt minFree;
    sqInt sched;
    sqInt lastSavedProcess;
    sqInt currentProc;
    sqInt oop1;

	/* begin newObjectHash */
	lastHash = (13849 + (27181 * lastHash)) & 65535;
	hash = lastHash;
	header1 = ((hash << HashBitsOffset) & HashBits) | ((longAt((classPointer + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1);
	header2 = classPointer;
	if ((header1 & CompactClassMask) > 0) {

		/* are contexts compact? */

		hdrSize = 1;
	} else {
		hdrSize = 2;
	}
	if (sizeInBytes <= SizeMask) {

		/* OR size into header1.  Must not do this if size > SizeMask */

		header1 += sizeInBytes - (header1 & SizeMask);
	} else {

		/* Zero the size field of header1 if large */

		hdrSize = 3;
		header1 -= header1 & SizeMask;
	}
	flag("Dan");
	/* begin allocate:headerSize:h1:h2:h3:doFill:with: */
	if (hdrSize > 1) {
		/* begin pushRemappableOop: */
		remapBuffer[remapBufferCount += 1] = header2;
	}
	/* begin allocateChunk: */
	if (allocationCount >= allocationsBetweenGCs) {
		incrementalGC();
	}
	/* begin sufficientSpaceToAllocate: */
	minFree = (lowSpaceThreshold + (sizeInBytes + ((hdrSize - 1) * BytesPerWord))) + BaseHeaderSize;
	if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) >= (((usqInt) minFree))) {
		enoughSpace = 1;
		goto l1;
	} else {
		enoughSpace = sufficientSpaceAfterGC(minFree);
		goto l1;
	}
l1:	/* end sufficientSpaceToAllocate: */;
	if (!(enoughSpace)) {
		signalLowSpace = 1;
		lowSpaceThreshold = 0;
		/* begin saveProcessSignalingLowSpace */
		lastSavedProcess = longAt((specialObjectsOop + BaseHeaderSize) + (ProcessSignalingLowSpace << ShiftForWord));
		if (lastSavedProcess == nilObj) {
			sched = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord));
			currentProc = longAt((sched + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
			/* begin storePointer:ofObject:withValue: */
			oop1 = specialObjectsOop;
			if ((((usqInt) oop1)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(oop1, currentProc);
			}
			longAtput((oop1 + BaseHeaderSize) + (ProcessSignalingLowSpace << ShiftForWord), currentProc);
		}
		/* begin forceInterruptCheck */
		interruptCheckCounter = -1000;
		nextPollTick = 0;
	}
	if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) < (((usqInt) ((sizeInBytes + ((hdrSize - 1) * BytesPerWord)) + BaseHeaderSize)))) {
		error("out of memory");
	}
	newFreeSize = ((longAt(freeBlock)) & AllButTypeMask) - (sizeInBytes + ((hdrSize - 1) * BytesPerWord));
	newChunk = freeBlock;
	freeBlock += sizeInBytes + ((hdrSize - 1) * BytesPerWord);
	/* begin setSizeOfFree:to: */
	longAtput(freeBlock, (newFreeSize & AllButTypeMask) | HeaderTypeFree);
	allocationCount += 1;
	newObj = newChunk;
	if (hdrSize > 1) {
		/* begin popRemappableOop */
		oop = remapBuffer[remapBufferCount];
		remapBufferCount -= 1;
		remappedClassOop = oop;
	}
	if (hdrSize == 3) {
		longAtput(newObj, LargeContextSize | HeaderTypeSizeAndClass);
		longAtput(newObj + BytesPerWord, remappedClassOop | HeaderTypeSizeAndClass);
		longAtput(newObj + (BytesPerWord * 2), header1 | HeaderTypeSizeAndClass);
		newObj += BytesPerWord * 2;
	}
	if (hdrSize == 2) {
		longAtput(newObj, remappedClassOop | HeaderTypeClass);
		longAtput(newObj + BytesPerWord, header1 | HeaderTypeClass);
		newObj += BytesPerWord;
	}
	if (hdrSize == 1) {
		longAtput(newObj, header1 | HeaderTypeShort);
	}
	if (0) {
		end = newObj + sizeInBytes;
		i = newObj + BytesPerWord;
		while (i < end) {
			longAtput(i, 0);
			i += BytesPerWord;
		}
	}
	if (DoAssertionChecks) {
		okayOop(newObj);
		oopHasOkayClass(newObj);
		if (!((objectAfter(newObj)) == freeBlock)) {
			error("allocate bug: did not set header of new oop correctly");
		}
		if (!((objectAfter(freeBlock)) == endOfMemory)) {
			error("allocate bug: did not set header of freeBlock correctly");
		}
	}
	return newObj;
}


/*	This version of instantiateClass assumes that the total object 
	size is under 256 bytes, the limit for objects with only one or 
	two header words. Note that the size is specified in bytes 
	and should include 4 or 8 bytes for the base header word. 
	NOTE this code will only work for sizes that are an integral number of words
		(like not a 32-bit LargeInteger in a 64-bit system). 
	May cause a GC.
	Note that the created small object IS NOT FILLED and must be completed before returning it to Squeak. Since this call is used in routines that do jsut that we are safe. Break this rule and die. */

sqInt instantiateSmallClasssizeInBytes(sqInt classPointer, sqInt sizeInBytes) {
    sqInt header1;
    sqInt hash;
    sqInt header2;
    sqInt hdrSize;
    usqInt end;
    sqInt remappedClassOop;
    usqInt i;
    sqInt newObj;
    sqInt oop;
    sqInt newFreeSize;
    sqInt enoughSpace;
    sqInt newChunk;
    usqInt minFree;
    sqInt sched;
    sqInt lastSavedProcess;
    sqInt currentProc;
    sqInt oop1;

	if (!((sizeInBytes & (BytesPerWord - 1)) == 0)) {
		error("size must be integral number of words");
	}
	/* begin newObjectHash */
	lastHash = (13849 + (27181 * lastHash)) & 65535;
	hash = lastHash;
	header1 = ((hash << HashBitsOffset) & HashBits) | ((longAt((classPointer + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1);
	header2 = classPointer;
	if ((header1 & CompactClassMask) > 0) {

		/* is this a compact class */

		hdrSize = 1;
	} else {
		hdrSize = 2;
	}
	header1 += sizeInBytes - (header1 & (SizeMask + Size4Bit));
	/* begin allocate:headerSize:h1:h2:h3:doFill:with: */
	if (hdrSize > 1) {
		/* begin pushRemappableOop: */
		remapBuffer[remapBufferCount += 1] = header2;
	}
	/* begin allocateChunk: */
	if (allocationCount >= allocationsBetweenGCs) {
		incrementalGC();
	}
	/* begin sufficientSpaceToAllocate: */
	minFree = (lowSpaceThreshold + (sizeInBytes + ((hdrSize - 1) * BytesPerWord))) + BaseHeaderSize;
	if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) >= (((usqInt) minFree))) {
		enoughSpace = 1;
		goto l1;
	} else {
		enoughSpace = sufficientSpaceAfterGC(minFree);
		goto l1;
	}
l1:	/* end sufficientSpaceToAllocate: */;
	if (!(enoughSpace)) {
		signalLowSpace = 1;
		lowSpaceThreshold = 0;
		/* begin saveProcessSignalingLowSpace */
		lastSavedProcess = longAt((specialObjectsOop + BaseHeaderSize) + (ProcessSignalingLowSpace << ShiftForWord));
		if (lastSavedProcess == nilObj) {
			sched = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord));
			currentProc = longAt((sched + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
			/* begin storePointer:ofObject:withValue: */
			oop1 = specialObjectsOop;
			if ((((usqInt) oop1)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(oop1, currentProc);
			}
			longAtput((oop1 + BaseHeaderSize) + (ProcessSignalingLowSpace << ShiftForWord), currentProc);
		}
		/* begin forceInterruptCheck */
		interruptCheckCounter = -1000;
		nextPollTick = 0;
	}
	if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) < (((usqInt) ((sizeInBytes + ((hdrSize - 1) * BytesPerWord)) + BaseHeaderSize)))) {
		error("out of memory");
	}
	newFreeSize = ((longAt(freeBlock)) & AllButTypeMask) - (sizeInBytes + ((hdrSize - 1) * BytesPerWord));
	newChunk = freeBlock;
	freeBlock += sizeInBytes + ((hdrSize - 1) * BytesPerWord);
	/* begin setSizeOfFree:to: */
	longAtput(freeBlock, (newFreeSize & AllButTypeMask) | HeaderTypeFree);
	allocationCount += 1;
	newObj = newChunk;
	if (hdrSize > 1) {
		/* begin popRemappableOop */
		oop = remapBuffer[remapBufferCount];
		remapBufferCount -= 1;
		remappedClassOop = oop;
	}
	if (hdrSize == 3) {
		longAtput(newObj, 0 | HeaderTypeSizeAndClass);
		longAtput(newObj + BytesPerWord, remappedClassOop | HeaderTypeSizeAndClass);
		longAtput(newObj + (BytesPerWord * 2), header1 | HeaderTypeSizeAndClass);
		newObj += BytesPerWord * 2;
	}
	if (hdrSize == 2) {
		longAtput(newObj, remappedClassOop | HeaderTypeClass);
		longAtput(newObj + BytesPerWord, header1 | HeaderTypeClass);
		newObj += BytesPerWord;
	}
	if (hdrSize == 1) {
		longAtput(newObj, header1 | HeaderTypeShort);
	}
	if (0) {
		end = newObj + sizeInBytes;
		i = newObj + BytesPerWord;
		while (i < end) {
			longAtput(i, 0);
			i += BytesPerWord;
		}
	}
	if (DoAssertionChecks) {
		okayOop(newObj);
		oopHasOkayClass(newObj);
		if (!((objectAfter(newObj)) == freeBlock)) {
			error("allocate bug: did not set header of new oop correctly");
		}
		if (!((objectAfter(freeBlock)) == endOfMemory)) {
			error("allocate bug: did not set header of freeBlock correctly");
		}
	}
	return newObj;
}

sqInt integerObjectOf(sqInt value) {
	return (value << 1) + 1;
}


/*	Translator produces 'objectPointer >> 1' */

sqInt integerValueOf(sqInt objectPointer) {
	if ((objectPointer & 2147483648U) != 0) {
		return ((((usqInt) (objectPointer & 2147483647U)) >> 1) - 1073741823) - 1;
	} else {
		return ((usqInt) objectPointer) >> 1;
	}
}


/*	This is the main interpreter loop. It runs until all pending events
	have been served then returns to its caller. */

sqInt interpret(void) {
    sqInt localReturnValue;
    sqInt localReturnContext;
    sqInt localHomeContext;
    char* localSP;
    char* localIP;
    sqInt currentBytecode;
    sqInt activeProc;
    jmp_buf oldExit;
    sqInt result;
    sqInt myList;

	if (vmRecursionDepth > 0) {
		if (primitiveIndex == 0) {
			return 0;
		}
		if (!(callbackStart())) {
			return 0;
		}
	}

	/* record entry time when running as a browser plug-in */

	vmRecursionDepth += 1;
	browserPluginInitialiseIfNeeded();
	memcpy(oldExit, jmpBufExit, sizeof(jmp_buf));
	result = setjmp(jmpBufExit);
	if (!(result == 0)) {
		callbackEnd();
		memcpy(jmpBufExit, oldExit, sizeof(jmp_buf));
		return 0;
	}
	checkForInterrupts();
	activeProc = longAt(((longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord))) + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
	myList = longAt((activeProc + BaseHeaderSize) + (MyListIndex << ShiftForWord));
	if (!(myList == nilObj)) {
		callbackEnd();
		memcpy(jmpBufExit, oldExit, sizeof(jmp_buf));
		return 0;
	}
	/* begin internalizeIPandSP */
	localIP = pointerForOop(instructionPointer);
	localSP = pointerForOop(stackPointer);
	localHomeContext = theHomeContext;
	/* begin fetchNextBytecode */
	currentBytecode = byteAtPointer(++localIP);
	while (1) {
		switch (currentBytecode) {
		case 0:
			/* pushReceiverVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + ((0 & 15) << ShiftForWord)));
			}
;
			break;
		case 1:
			/* pushReceiverVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + ((1 & 15) << ShiftForWord)));
			}
;
			break;
		case 2:
			/* pushReceiverVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + ((2 & 15) << ShiftForWord)));
			}
;
			break;
		case 3:
			/* pushReceiverVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + ((3 & 15) << ShiftForWord)));
			}
;
			break;
		case 4:
			/* pushReceiverVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + ((4 & 15) << ShiftForWord)));
			}
;
			break;
		case 5:
			/* pushReceiverVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + ((5 & 15) << ShiftForWord)));
			}
;
			break;
		case 6:
			/* pushReceiverVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + ((6 & 15) << ShiftForWord)));
			}
;
			break;
		case 7:
			/* pushReceiverVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + ((7 & 15) << ShiftForWord)));
			}
;
			break;
		case 8:
			/* pushReceiverVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + ((8 & 15) << ShiftForWord)));
			}
;
			break;
		case 9:
			/* pushReceiverVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + ((9 & 15) << ShiftForWord)));
			}
;
			break;
		case 10:
			/* pushReceiverVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + ((10 & 15) << ShiftForWord)));
			}
;
			break;
		case 11:
			/* pushReceiverVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + ((11 & 15) << ShiftForWord)));
			}
;
			break;
		case 12:
			/* pushReceiverVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + ((12 & 15) << ShiftForWord)));
			}
;
			break;
		case 13:
			/* pushReceiverVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + ((13 & 15) << ShiftForWord)));
			}
;
			break;
		case 14:
			/* pushReceiverVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + ((14 & 15) << ShiftForWord)));
			}
;
			break;
		case 15:
			/* pushReceiverVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushReceiverVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + ((15 & 15) << ShiftForWord)));
			}
;
			break;
		case 16:
			/* pushTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((localHomeContext + BaseHeaderSize) + (((16 & 15) + TempFrameStart) << ShiftForWord)));
			}
;
			break;
		case 17:
			/* pushTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((localHomeContext + BaseHeaderSize) + (((17 & 15) + TempFrameStart) << ShiftForWord)));
			}
;
			break;
		case 18:
			/* pushTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((localHomeContext + BaseHeaderSize) + (((18 & 15) + TempFrameStart) << ShiftForWord)));
			}
;
			break;
		case 19:
			/* pushTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((localHomeContext + BaseHeaderSize) + (((19 & 15) + TempFrameStart) << ShiftForWord)));
			}
;
			break;
		case 20:
			/* pushTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((localHomeContext + BaseHeaderSize) + (((20 & 15) + TempFrameStart) << ShiftForWord)));
			}
;
			break;
		case 21:
			/* pushTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((localHomeContext + BaseHeaderSize) + (((21 & 15) + TempFrameStart) << ShiftForWord)));
			}
;
			break;
		case 22:
			/* pushTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((localHomeContext + BaseHeaderSize) + (((22 & 15) + TempFrameStart) << ShiftForWord)));
			}
;
			break;
		case 23:
			/* pushTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((localHomeContext + BaseHeaderSize) + (((23 & 15) + TempFrameStart) << ShiftForWord)));
			}
;
			break;
		case 24:
			/* pushTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((localHomeContext + BaseHeaderSize) + (((24 & 15) + TempFrameStart) << ShiftForWord)));
			}
;
			break;
		case 25:
			/* pushTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((localHomeContext + BaseHeaderSize) + (((25 & 15) + TempFrameStart) << ShiftForWord)));
			}
;
			break;
		case 26:
			/* pushTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((localHomeContext + BaseHeaderSize) + (((26 & 15) + TempFrameStart) << ShiftForWord)));
			}
;
			break;
		case 27:
			/* pushTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((localHomeContext + BaseHeaderSize) + (((27 & 15) + TempFrameStart) << ShiftForWord)));
			}
;
			break;
		case 28:
			/* pushTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((localHomeContext + BaseHeaderSize) + (((28 & 15) + TempFrameStart) << ShiftForWord)));
			}
;
			break;
		case 29:
			/* pushTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((localHomeContext + BaseHeaderSize) + (((29 & 15) + TempFrameStart) << ShiftForWord)));
			}
;
			break;
		case 30:
			/* pushTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((localHomeContext + BaseHeaderSize) + (((30 & 15) + TempFrameStart) << ShiftForWord)));
			}
;
			break;
		case 31:
			/* pushTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushTemporaryVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((localHomeContext + BaseHeaderSize) + (((31 & 15) + TempFrameStart) << ShiftForWord)));
			}
;
			break;
		case 32:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((32 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 33:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((33 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 34:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((34 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 35:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((35 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 36:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((36 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 37:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((37 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 38:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((38 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 39:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((39 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 40:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((40 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 41:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((41 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 42:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((42 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 43:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((43 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 44:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((44 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 45:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((45 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 46:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((46 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 47:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((47 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 48:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((48 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 49:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((49 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 50:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((50 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 51:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((51 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 52:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((52 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 53:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((53 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 54:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((54 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 55:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((55 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 56:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((56 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 57:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((57 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 58:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((58 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 59:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((59 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 60:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((60 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 61:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((61 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 62:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((62 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 63:
			/* pushLiteralConstantBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralConstant: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + (((63 & 31) + LiteralStart) << ShiftForWord)));
			}
;
			break;
		case 64:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((64 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 65:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((65 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 66:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((66 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 67:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((67 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 68:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((68 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 69:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((69 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 70:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((70 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 71:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((71 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 72:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((72 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 73:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((73 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 74:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((74 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 75:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((75 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 76:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((76 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 77:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((77 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 78:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((78 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 79:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((79 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 80:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((80 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 81:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((81 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 82:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((82 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 83:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((83 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 84:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((84 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 85:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((85 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 86:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((86 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 87:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((87 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 88:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((88 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 89:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((89 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 90:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((90 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 91:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((91 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 92:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((92 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 93:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((93 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 94:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((94 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 95:
			/* pushLiteralVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushLiteralVariable: */
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + (((95 & 31) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
			}
;
			break;
		case 96:
			/* storeAndPopReceiverVariableBytecode */
			{
				sqInt top;
				sqInt rcvr;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				rcvr = receiver;
				top = longAtPointer(localSP);
				if ((((usqInt) rcvr)) < (((usqInt) youngStart))) {
					possibleRootStoreIntovalue(rcvr, top);
				}
				longAtput((rcvr + BaseHeaderSize) + ((96 & 7) << ShiftForWord), top);
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 97:
			/* storeAndPopReceiverVariableBytecode */
			{
				sqInt top;
				sqInt rcvr;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				rcvr = receiver;
				top = longAtPointer(localSP);
				if ((((usqInt) rcvr)) < (((usqInt) youngStart))) {
					possibleRootStoreIntovalue(rcvr, top);
				}
				longAtput((rcvr + BaseHeaderSize) + ((97 & 7) << ShiftForWord), top);
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 98:
			/* storeAndPopReceiverVariableBytecode */
			{
				sqInt top;
				sqInt rcvr;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				rcvr = receiver;
				top = longAtPointer(localSP);
				if ((((usqInt) rcvr)) < (((usqInt) youngStart))) {
					possibleRootStoreIntovalue(rcvr, top);
				}
				longAtput((rcvr + BaseHeaderSize) + ((98 & 7) << ShiftForWord), top);
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 99:
			/* storeAndPopReceiverVariableBytecode */
			{
				sqInt top;
				sqInt rcvr;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				rcvr = receiver;
				top = longAtPointer(localSP);
				if ((((usqInt) rcvr)) < (((usqInt) youngStart))) {
					possibleRootStoreIntovalue(rcvr, top);
				}
				longAtput((rcvr + BaseHeaderSize) + ((99 & 7) << ShiftForWord), top);
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 100:
			/* storeAndPopReceiverVariableBytecode */
			{
				sqInt top;
				sqInt rcvr;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				rcvr = receiver;
				top = longAtPointer(localSP);
				if ((((usqInt) rcvr)) < (((usqInt) youngStart))) {
					possibleRootStoreIntovalue(rcvr, top);
				}
				longAtput((rcvr + BaseHeaderSize) + ((100 & 7) << ShiftForWord), top);
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 101:
			/* storeAndPopReceiverVariableBytecode */
			{
				sqInt top;
				sqInt rcvr;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				rcvr = receiver;
				top = longAtPointer(localSP);
				if ((((usqInt) rcvr)) < (((usqInt) youngStart))) {
					possibleRootStoreIntovalue(rcvr, top);
				}
				longAtput((rcvr + BaseHeaderSize) + ((101 & 7) << ShiftForWord), top);
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 102:
			/* storeAndPopReceiverVariableBytecode */
			{
				sqInt top;
				sqInt rcvr;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				rcvr = receiver;
				top = longAtPointer(localSP);
				if ((((usqInt) rcvr)) < (((usqInt) youngStart))) {
					possibleRootStoreIntovalue(rcvr, top);
				}
				longAtput((rcvr + BaseHeaderSize) + ((102 & 7) << ShiftForWord), top);
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 103:
			/* storeAndPopReceiverVariableBytecode */
			{
				sqInt top;
				sqInt rcvr;
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				rcvr = receiver;
				top = longAtPointer(localSP);
				if ((((usqInt) rcvr)) < (((usqInt) youngStart))) {
					possibleRootStoreIntovalue(rcvr, top);
				}
				longAtput((rcvr + BaseHeaderSize) + ((103 & 7) << ShiftForWord), top);
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 104:
			/* storeAndPopTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				longAtput((localHomeContext + BaseHeaderSize) + (((104 & 7) + TempFrameStart) << ShiftForWord), longAtPointer(localSP));
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 105:
			/* storeAndPopTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				longAtput((localHomeContext + BaseHeaderSize) + (((105 & 7) + TempFrameStart) << ShiftForWord), longAtPointer(localSP));
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 106:
			/* storeAndPopTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				longAtput((localHomeContext + BaseHeaderSize) + (((106 & 7) + TempFrameStart) << ShiftForWord), longAtPointer(localSP));
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 107:
			/* storeAndPopTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				longAtput((localHomeContext + BaseHeaderSize) + (((107 & 7) + TempFrameStart) << ShiftForWord), longAtPointer(localSP));
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 108:
			/* storeAndPopTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				longAtput((localHomeContext + BaseHeaderSize) + (((108 & 7) + TempFrameStart) << ShiftForWord), longAtPointer(localSP));
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 109:
			/* storeAndPopTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				longAtput((localHomeContext + BaseHeaderSize) + (((109 & 7) + TempFrameStart) << ShiftForWord), longAtPointer(localSP));
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 110:
			/* storeAndPopTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				longAtput((localHomeContext + BaseHeaderSize) + (((110 & 7) + TempFrameStart) << ShiftForWord), longAtPointer(localSP));
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 111:
			/* storeAndPopTemporaryVariableBytecode */
			{
				flag("requires currentBytecode to be expanded to a constant");
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				longAtput((localHomeContext + BaseHeaderSize) + (((111 & 7) + TempFrameStart) << ShiftForWord), longAtPointer(localSP));
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 112:
			/* pushReceiverBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, receiver);
			}
;
			break;
		case 113:
			/* pushConstantTrueBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, trueObj);
			}
;
			break;
		case 114:
			/* pushConstantFalseBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, falseObj);
			}
;
			break;
		case 115:
			/* pushConstantNilBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, nilObj);
			}
;
			break;
		case 116:
			/* pushConstantMinusOneBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, ConstMinusOne);
			}
;
			break;
		case 117:
			/* pushConstantZeroBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, ConstZero);
			}
;
			break;
		case 118:
			/* pushConstantOneBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, ConstOne);
			}
;
			break;
		case 119:
			/* pushConstantTwoBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, ConstTwo);
			}
;
			break;
		case 120:
			/* returnReceiver */
			{
				sqInt context;
				sqInt closureOrNil;
				/* begin sender */
				context = localHomeContext;
				while ((closureOrNil = longAt((context + BaseHeaderSize) + (ClosureIndex << ShiftForWord))) != nilObj) {
					context = longAt((closureOrNil + BaseHeaderSize) + (ClosureOuterContextIndex << ShiftForWord));
				}
				localReturnContext = longAt((context + BaseHeaderSize) + (SenderIndex << ShiftForWord));
				localReturnValue = receiver;
				/* goto commonReturn */
			}
;
			
		commonReturn:
			/* commonReturn */
			{
				sqInt localVal;
				sqInt nilOop;
				sqInt unwindMarked;
				sqInt thisCntx;
				sqInt contextOfCaller;
				sqInt localCntx;
				sqInt meth;
				sqInt header;
				sqInt pIndex;
				sqInt header1;
				sqInt primBits;
				sqInt tmp;
				/* inline:  */;
				nilOop = nilObj;
				thisCntx = activeContext;
				localCntx = localReturnContext;
				localVal = localReturnValue;
				if ((localCntx == nilOop) || ((longAt((localCntx + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord))) == nilOop)) {
					/* begin internalCannotReturn: */
					/* begin internalPush: */
					longAtPointerput(localSP += BytesPerWord, activeContext);
					/* begin internalPush: */
					longAtPointerput(localSP += BytesPerWord, localVal);
					messageSelector = longAt((specialObjectsOop + BaseHeaderSize) + (SelectorCannotReturn << ShiftForWord));
					argumentCount = 1;
					goto normalSend;
					goto l42;
				}
				thisCntx = longAt((activeContext + BaseHeaderSize) + (SenderIndex << ShiftForWord));
				while (!(thisCntx == localCntx)) {
					if (thisCntx == nilOop) {
						/* begin internalCannotReturn: */
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, activeContext);
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, localVal);
						messageSelector = longAt((specialObjectsOop + BaseHeaderSize) + (SelectorCannotReturn << ShiftForWord));
						argumentCount = 1;
						goto normalSend;
						goto l42;
					}
					/* begin isUnwindMarked: */
					header = longAt(thisCntx);
					if (!(((((usqInt) header) >> 12) & 31) == 14)) {
						unwindMarked = 0;
						goto l43;
					}
					meth = longAt((thisCntx + BaseHeaderSize) + (MethodIndex << ShiftForWord));
					/* begin primitiveIndexOf: */
					primBits = (((usqInt) (longAt((meth + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 1) & 268435967;
					pIndex = (primBits & 511) + (((usqInt) primBits) >> 19);
					unwindMarked = pIndex == 198;
				l43:	/* end isUnwindMarked: */;
					if (unwindMarked) {
						/* begin internalAboutToReturn:through: */
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, activeContext);
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, localVal);
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, thisCntx);
						messageSelector = longAt((specialObjectsOop + BaseHeaderSize) + (SelectorAboutToReturn << ShiftForWord));
						argumentCount = 2;
						goto normalSend;
						goto l42;
					}
					thisCntx = longAt((thisCntx + BaseHeaderSize) + (SenderIndex << ShiftForWord));
				}
				thisCntx = activeContext;
				while (!(thisCntx == localCntx)) {
					contextOfCaller = longAt((thisCntx + BaseHeaderSize) + (SenderIndex << ShiftForWord));
					longAtput((thisCntx + BaseHeaderSize) + (SenderIndex << ShiftForWord), nilOop);
					longAtput((thisCntx + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord), nilOop);
					if (reclaimableContextCount > 0) {
						reclaimableContextCount -= 1;
						/* begin recycleContextIfPossible: */
						if ((((usqInt) thisCntx)) >= (((usqInt) youngStart))) {
							header1 = longAt(thisCntx);
							if (((((usqInt) header1) >> 12) & 31) == 14) {
								if ((header1 & SizeMask) == SmallContextSize) {
									longAtput((thisCntx + BaseHeaderSize) + (0 << ShiftForWord), freeContexts);
									freeContexts = thisCntx;
								}
								if ((header1 & SizeMask) == LargeContextSize) {
									longAtput((thisCntx + BaseHeaderSize) + (0 << ShiftForWord), freeLargeContexts);
									freeLargeContexts = thisCntx;
								}
							}
						}
					}
					thisCntx = contextOfCaller;
				}
				activeContext = thisCntx;
				if ((((usqInt) thisCntx)) < (((usqInt) youngStart))) {
					beRootIfOld(thisCntx);
				}
				/* begin internalFetchContextRegisters: */
				tmp = longAt((thisCntx + BaseHeaderSize) + (MethodIndex << ShiftForWord));
				if ((tmp & 1)) {
					tmp = longAt((thisCntx + BaseHeaderSize) + (HomeIndex << ShiftForWord));
					if ((((usqInt) tmp)) < (((usqInt) youngStart))) {
						beRootIfOld(tmp);
					}
				} else {
					tmp = thisCntx;
				}
				localHomeContext = tmp;
				receiver = longAt((tmp + BaseHeaderSize) + (ReceiverIndex << ShiftForWord));
				method = longAt((tmp + BaseHeaderSize) + (MethodIndex << ShiftForWord));
				tmp = ((longAt((thisCntx + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord))) >> 1);
				localIP = pointerForOop(((method + tmp) + BaseHeaderSize) - 2);
				tmp = ((longAt((thisCntx + BaseHeaderSize) + (StackPointerIndex << ShiftForWord))) >> 1);
				localSP = pointerForOop((thisCntx + BaseHeaderSize) + (((TempFrameStart + tmp) - 1) * BytesPerWord));
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, localVal);
			}
;
		l42:	/* end case */;
			break;
		case 121:
			/* returnTrue */
			{
				sqInt context;
				sqInt closureOrNil;
				/* begin sender */
				context = localHomeContext;
				while ((closureOrNil = longAt((context + BaseHeaderSize) + (ClosureIndex << ShiftForWord))) != nilObj) {
					context = longAt((closureOrNil + BaseHeaderSize) + (ClosureOuterContextIndex << ShiftForWord));
				}
				localReturnContext = longAt((context + BaseHeaderSize) + (SenderIndex << ShiftForWord));
				localReturnValue = trueObj;
				goto commonReturn;
			}
;
			break;
		case 122:
			/* returnFalse */
			{
				sqInt context;
				sqInt closureOrNil;
				/* begin sender */
				context = localHomeContext;
				while ((closureOrNil = longAt((context + BaseHeaderSize) + (ClosureIndex << ShiftForWord))) != nilObj) {
					context = longAt((closureOrNil + BaseHeaderSize) + (ClosureOuterContextIndex << ShiftForWord));
				}
				localReturnContext = longAt((context + BaseHeaderSize) + (SenderIndex << ShiftForWord));
				localReturnValue = falseObj;
				goto commonReturn;
			}
;
			break;
		case 123:
			/* returnNil */
			{
				sqInt context;
				sqInt closureOrNil;
				/* begin sender */
				context = localHomeContext;
				while ((closureOrNil = longAt((context + BaseHeaderSize) + (ClosureIndex << ShiftForWord))) != nilObj) {
					context = longAt((closureOrNil + BaseHeaderSize) + (ClosureOuterContextIndex << ShiftForWord));
				}
				localReturnContext = longAt((context + BaseHeaderSize) + (SenderIndex << ShiftForWord));
				localReturnValue = nilObj;
				goto commonReturn;
			}
;
			break;
		case 124:
			/* returnTopFromMethod */
			{
				sqInt context;
				sqInt closureOrNil;
				/* begin sender */
				context = localHomeContext;
				while ((closureOrNil = longAt((context + BaseHeaderSize) + (ClosureIndex << ShiftForWord))) != nilObj) {
					context = longAt((closureOrNil + BaseHeaderSize) + (ClosureOuterContextIndex << ShiftForWord));
				}
				localReturnContext = longAt((context + BaseHeaderSize) + (SenderIndex << ShiftForWord));
				localReturnValue = longAtPointer(localSP);
				goto commonReturn;
			}
;
			break;
		case 125:
			/* returnTopFromBlock */
			{
				localReturnContext = longAt((activeContext + BaseHeaderSize) + (CallerIndex << ShiftForWord));
				localReturnValue = longAtPointer(localSP);
				goto commonReturn;
			}
;
			break;
		case 126:
		case 127:
			/* unknownBytecode */
			{
				error("Unknown bytecode");
			}
;
			break;
		case 128:
			/* extendedPushBytecode */
			{
				sqInt variableIndex;
				sqInt descriptor;
				sqInt variableType;
				descriptor = byteAtPointer(++localIP);
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				variableType = (((usqInt) descriptor) >> 6) & 3;
				variableIndex = descriptor & 63;
				if (variableType == 0) {
					/* begin pushReceiverVariable: */
					/* begin internalPush: */
					longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + (variableIndex << ShiftForWord)));
					goto l1;
				}
				if (variableType == 1) {
					/* begin pushTemporaryVariable: */
					/* begin internalPush: */
					longAtPointerput(localSP += BytesPerWord, longAt((localHomeContext + BaseHeaderSize) + ((variableIndex + TempFrameStart) << ShiftForWord)));
					goto l1;
				}
				if (variableType == 2) {
					/* begin pushLiteralConstant: */
					/* begin internalPush: */
					longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + ((variableIndex + LiteralStart) << ShiftForWord)));
					goto l1;
				}
				if (variableType == 3) {
					/* begin pushLiteralVariable: */
					/* begin internalPush: */
					longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + ((variableIndex + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
					goto l1;
				}
			}
;
		l1:	/* end case */;
			break;
		case 129:
			/* extendedStoreBytecode */
			{
				sqInt variableIndex;
				sqInt association;
				sqInt descriptor;
				sqInt variableType;
				sqInt oop;
				sqInt valuePointer;
				sqInt valuePointer1;
				descriptor = byteAtPointer(++localIP);
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				variableType = (((usqInt) descriptor) >> 6) & 3;
				variableIndex = descriptor & 63;
				if (variableType == 0) {
					/* begin storePointer:ofObject:withValue: */
					oop = receiver;
					valuePointer = longAtPointer(localSP);
					if ((((usqInt) oop)) < (((usqInt) youngStart))) {
						possibleRootStoreIntovalue(oop, valuePointer);
					}
					longAtput((oop + BaseHeaderSize) + (variableIndex << ShiftForWord), valuePointer);
					goto l2;
				}
				if (variableType == 1) {
					longAtput((localHomeContext + BaseHeaderSize) + ((variableIndex + TempFrameStart) << ShiftForWord), longAtPointer(localSP));
					goto l2;
				}
				if (variableType == 2) {
					error("illegal store");
				}
				if (variableType == 3) {
					association = longAt((method + BaseHeaderSize) + ((variableIndex + LiteralStart) << ShiftForWord));
					/* begin storePointer:ofObject:withValue: */
					valuePointer1 = longAtPointer(localSP);
					if ((((usqInt) association)) < (((usqInt) youngStart))) {
						possibleRootStoreIntovalue(association, valuePointer1);
					}
					longAtput((association + BaseHeaderSize) + (ValueIndex << ShiftForWord), valuePointer1);
					goto l2;
				}
			}
;
		l2:	/* end case */;
			break;
		case 130:
			/* extendedStoreAndPopBytecode */
			{
				sqInt variableIndex;
				sqInt association;
				sqInt descriptor;
				sqInt variableType;
				sqInt oop;
				sqInt valuePointer;
				sqInt valuePointer1;
				/* begin extendedStoreBytecode */
				descriptor = byteAtPointer(++localIP);
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				variableType = (((usqInt) descriptor) >> 6) & 3;
				variableIndex = descriptor & 63;
				if (variableType == 0) {
					/* begin storePointer:ofObject:withValue: */
					oop = receiver;
					valuePointer = longAtPointer(localSP);
					if ((((usqInt) oop)) < (((usqInt) youngStart))) {
						possibleRootStoreIntovalue(oop, valuePointer);
					}
					longAtput((oop + BaseHeaderSize) + (variableIndex << ShiftForWord), valuePointer);
					goto l3;
				}
				if (variableType == 1) {
					longAtput((localHomeContext + BaseHeaderSize) + ((variableIndex + TempFrameStart) << ShiftForWord), longAtPointer(localSP));
					goto l3;
				}
				if (variableType == 2) {
					error("illegal store");
				}
				if (variableType == 3) {
					association = longAt((method + BaseHeaderSize) + ((variableIndex + LiteralStart) << ShiftForWord));
					/* begin storePointer:ofObject:withValue: */
					valuePointer1 = longAtPointer(localSP);
					if ((((usqInt) association)) < (((usqInt) youngStart))) {
						possibleRootStoreIntovalue(association, valuePointer1);
					}
					longAtput((association + BaseHeaderSize) + (ValueIndex << ShiftForWord), valuePointer1);
					goto l3;
				}
			l3:	/* end extendedStoreBytecode */;
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 131:
			/* singleExtendedSendBytecode */
			{
				sqInt descriptor;
				descriptor = byteAtPointer(++localIP);
				messageSelector = longAt((method + BaseHeaderSize) + (((descriptor & 31) + LiteralStart) << ShiftForWord));
				argumentCount = ((usqInt) descriptor) >> 5;
				/* goto normalSend */
			}
;
			
		normalSend:
			/* normalSend */
			{
				sqInt rcvr;
				sqInt ccIndex;
				/* inline:  */;
				rcvr = longAtPointer(localSP - (argumentCount * BytesPerWord));
				/* begin fetchClassOf: */
				if ((rcvr & 1)) {
					lkupClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
					goto l44;
				}
				ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
				if (ccIndex == 0) {
					lkupClass = (longAt(rcvr - BaseHeaderSize)) & AllButTypeMask;
					goto l44;
				} else {
					lkupClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
					goto l44;
				}
			l44:	/* end fetchClassOf: */;
				receiverClass = lkupClass;
				/* goto commonSend */
			}
;
			
		commonSend:
			/* commonSend */
			{
				sqInt ok;
				sqInt hash;
				sqInt probe;
				sqInt delta;
				sqInt localPrimIndex;
				sqInt nArgs;
				sqInt oop;
				sqInt tempCount;
				sqInt where;
				sqInt needsLarge;
				sqInt i;
				sqInt argCount2;
				sqInt newContext;
				sqInt methodHeader;
				sqInt activeCntx;
				sqInt valuePointer;
				sqInt valuePointer1;
				sqInt tmp;
				/* begin internalFindNewMethod */
				/* begin lookupInMethodCacheSel:class: */
				hash = messageSelector ^ lkupClass;
				probe = hash & MethodCacheMask;
				if (((methodCache[probe + MethodCacheSelector]) == messageSelector) && ((methodCache[probe + MethodCacheClass]) == lkupClass)) {
					newMethod = methodCache[probe + MethodCacheMethod];
					primitiveIndex = methodCache[probe + MethodCachePrim];
					newNativeMethod = methodCache[probe + MethodCacheNative];
					primitiveFunctionPointer = ((void *) (methodCache[probe + MethodCachePrimFunction]));
					ok = 1;
					goto l45;
				}
				probe = (((usqInt) hash) >> 1) & MethodCacheMask;
				if (((methodCache[probe + MethodCacheSelector]) == messageSelector) && ((methodCache[probe + MethodCacheClass]) == lkupClass)) {
					newMethod = methodCache[probe + MethodCacheMethod];
					primitiveIndex = methodCache[probe + MethodCachePrim];
					newNativeMethod = methodCache[probe + MethodCacheNative];
					primitiveFunctionPointer = ((void *) (methodCache[probe + MethodCachePrimFunction]));
					ok = 1;
					goto l45;
				}
				probe = (((usqInt) hash) >> 2) & MethodCacheMask;
				if (((methodCache[probe + MethodCacheSelector]) == messageSelector) && ((methodCache[probe + MethodCacheClass]) == lkupClass)) {
					newMethod = methodCache[probe + MethodCacheMethod];
					primitiveIndex = methodCache[probe + MethodCachePrim];
					newNativeMethod = methodCache[probe + MethodCacheNative];
					primitiveFunctionPointer = ((void *) (methodCache[probe + MethodCachePrimFunction]));
					ok = 1;
					goto l45;
				}
				ok = 0;
			l45:	/* end lookupInMethodCacheSel:class: */;
				if (!(ok)) {
					/* begin externalizeIPandSP */
					instructionPointer = oopForPointer(localIP);
					stackPointer = oopForPointer(localSP);
					theHomeContext = localHomeContext;
					lookupMethodInClass(lkupClass);
					/* begin internalizeIPandSP */
					localIP = pointerForOop(instructionPointer);
					localSP = pointerForOop(stackPointer);
					localHomeContext = theHomeContext;
					addNewMethodToCache();
				}
				/* begin internalExecuteNewMethod */
				localPrimIndex = primitiveIndex;
				if (localPrimIndex > 0) {
					if ((localPrimIndex > 255) && (localPrimIndex < 520)) {
						if (localPrimIndex >= 264) {
							/* begin internalPop:thenPush: */
							oop = longAt(((longAtPointer(localSP)) + BaseHeaderSize) + ((localPrimIndex - 264) << ShiftForWord));
							longAtPointerput(localSP -= (1 - 1) * BytesPerWord, oop);
							goto l46;
						} else {
							if (localPrimIndex == 256) {
								goto l46;
							}
							if (localPrimIndex == 257) {
								/* begin internalPop:thenPush: */
								longAtPointerput(localSP -= (1 - 1) * BytesPerWord, trueObj);
								goto l46;
							}
							if (localPrimIndex == 258) {
								/* begin internalPop:thenPush: */
								longAtPointerput(localSP -= (1 - 1) * BytesPerWord, falseObj);
								goto l46;
							}
							if (localPrimIndex == 259) {
								/* begin internalPop:thenPush: */
								longAtPointerput(localSP -= (1 - 1) * BytesPerWord, nilObj);
								goto l46;
							}
							/* begin internalPop:thenPush: */
							longAtPointerput(localSP -= (1 - 1) * BytesPerWord, (((localPrimIndex - 261) << 1) | 1));
							goto l46;
						}
					} else {
						/* begin externalizeIPandSP */
						instructionPointer = oopForPointer(localIP);
						stackPointer = oopForPointer(localSP);
						theHomeContext = localHomeContext;
						if (DoBalanceChecks) {
							nArgs = argumentCount;
							delta = stackPointer - activeContext;
						}
						successFlag = 1;
						dispatchFunctionPointer(primitiveFunctionPointer);
						if (DoBalanceChecks) {
							if (!(balancedStackafterPrimitivewithArgs(delta, localPrimIndex, nArgs))) {
								printUnbalancedStack(localPrimIndex);
							}
						}
						/* begin internalizeIPandSP */
						localIP = pointerForOop(instructionPointer);
						localSP = pointerForOop(stackPointer);
						localHomeContext = theHomeContext;
						if (successFlag) {
							browserPluginReturnIfNeeded();
							goto l46;
						}
					}
				}
				/* begin internalActivateNewMethod */
				methodHeader = longAt((newMethod + BaseHeaderSize) + (HeaderIndex << ShiftForWord));
				needsLarge = methodHeader & LargeContextBit;
				if ((needsLarge == 0) && (freeContexts != NilContext)) {
					newContext = freeContexts;
					freeContexts = longAt((newContext + BaseHeaderSize) + (0 << ShiftForWord));
				} else {
					/* begin externalizeIPandSP */
					instructionPointer = oopForPointer(localIP);
					stackPointer = oopForPointer(localSP);
					theHomeContext = localHomeContext;
					newContext = allocateOrRecycleContext(needsLarge);
					/* begin internalizeIPandSP */
					localIP = pointerForOop(instructionPointer);
					localSP = pointerForOop(stackPointer);
					localHomeContext = theHomeContext;
				}
				tempCount = (((usqInt) methodHeader) >> 19) & 63;
				where = newContext + BaseHeaderSize;
				longAtput(where + (SenderIndex << ShiftForWord), activeContext);
				longAtput(where + (InstructionPointerIndex << ShiftForWord), (((((LiteralStart + ((((usqInt) methodHeader) >> 10) & 255)) * BytesPerWord) + 1) << 1) | 1));
				longAtput(where + (StackPointerIndex << ShiftForWord), ((tempCount << 1) | 1));
				longAtput(where + (MethodIndex << ShiftForWord), newMethod);
				longAtput(where + (ClosureIndex << ShiftForWord), nilObj);
				argCount2 = argumentCount;
				for (i = 0; i <= argCount2; i += 1) {
					longAtput(where + ((ReceiverIndex + i) << ShiftForWord), longAtPointer(localSP - ((argCount2 - i) * BytesPerWord)));
				}
				methodHeader = nilObj;
				for (i = ((argCount2 + 1) + ReceiverIndex); i <= (tempCount + ReceiverIndex); i += 1) {
					longAtput(where + (i << ShiftForWord), methodHeader);
				}
				/* begin internalPop: */
				localSP -= (argCount2 + 1) * BytesPerWord;
				reclaimableContextCount += 1;
				/* begin internalNewActiveContext: */
				/* begin internalStoreContextRegisters: */
				activeCntx = activeContext;
				/* begin storePointerUnchecked:ofObject:withValue: */
				valuePointer = (((((oopForPointer(localIP)) + 2) - (method + BaseHeaderSize)) << 1) | 1);
				longAtput((activeCntx + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord), valuePointer);
				/* begin storePointerUnchecked:ofObject:withValue: */
				valuePointer1 = (((((((usqInt) ((oopForPointer(localSP)) - (activeCntx + BaseHeaderSize))) >> ShiftForWord) - TempFrameStart) + 1) << 1) | 1);
				longAtput((activeCntx + BaseHeaderSize) + (StackPointerIndex << ShiftForWord), valuePointer1);
				if ((((usqInt) newContext)) < (((usqInt) youngStart))) {
					beRootIfOld(newContext);
				}
				activeContext = newContext;
				/* begin internalFetchContextRegisters: */
				tmp = longAt((newContext + BaseHeaderSize) + (MethodIndex << ShiftForWord));
				if ((tmp & 1)) {
					tmp = longAt((newContext + BaseHeaderSize) + (HomeIndex << ShiftForWord));
					if ((((usqInt) tmp)) < (((usqInt) youngStart))) {
						beRootIfOld(tmp);
					}
				} else {
					tmp = newContext;
				}
				localHomeContext = tmp;
				receiver = longAt((tmp + BaseHeaderSize) + (ReceiverIndex << ShiftForWord));
				method = longAt((tmp + BaseHeaderSize) + (MethodIndex << ShiftForWord));
				tmp = ((longAt((newContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord))) >> 1);
				localIP = pointerForOop(((method + tmp) + BaseHeaderSize) - 2);
				tmp = ((longAt((newContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord))) >> 1);
				localSP = pointerForOop((newContext + BaseHeaderSize) + (((TempFrameStart + tmp) - 1) * BytesPerWord));
				/* begin internalQuickCheckForInterrupts */
				if ((interruptCheckCounter -= 1) <= 0) {
					/* begin externalizeIPandSP */
					instructionPointer = oopForPointer(localIP);
					stackPointer = oopForPointer(localSP);
					theHomeContext = localHomeContext;
					checkForInterrupts();
					browserPluginReturnIfNeeded();
					/* begin internalizeIPandSP */
					localIP = pointerForOop(instructionPointer);
					localSP = pointerForOop(stackPointer);
					localHomeContext = theHomeContext;
				}
			l46:	/* end internalExecuteNewMethod */;
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
			}
;
			break;
		case 132:
			/* doubleExtendedDoAnythingBytecode */
			{
				sqInt top;
				sqInt opType;
				sqInt byte3;
				sqInt byte2;
				sqInt oop;
				sqInt oop1;
				sqInt oop2;
				byte2 = byteAtPointer(++localIP);
				byte3 = byteAtPointer(++localIP);
				opType = ((usqInt) byte2) >> 5;
				if (opType == 0) {
					messageSelector = longAt((method + BaseHeaderSize) + ((byte3 + LiteralStart) << ShiftForWord));
					argumentCount = byte2 & 31;
					goto normalSend;
					goto l4;
				}
				if (opType == 1) {
					messageSelector = longAt((method + BaseHeaderSize) + ((byte3 + LiteralStart) << ShiftForWord));
					argumentCount = byte2 & 31;
					goto commonSupersend;
					goto l4;
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				if (opType == 2) {
					/* begin pushReceiverVariable: */
					/* begin internalPush: */
					longAtPointerput(localSP += BytesPerWord, longAt((receiver + BaseHeaderSize) + (byte3 << ShiftForWord)));
					goto l4;
				}
				if (opType == 3) {
					/* begin pushLiteralConstant: */
					/* begin internalPush: */
					longAtPointerput(localSP += BytesPerWord, longAt((method + BaseHeaderSize) + ((byte3 + LiteralStart) << ShiftForWord)));
					goto l4;
				}
				if (opType == 4) {
					/* begin pushLiteralVariable: */
					/* begin internalPush: */
					longAtPointerput(localSP += BytesPerWord, longAt(((longAt((method + BaseHeaderSize) + ((byte3 + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord)));
					goto l4;
				}
				if (opType == 5) {
					top = longAtPointer(localSP);
					/* begin storePointer:ofObject:withValue: */
					oop = receiver;
					if ((((usqInt) oop)) < (((usqInt) youngStart))) {
						possibleRootStoreIntovalue(oop, top);
					}
					longAtput((oop + BaseHeaderSize) + (byte3 << ShiftForWord), top);
					goto l4;
				}
				if (opType == 6) {
					top = longAtPointer(localSP);
					/* begin internalPop: */
					localSP -= 1 * BytesPerWord;
					/* begin storePointer:ofObject:withValue: */
					oop1 = receiver;
					if ((((usqInt) oop1)) < (((usqInt) youngStart))) {
						possibleRootStoreIntovalue(oop1, top);
					}
					longAtput((oop1 + BaseHeaderSize) + (byte3 << ShiftForWord), top);
					goto l4;
				}
				if (opType == 7) {
					top = longAtPointer(localSP);
					/* begin storePointer:ofObject:withValue: */
					oop2 = longAt((method + BaseHeaderSize) + ((byte3 + LiteralStart) << ShiftForWord));
					if ((((usqInt) oop2)) < (((usqInt) youngStart))) {
						possibleRootStoreIntovalue(oop2, top);
					}
					longAtput((oop2 + BaseHeaderSize) + (ValueIndex << ShiftForWord), top);
					goto l4;
				}
			}
;
		l4:	/* end case */;
			break;
		case 133:
			/* singleExtendedSuperBytecode */
			{
				sqInt descriptor;
				descriptor = byteAtPointer(++localIP);
				messageSelector = longAt((method + BaseHeaderSize) + (((descriptor & 31) + LiteralStart) << ShiftForWord));
				argumentCount = ((usqInt) descriptor) >> 5;
				/* goto commonSupersend */
			}
;
			
		commonSupersend:
			/* superclassSend */
			{
				sqInt rcvr;
				sqInt classPointer;
				sqInt ccIndex;
				/* inline:  */;
				/* begin superclassOf: */
				classPointer = longAt(((longAt((method + BaseHeaderSize) + (((((((usqInt) (longAt((method + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 10) & 255) - 1) + LiteralStart) << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord));
				lkupClass = longAt((classPointer + BaseHeaderSize) + (SuperclassIndex << ShiftForWord));
				rcvr = longAtPointer(localSP - (argumentCount * BytesPerWord));
				/* begin fetchClassOf: */
				if ((rcvr & 1)) {
					receiverClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
					goto l47;
				}
				ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
				if (ccIndex == 0) {
					receiverClass = (longAt(rcvr - BaseHeaderSize)) & AllButTypeMask;
					goto l47;
				} else {
					receiverClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
					goto l47;
				}
			l47:	/* end fetchClassOf: */;
				goto commonSend;
			}
;
			break;
		case 134:
			/* secondExtendedSendBytecode */
			{
				sqInt descriptor;
				descriptor = byteAtPointer(++localIP);
				messageSelector = longAt((method + BaseHeaderSize) + (((descriptor & 63) + LiteralStart) << ShiftForWord));
				argumentCount = ((usqInt) descriptor) >> 6;
				goto normalSend;
			}
;
			break;
		case 135:
			/* popStackBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 136:
			/* duplicateTopBytecode */
			{
				sqInt object;
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				object = longAtPointer(localSP);
				longAtPointerput(localSP += BytesPerWord, object);
			}
;
			break;
		case 137:
			/* pushActiveContextBytecode */
			{
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				reclaimableContextCount = 0;
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, activeContext);
			}
;
			break;
		case 138:
			/* pushNewArrayBytecode */
			{
				sqInt i;
				sqInt size;
				sqInt array;
				sqInt popValues;
				size = byteAtPointer(++localIP);
				popValues = size > 127;
				size = size & 127;
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin externalizeIPandSP */
				instructionPointer = oopForPointer(localIP);
				stackPointer = oopForPointer(localSP);
				theHomeContext = localHomeContext;
				array = instantiateClassindexableSize(longAt((specialObjectsOop + BaseHeaderSize) + (ClassArray << ShiftForWord)), size);
				/* begin internalizeIPandSP */
				localIP = pointerForOop(instructionPointer);
				localSP = pointerForOop(stackPointer);
				localHomeContext = theHomeContext;
				if (popValues) {
					for (i = 0; i <= (size - 1); i += 1) {
						longAtput((array + BaseHeaderSize) + (i << ShiftForWord), longAtPointer(localSP - (((size - i) - 1) * BytesPerWord)));
					}
					/* begin internalPop: */
					localSP -= size * BytesPerWord;
				}
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, array);
			}
;
			break;
		case 139:
			/* unknownBytecode */
			{
				error("Unknown bytecode");
			}
;
			break;
		case 140:
			/* pushRemoteTempLongBytecode */
			{
				sqInt tempVectorIndex;
				sqInt remoteTempIndex;
				sqInt tempVector;
				remoteTempIndex = byteAtPointer(++localIP);
				tempVectorIndex = byteAtPointer(++localIP);
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin pushRemoteTemp:inVectorAt: */
				tempVector = longAt((localHomeContext + BaseHeaderSize) + ((tempVectorIndex + TempFrameStart) << ShiftForWord));
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, longAt((tempVector + BaseHeaderSize) + (remoteTempIndex << ShiftForWord)));
			}
;
			break;
		case 141:
			/* storeRemoteTempLongBytecode */
			{
				sqInt tempVectorIndex;
				sqInt remoteTempIndex;
				sqInt tempVector;
				sqInt valuePointer;
				remoteTempIndex = byteAtPointer(++localIP);
				tempVectorIndex = byteAtPointer(++localIP);
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin storeRemoteTemp:inVectorAt: */
				tempVector = longAt((localHomeContext + BaseHeaderSize) + ((tempVectorIndex + TempFrameStart) << ShiftForWord));
				/* begin storePointer:ofObject:withValue: */
				valuePointer = longAtPointer(localSP);
				if ((((usqInt) tempVector)) < (((usqInt) youngStart))) {
					possibleRootStoreIntovalue(tempVector, valuePointer);
				}
				longAtput((tempVector + BaseHeaderSize) + (remoteTempIndex << ShiftForWord), valuePointer);
			}
;
			break;
		case 142:
			/* storeAndPopRemoteTempLongBytecode */
			{
				sqInt tempVectorIndex;
				sqInt remoteTempIndex;
				sqInt tempVector;
				sqInt valuePointer;
				/* begin storeRemoteTempLongBytecode */
				remoteTempIndex = byteAtPointer(++localIP);
				tempVectorIndex = byteAtPointer(++localIP);
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin storeRemoteTemp:inVectorAt: */
				tempVector = longAt((localHomeContext + BaseHeaderSize) + ((tempVectorIndex + TempFrameStart) << ShiftForWord));
				/* begin storePointer:ofObject:withValue: */
				valuePointer = longAtPointer(localSP);
				if ((((usqInt) tempVector)) < (((usqInt) youngStart))) {
					possibleRootStoreIntovalue(tempVector, valuePointer);
				}
				longAtput((tempVector + BaseHeaderSize) + (remoteTempIndex << ShiftForWord), valuePointer);
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			}
;
			break;
		case 143:
			/* pushClosureCopyCopiedValuesBytecode */
			{
				sqInt numArgsNumCopied;
				sqInt numCopied;
				sqInt i;
				sqInt numArgs;
				sqInt newClosure;
				sqInt blockSize;
				sqInt initialIP;
				sqInt newClosure1;
				if (BytesPerWord == 4) {
					imageFormatVersionNumber = 6504;
				} else {
					imageFormatVersionNumber = 68002;
				}
				numArgsNumCopied = byteAtPointer(++localIP);
				numArgs = numArgsNumCopied & 15;
				numCopied = ((usqInt) numArgsNumCopied >> 4);
				blockSize = (byteAtPointer(++localIP)) << 8;
				blockSize += byteAtPointer(++localIP);
				/* begin externalizeIPandSP */
				instructionPointer = oopForPointer(localIP);
				stackPointer = oopForPointer(localSP);
				theHomeContext = localHomeContext;
				/* begin closureNumArgs:instructionPointer:numCopiedValues: */
				initialIP = ((oopForPointer(localIP)) + 2) - (method + BaseHeaderSize);
				newClosure1 = instantiateSmallClasssizeInBytes(longAt((specialObjectsOop + BaseHeaderSize) + (ClassBlockClosure << ShiftForWord)), (BytesPerWord * (ClosureFirstCopiedValueIndex + numCopied)) + BaseHeaderSize);
				longAtput((newClosure1 + BaseHeaderSize) + (ClosureStartPCIndex << ShiftForWord), ((initialIP << 1) | 1));
				longAtput((newClosure1 + BaseHeaderSize) + (ClosureNumArgsIndex << ShiftForWord), ((numArgs << 1) | 1));
				newClosure = newClosure1;
				/* begin internalizeIPandSP */
				localIP = pointerForOop(instructionPointer);
				localSP = pointerForOop(stackPointer);
				localHomeContext = theHomeContext;
				longAtput((newClosure + BaseHeaderSize) + (ClosureOuterContextIndex << ShiftForWord), activeContext);
				reclaimableContextCount = 0;
				if (numCopied > 0) {
					for (i = 0; i <= (numCopied - 1); i += 1) {
						longAtput((newClosure + BaseHeaderSize) + ((i + ClosureFirstCopiedValueIndex) << ShiftForWord), longAtPointer(localSP - (((numCopied - i) - 1) * BytesPerWord)));
					}
					/* begin internalPop: */
					localSP -= numCopied * BytesPerWord;
				}
				localIP += blockSize;
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				/* begin internalPush: */
				longAtPointerput(localSP += BytesPerWord, newClosure);
			}
;
			break;
		case 144:
			/* shortUnconditionalJump */
			{
				sqInt offset;
				/* begin jump: */
				offset = (144 & 7) + 1;
				localIP = (localIP + offset) + 1;
				currentBytecode = byteAtPointer(localIP);
			}
;
			break;
		case 145:
			/* shortUnconditionalJump */
			{
				sqInt offset;
				/* begin jump: */
				offset = (145 & 7) + 1;
				localIP = (localIP + offset) + 1;
				currentBytecode = byteAtPointer(localIP);
			}
;
			break;
		case 146:
			/* shortUnconditionalJump */
			{
				sqInt offset;
				/* begin jump: */
				offset = (146 & 7) + 1;
				localIP = (localIP + offset) + 1;
				currentBytecode = byteAtPointer(localIP);
			}
;
			break;
		case 147:
			/* shortUnconditionalJump */
			{
				sqInt offset;
				/* begin jump: */
				offset = (147 & 7) + 1;
				localIP = (localIP + offset) + 1;
				currentBytecode = byteAtPointer(localIP);
			}
;
			break;
		case 148:
			/* shortUnconditionalJump */
			{
				sqInt offset;
				/* begin jump: */
				offset = (148 & 7) + 1;
				localIP = (localIP + offset) + 1;
				currentBytecode = byteAtPointer(localIP);
			}
;
			break;
		case 149:
			/* shortUnconditionalJump */
			{
				sqInt offset;
				/* begin jump: */
				offset = (149 & 7) + 1;
				localIP = (localIP + offset) + 1;
				currentBytecode = byteAtPointer(localIP);
			}
;
			break;
		case 150:
			/* shortUnconditionalJump */
			{
				sqInt offset;
				/* begin jump: */
				offset = (150 & 7) + 1;
				localIP = (localIP + offset) + 1;
				currentBytecode = byteAtPointer(localIP);
			}
;
			break;
		case 151:
			/* shortUnconditionalJump */
			{
				sqInt offset;
				/* begin jump: */
				offset = (151 & 7) + 1;
				localIP = (localIP + offset) + 1;
				currentBytecode = byteAtPointer(localIP);
			}
;
			break;
		case 152:
		case 153:
		case 154:
		case 155:
		case 156:
		case 157:
		case 158:
		case 159:
			/* shortConditionalJump */
			{
				sqInt offset;
				sqInt boolean;
				/* begin jumplfFalseBy: */
				offset = (currentBytecode & 7) + 1;
				boolean = longAtPointer(localSP);
				if (boolean == falseObj) {
					/* begin jump: */
					localIP = (localIP + offset) + 1;
					currentBytecode = byteAtPointer(localIP);
				} else {
					if (!(boolean == trueObj)) {
						messageSelector = longAt((specialObjectsOop + BaseHeaderSize) + (SelectorMustBeBoolean << ShiftForWord));
						argumentCount = 0;
						goto normalSend;
						goto l5;
					}
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
				}
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			l5:	/* end jumplfFalseBy: */;
			}
;
			break;
		case 160:
		case 161:
		case 162:
		case 163:
		case 164:
		case 165:
		case 166:
		case 167:
			/* longUnconditionalJump */
			{
				sqInt offset;
				offset = (((currentBytecode & 7) - 4) * 256) + (byteAtPointer(++localIP));
				localIP += offset;
				if (offset < 0) {
					/* begin internalQuickCheckForInterrupts */
					if ((interruptCheckCounter -= 1) <= 0) {
						/* begin externalizeIPandSP */
						instructionPointer = oopForPointer(localIP);
						stackPointer = oopForPointer(localSP);
						theHomeContext = localHomeContext;
						checkForInterrupts();
						browserPluginReturnIfNeeded();
						/* begin internalizeIPandSP */
						localIP = pointerForOop(instructionPointer);
						localSP = pointerForOop(stackPointer);
						localHomeContext = theHomeContext;
					}
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
			}
;
			break;
		case 168:
		case 169:
		case 170:
		case 171:
			/* longJumpIfTrue */
			{
				sqInt offset;
				sqInt boolean;
				/* begin jumplfTrueBy: */
				offset = ((currentBytecode & 3) * 256) + (byteAtPointer(++localIP));
				boolean = longAtPointer(localSP);
				if (boolean == trueObj) {
					/* begin jump: */
					localIP = (localIP + offset) + 1;
					currentBytecode = byteAtPointer(localIP);
				} else {
					if (!(boolean == falseObj)) {
						messageSelector = longAt((specialObjectsOop + BaseHeaderSize) + (SelectorMustBeBoolean << ShiftForWord));
						argumentCount = 0;
						goto normalSend;
						goto l6;
					}
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
				}
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			l6:	/* end jumplfTrueBy: */;
			}
;
			break;
		case 172:
		case 173:
		case 174:
		case 175:
			/* longJumpIfFalse */
			{
				sqInt offset;
				sqInt boolean;
				/* begin jumplfFalseBy: */
				offset = ((currentBytecode & 3) * 256) + (byteAtPointer(++localIP));
				boolean = longAtPointer(localSP);
				if (boolean == falseObj) {
					/* begin jump: */
					localIP = (localIP + offset) + 1;
					currentBytecode = byteAtPointer(localIP);
				} else {
					if (!(boolean == trueObj)) {
						messageSelector = longAt((specialObjectsOop + BaseHeaderSize) + (SelectorMustBeBoolean << ShiftForWord));
						argumentCount = 0;
						goto normalSend;
						goto l7;
					}
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
				}
				/* begin internalPop: */
				localSP -= 1 * BytesPerWord;
			l7:	/* end jumplfFalseBy: */;
			}
;
			break;
		case 176:
			/* bytecodePrimAdd */
			{
				sqInt arg;
				sqInt result;
				sqInt rcvr;
				rcvr = longAtPointer(localSP - (1 * BytesPerWord));
				arg = longAtPointer(localSP - (0 * BytesPerWord));
				if (((rcvr & arg) & 1) != 0) {
					result = ((rcvr >> 1)) + ((arg >> 1));
					if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
						(((((int) result)) ^ ((((int) result)) << 1)) >= 0)
# else
						((result >= -1073741824) && (result <= 1073741823))
# endif  // SQ_HOST32
					) {
						/* begin internalPop:thenPush: */
						longAtPointerput(localSP -= (2 - 1) * BytesPerWord, ((result << 1) | 1));
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l8;
					}
				} else {
					successFlag = 1;
					/* begin externalizeIPandSP */
					instructionPointer = oopForPointer(localIP);
					stackPointer = oopForPointer(localSP);
					theHomeContext = localHomeContext;
					primitiveFloatAddtoArg(rcvr, arg);
					/* begin internalizeIPandSP */
					localIP = pointerForOop(instructionPointer);
					localSP = pointerForOop(stackPointer);
					localHomeContext = theHomeContext;
					if (successFlag) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l8;
					}
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((0 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
		l8:	/* end case */;
			break;
		case 177:
			/* bytecodePrimSubtract */
			{
				sqInt arg;
				sqInt result;
				sqInt rcvr;
				rcvr = longAtPointer(localSP - (1 * BytesPerWord));
				arg = longAtPointer(localSP - (0 * BytesPerWord));
				if (((rcvr & arg) & 1) != 0) {
					result = ((rcvr >> 1)) - ((arg >> 1));
					if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
						(((((int) result)) ^ ((((int) result)) << 1)) >= 0)
# else
						((result >= -1073741824) && (result <= 1073741823))
# endif  // SQ_HOST32
					) {
						/* begin internalPop:thenPush: */
						longAtPointerput(localSP -= (2 - 1) * BytesPerWord, ((result << 1) | 1));
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l9;
					}
				} else {
					successFlag = 1;
					/* begin externalizeIPandSP */
					instructionPointer = oopForPointer(localIP);
					stackPointer = oopForPointer(localSP);
					theHomeContext = localHomeContext;
					primitiveFloatSubtractfromArg(rcvr, arg);
					/* begin internalizeIPandSP */
					localIP = pointerForOop(instructionPointer);
					localSP = pointerForOop(stackPointer);
					localHomeContext = theHomeContext;
					if (successFlag) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l9;
					}
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((1 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
		l9:	/* end case */;
			break;
		case 178:
			/* bytecodePrimLessThan */
			{
				sqInt arg;
				sqInt rcvr;
				sqInt aBool;
				sqInt bytecode;
				sqInt offset;
				sqInt bytecode1;
				sqInt offset1;
				sqInt bytecode2;
				sqInt offset2;
				rcvr = longAtPointer(localSP - (1 * BytesPerWord));
				arg = longAtPointer(localSP - (0 * BytesPerWord));
				if (((rcvr & arg) & 1) != 0) {
					;
					/* begin booleanCheat: */
					bytecode1 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * BytesPerWord;
					if ((bytecode1 < 160) && (bytecode1 > 151)) {
						if (rcvr < arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l10;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode1 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l10;
						}
					}
					if (bytecode1 == 172) {
						offset1 = byteAtPointer(++localIP);
						if (rcvr < arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l10;
						} else {
							/* begin jump: */
							localIP = (localIP + offset1) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l10;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (rcvr < arg) {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, falseObj);
					}
					goto l10;
				}
				successFlag = 1;
				aBool = primitiveFloatLessthanArg(rcvr, arg);
				if (successFlag) {
					/* begin booleanCheat: */
					bytecode2 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * BytesPerWord;
					if ((bytecode2 < 160) && (bytecode2 > 151)) {
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l10;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode2 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l10;
						}
					}
					if (bytecode2 == 172) {
						offset2 = byteAtPointer(++localIP);
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l10;
						} else {
							/* begin jump: */
							localIP = (localIP + offset2) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l10;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (aBool) {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, falseObj);
					}
					goto l10;
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((2 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
		l10:	/* end case */;
			break;
		case 179:
			/* bytecodePrimGreaterThan */
			{
				sqInt arg;
				sqInt rcvr;
				sqInt aBool;
				sqInt bytecode;
				sqInt offset;
				sqInt bytecode1;
				sqInt offset1;
				sqInt bytecode2;
				sqInt offset2;
				rcvr = longAtPointer(localSP - (1 * BytesPerWord));
				arg = longAtPointer(localSP - (0 * BytesPerWord));
				if (((rcvr & arg) & 1) != 0) {
					;
					/* begin booleanCheat: */
					bytecode1 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * BytesPerWord;
					if ((bytecode1 < 160) && (bytecode1 > 151)) {
						if (rcvr > arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l11;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode1 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l11;
						}
					}
					if (bytecode1 == 172) {
						offset1 = byteAtPointer(++localIP);
						if (rcvr > arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l11;
						} else {
							/* begin jump: */
							localIP = (localIP + offset1) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l11;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (rcvr > arg) {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, falseObj);
					}
					goto l11;
				}
				successFlag = 1;
				aBool = primitiveFloatGreaterthanArg(rcvr, arg);
				if (successFlag) {
					/* begin booleanCheat: */
					bytecode2 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * BytesPerWord;
					if ((bytecode2 < 160) && (bytecode2 > 151)) {
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l11;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode2 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l11;
						}
					}
					if (bytecode2 == 172) {
						offset2 = byteAtPointer(++localIP);
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l11;
						} else {
							/* begin jump: */
							localIP = (localIP + offset2) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l11;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (aBool) {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, falseObj);
					}
					goto l11;
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((3 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
		l11:	/* end case */;
			break;
		case 180:
			/* bytecodePrimLessOrEqual */
			{
				sqInt arg;
				sqInt rcvr;
				sqInt aBool;
				sqInt bytecode;
				sqInt offset;
				sqInt bytecode1;
				sqInt offset1;
				sqInt bytecode2;
				sqInt offset2;
				rcvr = longAtPointer(localSP - (1 * BytesPerWord));
				arg = longAtPointer(localSP - (0 * BytesPerWord));
				if (((rcvr & arg) & 1) != 0) {
					;
					/* begin booleanCheat: */
					bytecode1 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * BytesPerWord;
					if ((bytecode1 < 160) && (bytecode1 > 151)) {
						if (rcvr <= arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l12;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode1 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l12;
						}
					}
					if (bytecode1 == 172) {
						offset1 = byteAtPointer(++localIP);
						if (rcvr <= arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l12;
						} else {
							/* begin jump: */
							localIP = (localIP + offset1) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l12;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (rcvr <= arg) {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, falseObj);
					}
					goto l12;
				}
				successFlag = 1;
				aBool = primitiveFloatLessOrEqualtoArg(rcvr, arg);
				if (successFlag) {
					/* begin booleanCheat: */
					bytecode2 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * BytesPerWord;
					if ((bytecode2 < 160) && (bytecode2 > 151)) {
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l12;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode2 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l12;
						}
					}
					if (bytecode2 == 172) {
						offset2 = byteAtPointer(++localIP);
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l12;
						} else {
							/* begin jump: */
							localIP = (localIP + offset2) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l12;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (aBool) {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, falseObj);
					}
					goto l12;
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((4 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
		l12:	/* end case */;
			break;
		case 181:
			/* bytecodePrimGreaterOrEqual */
			{
				sqInt arg;
				sqInt rcvr;
				sqInt aBool;
				sqInt bytecode;
				sqInt offset;
				sqInt bytecode1;
				sqInt offset1;
				sqInt bytecode2;
				sqInt offset2;
				rcvr = longAtPointer(localSP - (1 * BytesPerWord));
				arg = longAtPointer(localSP - (0 * BytesPerWord));
				if (((rcvr & arg) & 1) != 0) {
					;
					/* begin booleanCheat: */
					bytecode1 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * BytesPerWord;
					if ((bytecode1 < 160) && (bytecode1 > 151)) {
						if (rcvr >= arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l13;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode1 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l13;
						}
					}
					if (bytecode1 == 172) {
						offset1 = byteAtPointer(++localIP);
						if (rcvr >= arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l13;
						} else {
							/* begin jump: */
							localIP = (localIP + offset1) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l13;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (rcvr >= arg) {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, falseObj);
					}
					goto l13;
				}
				successFlag = 1;
				aBool = primitiveFloatGreaterOrEqualtoArg(rcvr, arg);
				if (successFlag) {
					/* begin booleanCheat: */
					bytecode2 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * BytesPerWord;
					if ((bytecode2 < 160) && (bytecode2 > 151)) {
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l13;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode2 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l13;
						}
					}
					if (bytecode2 == 172) {
						offset2 = byteAtPointer(++localIP);
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l13;
						} else {
							/* begin jump: */
							localIP = (localIP + offset2) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l13;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (aBool) {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, falseObj);
					}
					goto l13;
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((5 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
		l13:	/* end case */;
			break;
		case 182:
			/* bytecodePrimEqual */
			{
				sqInt arg;
				sqInt rcvr;
				sqInt aBool;
				sqInt bytecode;
				sqInt offset;
				sqInt bytecode1;
				sqInt offset1;
				rcvr = longAtPointer(localSP - (1 * BytesPerWord));
				arg = longAtPointer(localSP - (0 * BytesPerWord));
				if (((rcvr & arg) & 1) != 0) {
					/* begin booleanCheat: */
					bytecode = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * BytesPerWord;
					if ((bytecode < 160) && (bytecode > 151)) {
						if (rcvr == arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l14;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l14;
						}
					}
					if (bytecode == 172) {
						offset = byteAtPointer(++localIP);
						if (rcvr == arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l14;
						} else {
							/* begin jump: */
							localIP = (localIP + offset) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l14;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (rcvr == arg) {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, falseObj);
					}
					goto l14;
				}
				successFlag = 1;
				aBool = primitiveFloatEqualtoArg(rcvr, arg);
				if (successFlag) {
					/* begin booleanCheat: */
					bytecode1 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * BytesPerWord;
					if ((bytecode1 < 160) && (bytecode1 > 151)) {
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l14;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode1 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l14;
						}
					}
					if (bytecode1 == 172) {
						offset1 = byteAtPointer(++localIP);
						if (aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l14;
						} else {
							/* begin jump: */
							localIP = (localIP + offset1) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l14;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (aBool) {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, falseObj);
					}
					goto l14;
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((6 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
		l14:	/* end case */;
			break;
		case 183:
			/* bytecodePrimNotEqual */
			{
				sqInt arg;
				sqInt rcvr;
				sqInt aBool;
				sqInt bytecode;
				sqInt offset;
				sqInt bytecode1;
				sqInt offset1;
				rcvr = longAtPointer(localSP - (1 * BytesPerWord));
				arg = longAtPointer(localSP - (0 * BytesPerWord));
				if (((rcvr & arg) & 1) != 0) {
					/* begin booleanCheat: */
					bytecode = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * BytesPerWord;
					if ((bytecode < 160) && (bytecode > 151)) {
						if (rcvr != arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l15;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l15;
						}
					}
					if (bytecode == 172) {
						offset = byteAtPointer(++localIP);
						if (rcvr != arg) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l15;
						} else {
							/* begin jump: */
							localIP = (localIP + offset) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l15;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (rcvr != arg) {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, falseObj);
					}
					goto l15;
				}
				successFlag = 1;
				aBool = primitiveFloatEqualtoArg(rcvr, arg);
				if (successFlag) {
					/* begin booleanCheat: */
					bytecode1 = byteAtPointer(++localIP);
					/* begin internalPop: */
					localSP -= 2 * BytesPerWord;
					if ((bytecode1 < 160) && (bytecode1 > 151)) {
						if (!aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l15;
						} else {
							/* begin jump: */
							localIP = (localIP + (bytecode1 - 151)) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l15;
						}
					}
					if (bytecode1 == 172) {
						offset1 = byteAtPointer(++localIP);
						if (!aBool) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l15;
						} else {
							/* begin jump: */
							localIP = (localIP + offset1) + 1;
							currentBytecode = byteAtPointer(localIP);
							goto l15;
						}
					}
					localIP -= 1;
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					if (!aBool) {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, trueObj);
					} else {
						/* begin internalPush: */
						longAtPointerput(localSP += BytesPerWord, falseObj);
					}
					goto l15;
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((7 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
		l15:	/* end case */;
			break;
		case 184:
			/* bytecodePrimMultiply */
			{
				sqInt arg;
				sqInt result;
				sqInt rcvr;
				rcvr = longAtPointer(localSP - (1 * BytesPerWord));
				arg = longAtPointer(localSP - (0 * BytesPerWord));
				if (((rcvr & arg) & 1) != 0) {
					rcvr = (rcvr >> 1);
					arg = (arg >> 1);
					result = rcvr * arg;
					if (((arg == 0) || ((result / arg) == rcvr)) && (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
	(((((int) result)) ^ ((((int) result)) << 1)) >= 0)
# else
	((result >= -1073741824) && (result <= 1073741823))
# endif  // SQ_HOST32
)) {
						/* begin internalPop:thenPush: */
						longAtPointerput(localSP -= (2 - 1) * BytesPerWord, ((result << 1) | 1));
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l16;
					}
				} else {
					successFlag = 1;
					/* begin externalizeIPandSP */
					instructionPointer = oopForPointer(localIP);
					stackPointer = oopForPointer(localSP);
					theHomeContext = localHomeContext;
					primitiveFloatMultiplybyArg(rcvr, arg);
					/* begin internalizeIPandSP */
					localIP = pointerForOop(instructionPointer);
					localSP = pointerForOop(stackPointer);
					localHomeContext = theHomeContext;
					if (successFlag) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l16;
					}
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((8 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
		l16:	/* end case */;
			break;
		case 185:
			/* bytecodePrimDivide */
			{
				sqInt arg;
				sqInt result;
				sqInt rcvr;
				rcvr = longAtPointer(localSP - (1 * BytesPerWord));
				arg = longAtPointer(localSP - (0 * BytesPerWord));
				if (((rcvr & arg) & 1) != 0) {
					rcvr = (rcvr >> 1);
					arg = (arg >> 1);
					if ((arg != 0) && ((rcvr % arg) == 0)) {
						result = rcvr / arg;
						if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
							(((((int) result)) ^ ((((int) result)) << 1)) >= 0)
# else
							((result >= -1073741824) && (result <= 1073741823))
# endif  // SQ_HOST32
						) {
							/* begin internalPop:thenPush: */
							longAtPointerput(localSP -= (2 - 1) * BytesPerWord, ((result << 1) | 1));
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							goto l17;
						}
					}
				} else {
					successFlag = 1;
					/* begin externalizeIPandSP */
					instructionPointer = oopForPointer(localIP);
					stackPointer = oopForPointer(localSP);
					theHomeContext = localHomeContext;
					primitiveFloatDividebyArg(rcvr, arg);
					/* begin internalizeIPandSP */
					localIP = pointerForOop(instructionPointer);
					localSP = pointerForOop(stackPointer);
					localHomeContext = theHomeContext;
					if (successFlag) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l17;
					}
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((9 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
		l17:	/* end case */;
			break;
		case 186:
			/* bytecodePrimMod */
			{
				sqInt mod;
				successFlag = 1;
				mod = doPrimitiveModby(longAtPointer(localSP - (1 * BytesPerWord)), longAtPointer(localSP - (0 * BytesPerWord)));
				if (successFlag) {
					/* begin internalPop:thenPush: */
					longAtPointerput(localSP -= (2 - 1) * BytesPerWord, ((mod << 1) | 1));
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					goto l18;
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((10 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
		l18:	/* end case */;
			break;
		case 187:
			/* bytecodePrimMakePoint */
			{
				sqInt argument;
				sqInt pt;
				sqInt rcvr;
				sqInt pointResult;
				sqInt pointResult1;
				sqInt valuePointer;
				sqInt pointResult2;
				sqInt valuePointer1;
				sqInt valuePointer2;
				sqInt sp;
				successFlag = 1;
				/* begin externalizeIPandSP */
				instructionPointer = oopForPointer(localIP);
				stackPointer = oopForPointer(localSP);
				theHomeContext = localHomeContext;
				/* begin primitiveMakePoint */
				argument = longAt(stackPointer);
				rcvr = longAt(stackPointer - (1 * BytesPerWord));
				if ((rcvr & 1)) {
					if ((argument & 1)) {
						/* begin makePointwithxValue:yValue: */
						pointResult = instantiateSmallClasssizeInBytes(longAt((specialObjectsOop + BaseHeaderSize) + (ClassPoint << ShiftForWord)), 3 * BytesPerWord);
						longAtput((pointResult + BaseHeaderSize) + (XIndex << ShiftForWord), ((((rcvr >> 1)) << 1) | 1));
						longAtput((pointResult + BaseHeaderSize) + (YIndex << ShiftForWord), ((((argument >> 1)) << 1) | 1));
						pt = pointResult;
					} else {
						/* begin makePointwithxValue:yValue: */
						pointResult1 = instantiateSmallClasssizeInBytes(longAt((specialObjectsOop + BaseHeaderSize) + (ClassPoint << ShiftForWord)), 3 * BytesPerWord);
						longAtput((pointResult1 + BaseHeaderSize) + (XIndex << ShiftForWord), ((((rcvr >> 1)) << 1) | 1));
						longAtput((pointResult1 + BaseHeaderSize) + (YIndex << ShiftForWord), ((0 << 1) | 1));
						pt = pointResult1;
						/* begin storePointer:ofObject:withValue: */
						valuePointer = longAt(stackPointer - (0 * BytesPerWord));
						if ((((usqInt) pt)) < (((usqInt) youngStart))) {
							possibleRootStoreIntovalue(pt, valuePointer);
						}
						longAtput((pt + BaseHeaderSize) + (1 << ShiftForWord), valuePointer);
					}
				} else {
					if (!((fetchClassOf(rcvr)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord))))) {
						/* begin success: */
						successFlag = 0 && successFlag;
						goto l20;
					}
					/* begin makePointwithxValue:yValue: */
					pointResult2 = instantiateSmallClasssizeInBytes(longAt((specialObjectsOop + BaseHeaderSize) + (ClassPoint << ShiftForWord)), 3 * BytesPerWord);
					longAtput((pointResult2 + BaseHeaderSize) + (XIndex << ShiftForWord), ((0 << 1) | 1));
					longAtput((pointResult2 + BaseHeaderSize) + (YIndex << ShiftForWord), ((0 << 1) | 1));
					pt = pointResult2;
					/* begin storePointer:ofObject:withValue: */
					valuePointer1 = longAt(stackPointer - (1 * BytesPerWord));
					if ((((usqInt) pt)) < (((usqInt) youngStart))) {
						possibleRootStoreIntovalue(pt, valuePointer1);
					}
					longAtput((pt + BaseHeaderSize) + (0 << ShiftForWord), valuePointer1);
					/* begin storePointer:ofObject:withValue: */
					valuePointer2 = longAt(stackPointer - (0 * BytesPerWord));
					if ((((usqInt) pt)) < (((usqInt) youngStart))) {
						possibleRootStoreIntovalue(pt, valuePointer2);
					}
					longAtput((pt + BaseHeaderSize) + (1 << ShiftForWord), valuePointer2);
				}
				/* begin pop:thenPush: */
				longAtput(sp = stackPointer - ((2 - 1) * BytesPerWord), pt);
				stackPointer = sp;
			l20:	/* end primitiveMakePoint */;
				/* begin internalizeIPandSP */
				localIP = pointerForOop(instructionPointer);
				localSP = pointerForOop(stackPointer);
				localHomeContext = theHomeContext;
				if (successFlag) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					goto l19;
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((11 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
		l19:	/* end case */;
			break;
		case 188:
			/* bytecodePrimBitShift */
			{
				sqInt integerArgument;
				sqInt shifted;
				sqInt integerReceiver;
				sqInt integerPointer;
				sqInt object;
				sqInt sp;
				sqInt top;
				sqInt top2;
				sqInt top1;
				successFlag = 1;
				/* begin externalizeIPandSP */
				instructionPointer = oopForPointer(localIP);
				stackPointer = oopForPointer(localSP);
				theHomeContext = localHomeContext;
				/* begin primitiveBitShift */
				/* begin popInteger */
				/* begin popStack */
				top = longAt(stackPointer);
				stackPointer -= BytesPerWord;
				integerPointer = top;
				/* begin checkedIntegerValueOf: */
				if ((integerPointer & 1)) {
					integerArgument = (integerPointer >> 1);
					goto l22;
				} else {
					/* begin primitiveFail */
					successFlag = 0;
					integerArgument = 0;
					goto l22;
				}
			l22:	/* end checkedIntegerValueOf: */;
				/* begin popPos32BitInteger */
				/* begin popStack */
				top1 = longAt(stackPointer);
				stackPointer -= BytesPerWord;
				top2 = top1;
				integerReceiver = positive32BitValueOf(top2);
				if (successFlag) {
					if (integerArgument >= 0) {
						/* begin success: */
						successFlag = (integerArgument <= 31) && successFlag;
						shifted = integerReceiver << integerArgument;
						/* begin success: */
						successFlag = ((((usqInt) shifted) >> integerArgument) == integerReceiver) && successFlag;
					} else {
						/* begin success: */
						successFlag = (integerArgument >= -31) && successFlag;
						shifted = ((integerArgument < 0) ? ((usqInt) integerReceiver >> -integerArgument) : ((usqInt) integerReceiver << integerArgument));
					}
				}
				if (successFlag) {
					/* begin push: */
					object = positive32BitIntegerFor(shifted);
					longAtput(sp = stackPointer + BytesPerWord, object);
					stackPointer = sp;
				} else {
					/* begin unPop: */
					stackPointer += 2 * BytesPerWord;
				}
				/* begin internalizeIPandSP */
				localIP = pointerForOop(instructionPointer);
				localSP = pointerForOop(stackPointer);
				localHomeContext = theHomeContext;
				if (successFlag) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					goto l21;
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((12 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
		l21:	/* end case */;
			break;
		case 189:
			/* bytecodePrimDiv */
			{
				sqInt quotient;
				successFlag = 1;
				quotient = doPrimitiveDivby(longAtPointer(localSP - (1 * BytesPerWord)), longAtPointer(localSP - (0 * BytesPerWord)));
				if (successFlag) {
					/* begin internalPop:thenPush: */
					longAtPointerput(localSP -= (2 - 1) * BytesPerWord, ((quotient << 1) | 1));
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					goto l23;
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((13 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
		l23:	/* end case */;
			break;
		case 190:
			/* bytecodePrimBitAnd */
			{
				sqInt integerArgument;
				sqInt integerReceiver;
				sqInt object;
				sqInt sp;
				sqInt top;
				sqInt top1;
				sqInt top2;
				sqInt top11;
				successFlag = 1;
				/* begin externalizeIPandSP */
				instructionPointer = oopForPointer(localIP);
				stackPointer = oopForPointer(localSP);
				theHomeContext = localHomeContext;
				/* begin primitiveBitAnd */
				/* begin popPos32BitInteger */
				/* begin popStack */
				top1 = longAt(stackPointer);
				stackPointer -= BytesPerWord;
				top = top1;
				integerArgument = positive32BitValueOf(top);
				/* begin popPos32BitInteger */
				/* begin popStack */
				top11 = longAt(stackPointer);
				stackPointer -= BytesPerWord;
				top2 = top11;
				integerReceiver = positive32BitValueOf(top2);
				if (successFlag) {
					/* begin push: */
					object = positive32BitIntegerFor(integerReceiver & integerArgument);
					longAtput(sp = stackPointer + BytesPerWord, object);
					stackPointer = sp;
				} else {
					/* begin unPop: */
					stackPointer += 2 * BytesPerWord;
				}
				/* begin internalizeIPandSP */
				localIP = pointerForOop(instructionPointer);
				localSP = pointerForOop(stackPointer);
				localHomeContext = theHomeContext;
				if (successFlag) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					goto l24;
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((14 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
		l24:	/* end case */;
			break;
		case 191:
			/* bytecodePrimBitOr */
			{
				sqInt integerArgument;
				sqInt integerReceiver;
				sqInt object;
				sqInt sp;
				sqInt top;
				sqInt top1;
				sqInt top2;
				sqInt top11;
				successFlag = 1;
				/* begin externalizeIPandSP */
				instructionPointer = oopForPointer(localIP);
				stackPointer = oopForPointer(localSP);
				theHomeContext = localHomeContext;
				/* begin primitiveBitOr */
				/* begin popPos32BitInteger */
				/* begin popStack */
				top1 = longAt(stackPointer);
				stackPointer -= BytesPerWord;
				top = top1;
				integerArgument = positive32BitValueOf(top);
				/* begin popPos32BitInteger */
				/* begin popStack */
				top11 = longAt(stackPointer);
				stackPointer -= BytesPerWord;
				top2 = top11;
				integerReceiver = positive32BitValueOf(top2);
				if (successFlag) {
					/* begin push: */
					object = positive32BitIntegerFor(integerReceiver | integerArgument);
					longAtput(sp = stackPointer + BytesPerWord, object);
					stackPointer = sp;
				} else {
					/* begin unPop: */
					stackPointer += 2 * BytesPerWord;
				}
				/* begin internalizeIPandSP */
				localIP = pointerForOop(instructionPointer);
				localSP = pointerForOop(stackPointer);
				localHomeContext = theHomeContext;
				if (successFlag) {
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					goto l25;
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((15 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
		l25:	/* end case */;
			break;
		case 192:
			/* bytecodePrimAt */
			{
				sqInt result;
				sqInt atIx;
				sqInt rcvr;
				sqInt index;
				sqInt result1;
				sqInt fmt;
				sqInt fixedFields;
				sqInt stSize;
				index = longAtPointer(localSP);
				rcvr = longAtPointer(localSP - (1 * BytesPerWord));
				successFlag = (!((rcvr & 1))) && ((index & 1));
				if (successFlag) {
					atIx = rcvr & AtCacheMask;
					if ((atCache[atIx + AtCacheOop]) == rcvr) {
						/* begin commonVariableInternal:at:cacheIndex: */
						stSize = atCache[atIx + AtCacheSize];
						if (((((usqInt) ((index >> 1)))) >= (((usqInt) 1))) && ((((usqInt) ((index >> 1)))) <= (((usqInt) stSize)))) {
							fmt = atCache[atIx + AtCacheFmt];
							if (fmt <= 4) {
								fixedFields = atCache[atIx + AtCacheFixedFields];
								result = longAt((rcvr + BaseHeaderSize) + (((((index >> 1)) + fixedFields) - 1) << ShiftForWord));
								goto l27;
							}
							if (fmt < 8) {
								result1 = long32At((rcvr + BaseHeaderSize) + ((((index >> 1)) - 1) << 2));
								/* begin externalizeIPandSP */
								instructionPointer = oopForPointer(localIP);
								stackPointer = oopForPointer(localSP);
								theHomeContext = localHomeContext;
								result1 = positive32BitIntegerFor(result1);
								/* begin internalizeIPandSP */
								localIP = pointerForOop(instructionPointer);
								localSP = pointerForOop(stackPointer);
								localHomeContext = theHomeContext;
								result = result1;
								goto l27;
							}
							if (fmt >= 16) {
								result = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CharacterTable << ShiftForWord))) + BaseHeaderSize) + ((byteAt((rcvr + BaseHeaderSize) + (((index >> 1)) - 1))) << ShiftForWord));
								goto l27;
							} else {
								result = (((byteAt((rcvr + BaseHeaderSize) + (((index >> 1)) - 1))) << 1) | 1);
								goto l27;
							}
						}
						/* begin primitiveFail */
						successFlag = 0;
					l27:	/* end commonVariableInternal:at:cacheIndex: */;
						if (successFlag) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							/* begin internalPop:thenPush: */
							longAtPointerput(localSP -= (2 - 1) * BytesPerWord, result);
							goto l26;
						}
					}
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((16 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
		l26:	/* end case */;
			break;
		case 193:
			/* bytecodePrimAtPut */
			{
				sqInt value;
				sqInt atIx;
				sqInt rcvr;
				sqInt index;
				sqInt valToPut;
				sqInt fmt;
				sqInt fixedFields;
				sqInt stSize;
				value = longAtPointer(localSP);
				index = longAtPointer(localSP - (1 * BytesPerWord));
				rcvr = longAtPointer(localSP - (2 * BytesPerWord));
				successFlag = (!((rcvr & 1))) && ((index & 1));
				if (successFlag) {
					atIx = (rcvr & AtCacheMask) + AtPutBase;
					if ((atCache[atIx + AtCacheOop]) == rcvr) {
						/* begin commonVariable:at:put:cacheIndex: */
						stSize = atCache[atIx + AtCacheSize];
						if (((((usqInt) ((index >> 1)))) >= (((usqInt) 1))) && ((((usqInt) ((index >> 1)))) <= (((usqInt) stSize)))) {
							fmt = atCache[atIx + AtCacheFmt];
							if (fmt <= 4) {
								fixedFields = atCache[atIx + AtCacheFixedFields];
								/* begin storePointer:ofObject:withValue: */
								if ((((usqInt) rcvr)) < (((usqInt) youngStart))) {
									possibleRootStoreIntovalue(rcvr, value);
								}
								longAtput((rcvr + BaseHeaderSize) + (((((index >> 1)) + fixedFields) - 1) << ShiftForWord), value);
								goto l29;
							}
							if (fmt < 8) {
								valToPut = positive32BitValueOf(value);
								if (successFlag) {
									long32Atput((rcvr + BaseHeaderSize) + ((((index >> 1)) - 1) << 2), valToPut);
								}
								goto l29;
							}
							if (fmt >= 16) {
								valToPut = asciiOfCharacter(value);
								if (!(successFlag)) {
									goto l29;
								}
							} else {
								valToPut = value;
							}
							if ((valToPut & 1)) {
								valToPut = (valToPut >> 1);
								if (!((valToPut >= 0) && (valToPut <= 255))) {
									/* begin primitiveFail */
									successFlag = 0;
									goto l29;
								}
								byteAtput((rcvr + BaseHeaderSize) + (((index >> 1)) - 1), valToPut);
								goto l29;
							}
						}
						/* begin primitiveFail */
						successFlag = 0;
					l29:	/* end commonVariable:at:put:cacheIndex: */;
						if (successFlag) {
							/* begin fetchNextBytecode */
							currentBytecode = byteAtPointer(++localIP);
							/* begin internalPop:thenPush: */
							longAtPointerput(localSP -= (3 - 1) * BytesPerWord, value);
							goto l28;
						}
					}
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((17 * 2) << ShiftForWord));
				argumentCount = 2;
				goto normalSend;
			}
;
		l28:	/* end case */;
			break;
		case 194:
			/* bytecodePrimSize */
			{
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((18 * 2) << ShiftForWord));
				argumentCount = 0;
				goto normalSend;
			}
;
			break;
		case 195:
			/* bytecodePrimNext */
			{
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((19 * 2) << ShiftForWord));
				argumentCount = 0;
				goto normalSend;
			}
;
			break;
		case 196:
			/* bytecodePrimNextPut */
			{
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((20 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
			break;
		case 197:
			/* bytecodePrimAtEnd */
			{
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((21 * 2) << ShiftForWord));
				argumentCount = 0;
				goto normalSend;
			}
;
			break;
		case 198:
			/* bytecodePrimEquivalent */
			{
				sqInt arg;
				sqInt rcvr;
				sqInt bytecode;
				sqInt offset;
				rcvr = longAtPointer(localSP - (1 * BytesPerWord));
				arg = longAtPointer(localSP - (0 * BytesPerWord));
				/* begin booleanCheat: */
				bytecode = byteAtPointer(++localIP);
				/* begin internalPop: */
				localSP -= 2 * BytesPerWord;
				if ((bytecode < 160) && (bytecode > 151)) {
					if (rcvr == arg) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l30;
					} else {
						/* begin jump: */
						localIP = (localIP + (bytecode - 151)) + 1;
						currentBytecode = byteAtPointer(localIP);
						goto l30;
					}
				}
				if (bytecode == 172) {
					offset = byteAtPointer(++localIP);
					if (rcvr == arg) {
						/* begin fetchNextBytecode */
						currentBytecode = byteAtPointer(++localIP);
						goto l30;
					} else {
						/* begin jump: */
						localIP = (localIP + offset) + 1;
						currentBytecode = byteAtPointer(localIP);
						goto l30;
					}
				}
				localIP -= 1;
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
				if (rcvr == arg) {
					/* begin internalPush: */
					longAtPointerput(localSP += BytesPerWord, trueObj);
				} else {
					/* begin internalPush: */
					longAtPointerput(localSP += BytesPerWord, falseObj);
				}
			l30:	/* end booleanCheat: */;
			}
;
			break;
		case 199:
			/* bytecodePrimClass */
			{
				sqInt rcvr;
				sqInt oop;
				sqInt ccIndex;
				rcvr = longAtPointer(localSP);
				/* begin internalPop:thenPush: */
				/* begin fetchClassOf: */
				if ((rcvr & 1)) {
					oop = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
					goto l31;
				}
				ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
				if (ccIndex == 0) {
					oop = (longAt(rcvr - BaseHeaderSize)) & AllButTypeMask;
					goto l31;
				} else {
					oop = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
					goto l31;
				}
			l31:	/* end fetchClassOf: */;
				longAtPointerput(localSP -= (1 - 1) * BytesPerWord, oop);
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
			}
;
			break;
		case 200:
			/* bytecodePrimBlockCopy */
			{
				sqInt hdr;
				sqInt rcvr;
				sqInt successValue;
				sqInt methodContext;
				sqInt context;
				sqInt initialIP;
				sqInt newContext;
				sqInt contextSize;
				sqInt header;
				sqInt oop;
				sqInt sp;
				rcvr = longAtPointer(localSP - (1 * BytesPerWord));
				successFlag = 1;
				hdr = longAt(rcvr);
				/* begin success: */
				successValue = (((((usqInt) hdr) >> 12) & 31) == 13) || ((((((usqInt) hdr) >> 12) & 31) == 14) || (((((usqInt) hdr) >> 12) & 31) == 4));
				successFlag = successValue && successFlag;
				if (successFlag) {
					/* begin externalizeIPandSP */
					instructionPointer = oopForPointer(localIP);
					stackPointer = oopForPointer(localSP);
					theHomeContext = localHomeContext;
					/* begin primitiveBlockCopy */
					context = longAt(stackPointer - (1 * BytesPerWord));
					if (((longAt((context + BaseHeaderSize) + (MethodIndex << ShiftForWord))) & 1)) {
						methodContext = longAt((context + BaseHeaderSize) + (HomeIndex << ShiftForWord));
					} else {
						methodContext = context;
					}
					/* begin sizeBitsOf: */
					header = longAt(methodContext);
					if ((header & TypeMask) == HeaderTypeSizeAndClass) {
						contextSize = (longAt(methodContext - (BytesPerWord * 2))) & LongSizeMask;
						goto l33;
					} else {
						contextSize = header & SizeMask;
						goto l33;
					}
				l33:	/* end sizeBitsOf: */;
					context = null;
					/* begin pushRemappableOop: */
					remapBuffer[remapBufferCount += 1] = methodContext;
					newContext = instantiateContextsizeInBytes(longAt((specialObjectsOop + BaseHeaderSize) + (ClassBlockContext << ShiftForWord)), contextSize);
					/* begin popRemappableOop */
					oop = remapBuffer[remapBufferCount];
					remapBufferCount -= 1;
					methodContext = oop;
					initialIP = (((((instructionPointer + 1) + 3) - (method + BaseHeaderSize)) << 1) | 1);
					longAtput((newContext + BaseHeaderSize) + (InitialIPIndex << ShiftForWord), initialIP);
					longAtput((newContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord), initialIP);
					/* begin storeStackPointerValue:inContext: */
					longAtput((newContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord), ((0 << 1) | 1));
					longAtput((newContext + BaseHeaderSize) + (BlockArgumentCountIndex << ShiftForWord), longAt(stackPointer - (0 * BytesPerWord)));
					longAtput((newContext + BaseHeaderSize) + (HomeIndex << ShiftForWord), methodContext);
					longAtput((newContext + BaseHeaderSize) + (SenderIndex << ShiftForWord), nilObj);
					/* begin pop:thenPush: */
					longAtput(sp = stackPointer - ((2 - 1) * BytesPerWord), newContext);
					stackPointer = sp;
					/* begin internalizeIPandSP */
					localIP = pointerForOop(instructionPointer);
					localSP = pointerForOop(stackPointer);
					localHomeContext = theHomeContext;
				}
				if (!(successFlag)) {
					messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((24 * 2) << ShiftForWord));
					argumentCount = 1;
					goto normalSend;
					goto l32;
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
			}
;
		l32:	/* end case */;
			break;
		case 201:
			/* bytecodePrimValue */
			{
				sqInt rcvrClass;
				sqInt maybeBlock;
				sqInt ccIndex;
				maybeBlock = longAtPointer(localSP);
				argumentCount = 0;
				successFlag = 1;
				if ((maybeBlock & 1) == 0) {
					/* begin fetchClassOfNonInt: */
					ccIndex = (((usqInt) (longAt(maybeBlock))) >> 12) & 31;
					if (ccIndex == 0) {
						rcvrClass = (longAt(maybeBlock - BaseHeaderSize)) & AllButTypeMask;
						goto l35;
					} else {
						rcvrClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
						goto l35;
					}
				l35:	/* end fetchClassOfNonInt: */;
					if (rcvrClass == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassBlockClosure << ShiftForWord)))) {
						/* begin externalizeIPandSP */
						instructionPointer = oopForPointer(localIP);
						stackPointer = oopForPointer(localSP);
						theHomeContext = localHomeContext;
						primitiveClosureValue();
						/* begin internalizeIPandSP */
						localIP = pointerForOop(instructionPointer);
						localSP = pointerForOop(stackPointer);
						localHomeContext = theHomeContext;
					} else {
						if (rcvrClass == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassBlockContext << ShiftForWord)))) {
							/* begin externalizeIPandSP */
							instructionPointer = oopForPointer(localIP);
							stackPointer = oopForPointer(localSP);
							theHomeContext = localHomeContext;
							primitiveValue();
							/* begin internalizeIPandSP */
							localIP = pointerForOop(instructionPointer);
							localSP = pointerForOop(stackPointer);
							localHomeContext = theHomeContext;
						} else {
							successFlag = 0;
						}
					}
				}
				if (!(successFlag)) {
					messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((25 * 2) << ShiftForWord));
					goto normalSend;
					goto l34;
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
			}
;
		l34:	/* end case */;
			break;
		case 202:
			/* bytecodePrimValueWithArg */
			{
				sqInt rcvrClass;
				sqInt maybeBlock;
				sqInt ccIndex;
				maybeBlock = longAtPointer(localSP - (1 * BytesPerWord));
				argumentCount = 1;
				successFlag = 1;
				if ((maybeBlock & 1) == 0) {
					/* begin fetchClassOfNonInt: */
					ccIndex = (((usqInt) (longAt(maybeBlock))) >> 12) & 31;
					if (ccIndex == 0) {
						rcvrClass = (longAt(maybeBlock - BaseHeaderSize)) & AllButTypeMask;
						goto l37;
					} else {
						rcvrClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
						goto l37;
					}
				l37:	/* end fetchClassOfNonInt: */;
					if (rcvrClass == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassBlockClosure << ShiftForWord)))) {
						/* begin externalizeIPandSP */
						instructionPointer = oopForPointer(localIP);
						stackPointer = oopForPointer(localSP);
						theHomeContext = localHomeContext;
						primitiveClosureValue();
						/* begin internalizeIPandSP */
						localIP = pointerForOop(instructionPointer);
						localSP = pointerForOop(stackPointer);
						localHomeContext = theHomeContext;
					} else {
						if (rcvrClass == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassBlockContext << ShiftForWord)))) {
							/* begin externalizeIPandSP */
							instructionPointer = oopForPointer(localIP);
							stackPointer = oopForPointer(localSP);
							theHomeContext = localHomeContext;
							primitiveValue();
							/* begin internalizeIPandSP */
							localIP = pointerForOop(instructionPointer);
							localSP = pointerForOop(stackPointer);
							localHomeContext = theHomeContext;
						} else {
							successFlag = 0;
						}
					}
				}
				if (!(successFlag)) {
					messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((26 * 2) << ShiftForWord));
					goto normalSend;
					goto l36;
				}
				/* begin fetchNextBytecode */
				currentBytecode = byteAtPointer(++localIP);
			}
;
		l36:	/* end case */;
			break;
		case 203:
			/* bytecodePrimDo */
			{
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((27 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
			break;
		case 204:
			/* bytecodePrimNew */
			{
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((28 * 2) << ShiftForWord));
				argumentCount = 0;
				goto normalSend;
			}
;
			break;
		case 205:
			/* bytecodePrimNewWithArg */
			{
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((29 * 2) << ShiftForWord));
				argumentCount = 1;
				goto normalSend;
			}
;
			break;
		case 206:
			/* bytecodePrimPointX */
			{
				sqInt rcvr;
				sqInt cl;
				sqInt ccIndex;
				successFlag = 1;
				rcvr = longAtPointer(localSP);
				/* begin assertClassOf:is: */
				if ((rcvr & 1)) {
					successFlag = 0;
					goto l39;
				}
				ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
				if (ccIndex == 0) {
					cl = (longAt(rcvr - BaseHeaderSize)) & AllButTypeMask;
				} else {
					cl = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
				}
				/* begin success: */
				successFlag = (cl == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassPoint << ShiftForWord)))) && successFlag;
			l39:	/* end assertClassOf:is: */;
				if (successFlag) {
					/* begin internalPop:thenPush: */
					longAtPointerput(localSP -= (1 - 1) * BytesPerWord, longAt((rcvr + BaseHeaderSize) + (XIndex << ShiftForWord)));
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					goto l38;
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((30 * 2) << ShiftForWord));
				argumentCount = 0;
				goto normalSend;
			}
;
		l38:	/* end case */;
			break;
		case 207:
			/* bytecodePrimPointY */
			{
				sqInt rcvr;
				sqInt cl;
				sqInt ccIndex;
				successFlag = 1;
				rcvr = longAtPointer(localSP);
				/* begin assertClassOf:is: */
				if ((rcvr & 1)) {
					successFlag = 0;
					goto l41;
				}
				ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
				if (ccIndex == 0) {
					cl = (longAt(rcvr - BaseHeaderSize)) & AllButTypeMask;
				} else {
					cl = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
				}
				/* begin success: */
				successFlag = (cl == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassPoint << ShiftForWord)))) && successFlag;
			l41:	/* end assertClassOf:is: */;
				if (successFlag) {
					/* begin internalPop:thenPush: */
					longAtPointerput(localSP -= (1 - 1) * BytesPerWord, longAt((rcvr + BaseHeaderSize) + (YIndex << ShiftForWord)));
					/* begin fetchNextBytecode */
					currentBytecode = byteAtPointer(++localIP);
					goto l40;
				}
				messageSelector = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SpecialSelectors << ShiftForWord))) + BaseHeaderSize) + ((31 * 2) << ShiftForWord));
				argumentCount = 0;
				goto normalSend;
			}
;
		l40:	/* end case */;
			break;
		case 208:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((208 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 208) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 209:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((209 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 209) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 210:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((210 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 210) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 211:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((211 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 211) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 212:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((212 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 212) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 213:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((213 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 213) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 214:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((214 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 214) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 215:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((215 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 215) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 216:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((216 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 216) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 217:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((217 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 217) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 218:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((218 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 218) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 219:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((219 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 219) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 220:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((220 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 220) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 221:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((221 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 221) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 222:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((222 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 222) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 223:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((223 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 223) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 224:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((224 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 224) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 225:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((225 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 225) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 226:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((226 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 226) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 227:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((227 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 227) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 228:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((228 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 228) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 229:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((229 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 229) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 230:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((230 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 230) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 231:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((231 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 231) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 232:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((232 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 232) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 233:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((233 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 233) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 234:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((234 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 234) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 235:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((235 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 235) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 236:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((236 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 236) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 237:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((237 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 237) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 238:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((238 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 238) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 239:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((239 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 239) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 240:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((240 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 240) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 241:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((241 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 241) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 242:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((242 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 242) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 243:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((243 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 243) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 244:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((244 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 244) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 245:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((245 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 245) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 246:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((246 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 246) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 247:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((247 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 247) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 248:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((248 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 248) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 249:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((249 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 249) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 250:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((250 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 250) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 251:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((251 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 251) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 252:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((252 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 252) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 253:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((253 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 253) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 254:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((254 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 254) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		case 255:
			/* sendLiteralSelectorBytecode */
			{
				messageSelector = longAt((method + BaseHeaderSize) + (((255 & 15) + LiteralStart) << ShiftForWord));
				argumentCount = ((((usqInt) 255) >> 4) & 3) - 1;
				goto normalSend;
			}
;
			break;
		}
	}

	/* undo the pre-increment of IP before returning */

	localIP -= 1;
	/* begin externalizeIPandSP */
	instructionPointer = oopForPointer(localIP);
	stackPointer = oopForPointer(localSP);
	theHomeContext = localHomeContext;
}


/*	the vm has to convert aFilenameString via any canonicalization and char-mapping and put the result in aCharBuffer.
Note the resolveAliases flag - this is an awful artefact of OSX and Apples demented alias handling. When opening a file, the flag must be  true, when closing or renaming it must be false. Sigh. */

sqInt ioFilenamefromStringofLengthresolveAliases(char * aCharBuffer, char * aFilenameString, sqInt filenameLength, sqInt aBoolean) {
	sqGetFilenameFromString(aCharBuffer, aFilenameString, filenameLength, aBoolean);
}


/*	Support for external primitives. */

sqInt isKindOf(sqInt oop, char * className) {
    sqInt oopClass;
    sqInt ccIndex;

	/* begin fetchClassOf: */
	if ((oop & 1)) {
		oopClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		oopClass = (longAt(oop - BaseHeaderSize)) & AllButTypeMask;
		goto l1;
	} else {
		oopClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	while (!(oopClass == nilObj)) {
		if (classNameOfIs(oopClass, className)) {
			return 1;
		}
		oopClass = longAt((oopClass + BaseHeaderSize) + (SuperclassIndex << ShiftForWord));
	}
	return 0;
}


/*	Support for external primitives */

sqInt isMemberOf(sqInt oop, char * className) {
    sqInt oopClass;
    sqInt ccIndex;

	/* begin fetchClassOf: */
	if ((oop & 1)) {
		oopClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		oopClass = (longAt(oop - BaseHeaderSize)) & AllButTypeMask;
		goto l1;
	} else {
		oopClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	return classNameOfIs(oopClass, className);
}


/*	Answer true if this is an indexable object with pointer elements, e.g., an array */

sqInt isArray(sqInt oop) {
	return ((oop & 1) == 0) && (((((usqInt) (longAt(oop))) >> 8) & 15) == 2);
}


/*	Answer true (non-zero) if running on a big endian machine. */

sqInt isBigEnder(void) {
    char * cString;
    sqInt i;
    sqInt anInt;
    static sqInt endianness = -1;
    sqInt len;

	if (!(endianness == -1)) {
		return endianness;
	}
	len = sizeof(anInt);
	cString = (char *) &anInt;
	i = 0;
	while (i < len) {
		cString[i] = i;
		i += 1;
	}
	endianness = anInt & 255;
	return endianness;
}


/*	Answer true if the argument contains indexable bytes. See comment in formatOf: */
/*	Note: Includes CompiledMethods. */

sqInt isBytes(sqInt oop) {
	return ((oop & 1) == 0) && (((((usqInt) (longAt(oop))) >> 8) & 15) >= 8);
}


/*	Answer true if size is greater than (((2 raisedTo: 31) - 1) >> bits). Used
	to limit size of allocation requests to 31 bit integer maximum to prevent
	arithmetic overflow in subsequent calculations. Always answers false
	in interpreter simulation.

	Assumes that sizeof(int) is 4 for all platforms. */

sqInt isExcessiveAllocationRequestshift(sqInt size, sqInt bits) {
    sqInt shiftCount;
    int int32;

	int32 = size;
	shiftCount = 0;
	if (int32 < 0) {
		return 1;
	}
	while (shiftCount < bits) {
		int32 = int32 << 1;
		if (int32 < 0) {
			return 1;
		}
		shiftCount += 1;
	}
	return 0;
}

sqInt isFloatObject(sqInt oop) {
	return (fetchClassOf(oop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)));
}


/*	Is this a MethodContext whose meth has a primitive number of 199? */
/*	NB: the use of a primitive number for marking the method is pretty grungy, but it is simple to use for a test sytem, not too expensive and we don't actually have the two spare method header bits we need. We can probably obtain them when the method format is changed.
	NB 2: actually, the jitter will probably implement the prim to actually mark the volatile frame by changing the return function pointer. */

sqInt isHandlerMarked(sqInt aContext) {
    sqInt meth;
    sqInt header;
    sqInt pIndex;
    sqInt primBits;

	header = longAt(aContext);
	if (!(((((usqInt) header) >> 12) & 31) == 14)) {
		return 0;
	}
	meth = longAt((aContext + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	/* begin primitiveIndexOf: */
	primBits = (((usqInt) (longAt((meth + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 1) & 268435967;
	pIndex = (primBits & 511) + (((usqInt) primBits) >> 19);
	return pIndex == 199;
}


/*	Return true if the given address is in ST object memory */

sqInt isInMemory(sqInt address) {
	return ((((usqInt) address)) >= (((usqInt) memory))) && ((((usqInt) address)) < (((usqInt) endOfMemory)));
}

sqInt isIndexable(sqInt oop) {
	return ((((usqInt) (longAt(oop))) >> 8) & 15) >= 2;
}

sqInt isIntegerObject(sqInt objectPointer) {
	return (objectPointer & 1) > 0;
}


/*	Return true if the given value can be represented as a Smalltalk integer value. */
/*	Use a shift and XOR to set the sign bit if and only if the top two bits of the given
	value are the same, then test the sign bit. Note that the top two bits are equal for
	exactly those integers in the range that can be represented in 31-bits or 63-bits.

	Operands are coerced to machine integer size so the test will work with 64 bit
	images on 32 bit hosts. When running on a 32 bit host, the cast to int has little
	or no performance impact for either 32 bit or 64 bit images.

	On a 64 bit host, the shift and XOR test is replaced by an explicit range check,
	which provides the best performance for both 32 bit and 64 bit images.

	If the range of small integers is enlarged for 64 bit images, this method must
	be updated accordingly. */

sqInt isIntegerValue(sqInt intValue) {
	return 
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) intValue)) ^ ((((int) intValue)) << 1)) >= 0)
# else
		((intValue >= -1073741824) && (intValue <= 1073741823))
# endif  // SQ_HOST32
	;
}


/*	Answer true if the argument has only fields that can hold oops. See comment in formatOf: */

sqInt isPointers(sqInt oop) {
	return ((oop & 1) == 0) && (((((usqInt) (longAt(oop))) >> 8) & 15) <= 4);
}


/*	Answer true if the argument has only weak fields that can hold oops. See comment in formatOf: */

sqInt isWeak(sqInt oop) {
	return ((oop & 1) == 0) && (((((usqInt) (longAt(oop))) >> 8) & 15) == 4);
}


/*	Answer true if the argument contains only indexable words (no oops). See comment in formatOf: */

sqInt isWords(sqInt oop) {
	return ((oop & 1) == 0) && (((((usqInt) (longAt(oop))) >> 8) & 15) == 6);
}


/*	Answer true if the contains only indexable words or bytes (no oops). See comment in formatOf: */
/*	Note: Excludes CompiledMethods. */

sqInt isWordsOrBytes(sqInt oop) {
	return ((oop & 1) == 0) && (isWordsOrBytesNonInt(oop));
}


/*	Answer true if the contains only indexable words or bytes (no oops). See comment in formatOf: */
/*	Note: Excludes CompiledMethods. */

sqInt isWordsOrBytesNonInt(sqInt oop) {
    sqInt fmt;

	fmt = (((usqInt) (longAt(oop))) >> 8) & 15;
	return (fmt == 6) || ((fmt >= 8) && (fmt <= 11));
}


/*	Return the byte offset of the last pointer field of the given object.  
	Works with CompiledMethods, as well as ordinary objects. 
	Can be used even when the type bits are not correct. */

sqInt lastPointerOf(sqInt oop) {
    sqInt sz;
    sqInt header;
    sqInt contextSize;
    sqInt fmt;
    sqInt methodHeader;
    sqInt sp;
    sqInt header1;
    sqInt type;

	header = longAt(oop);
	fmt = (((usqInt) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && ((((((usqInt) header) >> 12) & 31) == 13) || ((((((usqInt) header) >> 12) & 31) == 14) || (((((usqInt) header) >> 12) & 31) == 4)))) {
			/* begin fetchStackPointerOf: */
			sp = longAt((oop + BaseHeaderSize) + (StackPointerIndex << ShiftForWord));
			if (!((sp & 1))) {
				contextSize = 0;
				goto l1;
			}
			contextSize = (sp >> 1);
		l1:	/* end fetchStackPointerOf: */;
			return (CtxtTempFrameStart + contextSize) * BytesPerWord;
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(oop);
		/* begin rightType: */
		if ((header1 & SizeMask) == 0) {
			type = HeaderTypeSizeAndClass;
			goto l2;
		} else {
			if ((header1 & CompactClassMask) == 0) {
				type = HeaderTypeClass;
				goto l2;
			} else {
				type = HeaderTypeShort;
				goto l2;
			}
		}
	l2:	/* end rightType: */;
		if (type == HeaderTypeSizeAndClass) {
			sz = (longAt(oop - (BytesPerWord * 2))) & AllButTypeMask;
			goto l3;
		} else {
			sz = header1 & SizeMask;
			goto l3;
		}
	l3:	/* end sizeBitsOfSafe: */;
		return sz - BaseHeaderSize;
	}
	if (fmt < 12) {
		return 0;
	}
	methodHeader = longAt(oop + BaseHeaderSize);
	return (((((usqInt) methodHeader) >> 10) & 255) * BytesPerWord) + BaseHeaderSize;
}


/*	Return the number of indexable bytes or words in the given object. Assume the argument is not an integer. For a CompiledMethod, the size of the method header (in bytes) should be subtracted from the result. */

sqInt lengthOf(sqInt oop) {
    sqInt header;
    sqInt sz;

	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz = header & SizeMask;
	}
	sz -= header & Size4Bit;
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		return ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		return ((usqInt) (sz - BaseHeaderSize)) >> 2;
	} else {
		return (sz - BaseHeaderSize) - (((((usqInt) header) >> 8) & 15) & 3);
	}
	return null;
}

sqInt literalofMethod(sqInt offset, sqInt methodPointer) {
	return longAt((methodPointer + BaseHeaderSize) + ((offset + LiteralStart) << ShiftForWord));
}

sqInt literalCountOf(sqInt methodPointer) {
	return (((usqInt) (longAt((methodPointer + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 10) & 255;
}


/*	This entry point needs to be implemented for the interpreter proxy.
	Since BitBlt is now a plugin we need to look up BitBltPlugin:=loadBitBltFrom
	and call it. This entire mechanism should eventually go away and be
	replaced with a dynamic lookup from BitBltPlugin itself but for backward
	compatibility this stub is provided */

sqInt loadBitBltFrom(sqInt bb) {
    void * fn;

	fn = ioLoadFunctionFrom("loadBitBltFrom", "BitBltPlugin");
	if (fn == 0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	return ((sqInt (*)(sqInt))fn)(bb);
}

sqInt loadInitialContext(void) {
    sqInt proc;
    sqInt sched;
    sqInt activeCntx;
    sqInt tmp;

	sched = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord));
	proc = longAt((sched + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
	activeContext = longAt((proc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord));
	if ((((usqInt) activeContext)) < (((usqInt) youngStart))) {
		beRootIfOld(activeContext);
	}
	/* begin fetchContextRegisters: */
	activeCntx = activeContext;
	tmp = longAt((activeCntx + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	if ((tmp & 1)) {
		tmp = longAt((activeCntx + BaseHeaderSize) + (HomeIndex << ShiftForWord));
		if ((((usqInt) tmp)) < (((usqInt) youngStart))) {
			beRootIfOld(tmp);
		}
	} else {
		tmp = activeCntx;
	}
	theHomeContext = tmp;
	receiver = longAt((tmp + BaseHeaderSize) + (ReceiverIndex << ShiftForWord));
	method = longAt((tmp + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	tmp = ((longAt((activeCntx + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord))) >> 1);
	instructionPointer = ((method + tmp) + BaseHeaderSize) - 2;
	tmp = ((longAt((activeCntx + BaseHeaderSize) + (StackPointerIndex << ShiftForWord))) >> 1);
	stackPointer = (activeCntx + BaseHeaderSize) + (((TempFrameStart + tmp) - 1) * BytesPerWord);
	reclaimableContextCount = 0;
}

sqInt lookupMethodInClass(sqInt class) {
    sqInt dictionary;
    sqInt currentClass;
    sqInt rclass;
    sqInt found;
    sqInt oop;
    sqInt oop1;
    sqInt length;
    sqInt wrapAround;
    sqInt index;
    sqInt nextSelector;
    sqInt mask;
    sqInt methodArray;
    sqInt primBits;
    sqInt sz;
    sqInt header;

	currentClass = class;
	while (currentClass != nilObj) {
		dictionary = longAt((currentClass + BaseHeaderSize) + (MessageDictionaryIndex << ShiftForWord));
		if (dictionary == nilObj) {
			/* begin pushRemappableOop: */
			remapBuffer[remapBufferCount += 1] = currentClass;
			createActualMessageTo(class);
			/* begin popRemappableOop */
			oop = remapBuffer[remapBufferCount];
			remapBufferCount -= 1;
			currentClass = oop;
			messageSelector = longAt((specialObjectsOop + BaseHeaderSize) + (SelectorCannotInterpret << ShiftForWord));
			return lookupMethodInClass(longAt((currentClass + BaseHeaderSize) + (SuperclassIndex << ShiftForWord)));
		}
		/* begin lookupMethodInDictionary: */
		/* begin fetchWordLengthOf: */
		/* begin sizeBitsOf: */
		header = longAt(dictionary);
		if ((header & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(dictionary - (BytesPerWord * 2))) & LongSizeMask;
			goto l1;
		} else {
			sz = header & SizeMask;
			goto l1;
		}
	l1:	/* end sizeBitsOf: */;
		length = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
		mask = (length - SelectorStart) - 1;
		if ((messageSelector & 1)) {
			index = (mask & ((messageSelector >> 1))) + SelectorStart;
		} else {
			index = (mask & ((((usqInt) (longAt(messageSelector))) >> 17) & 4095)) + SelectorStart;
		}
		wrapAround = 0;
		while (1) {
			nextSelector = longAt((dictionary + BaseHeaderSize) + (index << ShiftForWord));
			if (nextSelector == nilObj) {
				found = 0;
				goto l2;
			}
			if (nextSelector == messageSelector) {
				methodArray = longAt((dictionary + BaseHeaderSize) + (MethodArrayIndex << ShiftForWord));
				newMethod = longAt((methodArray + BaseHeaderSize) + ((index - SelectorStart) << ShiftForWord));
				if (((((usqInt) (longAt(newMethod))) >> 8) & 15) >= 12) {
					/* begin primitiveIndexOf: */
					primBits = (((usqInt) (longAt((newMethod + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 1) & 268435967;
					primitiveIndex = (primBits & 511) + (((usqInt) primBits) >> 19);
					if (primitiveIndex > MaxPrimitiveIndex) {
						primitiveIndex = 0;
					}
				} else {
					primitiveIndex = 248;
				}
				found = 1;
				goto l2;
			}
			index += 1;
			if (index == length) {
				if (wrapAround) {
					found = 0;
					goto l2;
				}
				wrapAround = 1;
				index = SelectorStart;
			}
		}
	l2:	/* end lookupMethodInDictionary: */;
		if (found) {
			return methodClass = currentClass;
		}
		currentClass = longAt((currentClass + BaseHeaderSize) + (SuperclassIndex << ShiftForWord));
	}
	if (messageSelector == (longAt((specialObjectsOop + BaseHeaderSize) + (SelectorDoesNotUnderstand << ShiftForWord)))) {
		error("Recursive not understood error encountered");
	}
	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = class;
	createActualMessageTo(class);
	/* begin popRemappableOop */
	oop1 = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	rclass = oop1;
	messageSelector = longAt((specialObjectsOop + BaseHeaderSize) + (SelectorDoesNotUnderstand << ShiftForWord));
	return lookupMethodInClass(rclass);
}


/*	Return the first free block after the given chunk in memory. */

sqInt lowestFreeAfter(sqInt chunk) {
    sqInt oopSize;
    sqInt oop;
    sqInt oopHeaderType;
    sqInt oopHeader;

	oop = chunk + (headerTypeBytes[(longAt(chunk)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) endOfMemory))) {
		oopHeader = longAt(oop);
		oopHeaderType = oopHeader & TypeMask;
		if (oopHeaderType == HeaderTypeFree) {
			return oop;
		} else {
			if (oopHeaderType == HeaderTypeSizeAndClass) {
				oopSize = (longAt(oop - (BytesPerWord * 2))) & AllButTypeMask;
			} else {
				oopSize = oopHeader & SizeMask;
			}
		}
		oop = (oop + oopSize) + (headerTypeBytes[(longAt(oop + oopSize)) & TypeMask]);
	}
	error("expected to find at least one free object");
}


/*	make a Point xValue@yValue.
We know both will be integers so no value nor root checking is needed */

sqInt makePointwithxValueyValue(sqInt xValue, sqInt yValue) {
    sqInt pointResult;

	pointResult = instantiateSmallClasssizeInBytes(longAt((specialObjectsOop + BaseHeaderSize) + (ClassPoint << ShiftForWord)), 3 * BytesPerWord);
	longAtput((pointResult + BaseHeaderSize) + (XIndex << ShiftForWord), ((xValue << 1) | 1));
	longAtput((pointResult + BaseHeaderSize) + (YIndex << ShiftForWord), ((yValue << 1) | 1));
	return pointResult;
}


/*	Use the forwarding table to update the pointers of all non-free objects in the given range of memory. Also remap pointers in root objects which may contains pointers into the given memory range, and don't forget to flush the method cache based on the range */

sqInt mapPointersInObjectsFromto(sqInt memStart, sqInt memEnd) {
    sqInt oop;
    sqInt i;
    sqInt oop1;
    sqInt i1;
    sqInt i2;
    sqInt probe;

	/* begin compilerMapHookFrom:to: */
	if (compilerInitialized) {
		compilerMapFromto(memStart, memEnd);
	}
	/* begin mapInterpreterOops */
	nilObj = remap(nilObj);
	falseObj = remap(falseObj);
	trueObj = remap(trueObj);
	specialObjectsOop = remap(specialObjectsOop);
	if (!(compilerInitialized)) {
		stackPointer -= activeContext;
		activeContext = remap(activeContext);
		stackPointer += activeContext;
		theHomeContext = remap(theHomeContext);
	}
	instructionPointer -= method;
	method = remap(method);
	instructionPointer += method;
	receiver = remap(receiver);
	messageSelector = remap(messageSelector);
	newMethod = remap(newMethod);
	methodClass = remap(methodClass);
	lkupClass = remap(lkupClass);
	receiverClass = remap(receiverClass);
	for (i1 = 1; i1 <= remapBufferCount; i1 += 1) {
		oop1 = remapBuffer[i1];
		if (!((oop1 & 1))) {
			remapBuffer[i1] = (remap(oop1));
		}
	}
	for (i1 = 1; i1 <= jmpDepth; i1 += 1) {
		oop1 = suspendedCallbacks[i1];
		if (!((oop1 & 1))) {
			suspendedCallbacks[i1] = (remap(oop1));
		}
		oop1 = suspendedMethods[i1];
		if (!((oop1 & 1))) {
			suspendedMethods[i1] = (remap(oop1));
		}
	}
	for (i = 1; i <= extraRootCount; i += 1) {
		oop = (extraRoots[i])[0];
		if (!((oop & 1))) {
			(extraRoots[i])[0] = (remap(oop));
		}
	}
	/* begin flushMethodCacheFrom:to: */
	probe = 0;
	for (i2 = 1; i2 <= MethodCacheEntries; i2 += 1) {
		if (!((methodCache[probe + MethodCacheSelector]) == 0)) {
			if ((((((((usqInt) (methodCache[probe + MethodCacheSelector]))) >= (((usqInt) memStart))) && ((((usqInt) (methodCache[probe + MethodCacheSelector]))) < (((usqInt) memEnd)))) || (((((usqInt) (methodCache[probe + MethodCacheClass]))) >= (((usqInt) memStart))) && ((((usqInt) (methodCache[probe + MethodCacheClass]))) < (((usqInt) memEnd))))) || (((((usqInt) (methodCache[probe + MethodCacheMethod]))) >= (((usqInt) memStart))) && ((((usqInt) (methodCache[probe + MethodCacheMethod]))) < (((usqInt) memEnd))))) || (((((usqInt) (methodCache[probe + MethodCacheNative]))) >= (((usqInt) memStart))) && ((((usqInt) (methodCache[probe + MethodCacheNative]))) < (((usqInt) memEnd))))) {
				methodCache[probe + MethodCacheSelector] = 0;
			}
		}
		probe += MethodCacheEntrySize;
	}
	for (i2 = 1; i2 <= AtCacheTotalSize; i2 += 1) {
		atCache[i2] = 0;
	}
	updatePointersInRootObjectsFromto(memStart, memEnd);
	updatePointersInRangeFromto(memStart, memEnd);
}


/*	Mark all objects reachable from the given one.
	Trace from the given object even if it is old.
	Do not trace if it is already marked.
	Mark it only if it is a young object. */
/*	Tracer state variables:
		child		object being examined
		field		next field of child to examine
		parentField	field where child was stored in its referencing object */

sqInt markAndTrace(sqInt oop) {
    sqInt lastFieldOffset;
    sqInt action;
    sqInt header;
    sqInt statMarkCountLocal;
    sqInt sz;
    sqInt header1;
    sqInt contextSize;
    sqInt fmt;
    sqInt methodHeader;
    sqInt typeBits;
    sqInt childType;
    sqInt type;
    sqInt header2;
    sqInt sp;
    sqInt header3;
    sqInt type1;
    sqInt lastFieldOffset1;
    sqInt oop1;
    sqInt header4;
    sqInt sz1;
    sqInt header11;
    sqInt contextSize1;
    sqInt fmt1;
    sqInt methodHeader1;
    sqInt sp1;
    sqInt header21;
    sqInt type2;
    sqInt child;
    sqInt field;
    usqInt youngStartLocal;
    sqInt parentField;

	header = longAt(oop);
	if (!((header & MarkBit) == 0)) {
		return 0;
	}
	header = (header & AllButTypeMask) | HeaderTypeGC;
	if ((((usqInt) oop)) >= (((usqInt) youngStart))) {
		header = header | MarkBit;
	}
	longAtput(oop, header);
	parentField = GCTopMarker;
	child = oop;
	if (((((usqInt) (longAt(oop))) >> 8) & 15) == 4) {

		/* Set lastFieldOffset before the weak fields in the receiver */
		/* And remember as weak root */

		lastFieldOffset = (nonWeakFieldsOf(oop)) << ShiftForWord;
		weakRootCount += 1;
		weakRoots[weakRootCount] = oop;
	} else {
		/* begin lastPointerOf: */
		header1 = longAt(oop);
		fmt = (((usqInt) header1) >> 8) & 15;
		if (fmt <= 4) {
			if ((fmt == 3) && ((((((usqInt) header1) >> 12) & 31) == 13) || ((((((usqInt) header1) >> 12) & 31) == 14) || (((((usqInt) header1) >> 12) & 31) == 4)))) {
				/* begin fetchStackPointerOf: */
				sp = longAt((oop + BaseHeaderSize) + (StackPointerIndex << ShiftForWord));
				if (!((sp & 1))) {
					contextSize = 0;
					goto l7;
				}
				contextSize = (sp >> 1);
			l7:	/* end fetchStackPointerOf: */;
				lastFieldOffset = (CtxtTempFrameStart + contextSize) * BytesPerWord;
				goto l1;
			}
			/* begin sizeBitsOfSafe: */
			header3 = longAt(oop);
			/* begin rightType: */
			if ((header3 & SizeMask) == 0) {
				type1 = HeaderTypeSizeAndClass;
				goto l8;
			} else {
				if ((header3 & CompactClassMask) == 0) {
					type1 = HeaderTypeClass;
					goto l8;
				} else {
					type1 = HeaderTypeShort;
					goto l8;
				}
			}
		l8:	/* end rightType: */;
			if (type1 == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - (BytesPerWord * 2))) & AllButTypeMask;
				goto l9;
			} else {
				sz = header3 & SizeMask;
				goto l9;
			}
		l9:	/* end sizeBitsOfSafe: */;
			lastFieldOffset = sz - BaseHeaderSize;
			goto l1;
		}
		if (fmt < 12) {
			lastFieldOffset = 0;
			goto l1;
		}
		methodHeader = longAt(oop + BaseHeaderSize);
		lastFieldOffset = (((((usqInt) methodHeader) >> 10) & 255) * BytesPerWord) + BaseHeaderSize;
	l1:	/* end lastPointerOf: */;
	}
	field = oop + lastFieldOffset;
	action = StartField;
	youngStartLocal = youngStart;

	/* run the tracer state machine until all objects reachable from oop are marked */

	statMarkCountLocal = statMarkCount;
	while (!(action == Done)) {
		statMarkCountLocal += 1;
		if (action == StartField) {
			/* begin startField */
			child = longAt(field);
			typeBits = child & TypeMask;
			if ((typeBits & 1) == 1) {
				field -= BytesPerWord;
				action = StartField;
				goto l3;
			}
			if (typeBits == 0) {
				longAtput(field, parentField);
				parentField = field;
				action = StartObj;
				goto l3;
			}
			if (typeBits == 2) {
				if ((child & CompactClassMask) != 0) {
					child = child & AllButTypeMask;
					/* begin rightType: */
					if ((child & SizeMask) == 0) {
						childType = HeaderTypeSizeAndClass;
						goto l2;
					} else {
						if ((child & CompactClassMask) == 0) {
							childType = HeaderTypeClass;
							goto l2;
						} else {
							childType = HeaderTypeShort;
							goto l2;
						}
					}
				l2:	/* end rightType: */;
					longAtput(field, child | childType);
					action = Upward;
					goto l3;
				} else {
					child = longAt(field - BytesPerWord);
					child = child & AllButTypeMask;
					longAtput(field - BytesPerWord, parentField);
					parentField = (field - BytesPerWord) | 1;
					action = StartObj;
					goto l3;
				}
			}
		l3:	/* end startField */;
		}
		if (action == StartObj) {
			/* begin startObj */
			oop1 = child;
			if ((((usqInt) oop1)) < (((usqInt) youngStartLocal))) {
				field = oop1;
				action = Upward;
				goto l14;
			}
			header4 = longAt(oop1);
			if ((header4 & MarkBit) == 0) {
				if (((((usqInt) (longAt(oop1))) >> 8) & 15) == 4) {
					lastFieldOffset1 = (nonWeakFieldsOf(oop1)) << ShiftForWord;
				} else {
					/* begin lastPointerOf: */
					header11 = longAt(oop1);
					fmt1 = (((usqInt) header11) >> 8) & 15;
					if (fmt1 <= 4) {
						if ((fmt1 == 3) && ((((((usqInt) header11) >> 12) & 31) == 13) || ((((((usqInt) header11) >> 12) & 31) == 14) || (((((usqInt) header11) >> 12) & 31) == 4)))) {
							/* begin fetchStackPointerOf: */
							sp1 = longAt((oop1 + BaseHeaderSize) + (StackPointerIndex << ShiftForWord));
							if (!((sp1 & 1))) {
								contextSize1 = 0;
								goto l11;
							}
							contextSize1 = (sp1 >> 1);
						l11:	/* end fetchStackPointerOf: */;
							lastFieldOffset1 = (CtxtTempFrameStart + contextSize1) * BytesPerWord;
							goto l10;
						}
						/* begin sizeBitsOfSafe: */
						header21 = longAt(oop1);
						/* begin rightType: */
						if ((header21 & SizeMask) == 0) {
							type2 = HeaderTypeSizeAndClass;
							goto l12;
						} else {
							if ((header21 & CompactClassMask) == 0) {
								type2 = HeaderTypeClass;
								goto l12;
							} else {
								type2 = HeaderTypeShort;
								goto l12;
							}
						}
					l12:	/* end rightType: */;
						if (type2 == HeaderTypeSizeAndClass) {
							sz1 = (longAt(oop1 - (BytesPerWord * 2))) & AllButTypeMask;
							goto l13;
						} else {
							sz1 = header21 & SizeMask;
							goto l13;
						}
					l13:	/* end sizeBitsOfSafe: */;
						lastFieldOffset1 = sz1 - BaseHeaderSize;
						goto l10;
					}
					if (fmt1 < 12) {
						lastFieldOffset1 = 0;
						goto l10;
					}
					methodHeader1 = longAt(oop1 + BaseHeaderSize);
					lastFieldOffset1 = (((((usqInt) methodHeader1) >> 10) & 255) * BytesPerWord) + BaseHeaderSize;
				l10:	/* end lastPointerOf: */;
				}
				header4 = header4 & AllButTypeMask;
				header4 = (header4 | MarkBit) | HeaderTypeGC;
				longAtput(oop1, header4);
				field = oop1 + lastFieldOffset1;
				action = StartField;
				goto l14;
			} else {
				field = oop1;
				action = Upward;
				goto l14;
			}
		l14:	/* end startObj */;
		}
		if (action == Upward) {
			/* begin upward */
			if ((parentField & 1) == 1) {
				if (parentField == GCTopMarker) {
					header2 = (longAt(field)) & AllButTypeMask;
					/* begin rightType: */
					if ((header2 & SizeMask) == 0) {
						type = HeaderTypeSizeAndClass;
						goto l4;
					} else {
						if ((header2 & CompactClassMask) == 0) {
							type = HeaderTypeClass;
							goto l4;
						} else {
							type = HeaderTypeShort;
							goto l4;
						}
					}
				l4:	/* end rightType: */;
					longAtput(field, header2 | type);
					action = Done;
					goto l6;
				} else {
					child = field;
					field = parentField - 1;
					parentField = longAt(field);
					header2 = longAt(field + BytesPerWord);
					/* begin rightType: */
					if ((header2 & SizeMask) == 0) {
						type = HeaderTypeSizeAndClass;
						goto l5;
					} else {
						if ((header2 & CompactClassMask) == 0) {
							type = HeaderTypeClass;
							goto l5;
						} else {
							type = HeaderTypeShort;
							goto l5;
						}
					}
				l5:	/* end rightType: */;
					longAtput(field, child | type);
					field += BytesPerWord;
					header2 = header2 & AllButTypeMask;
					longAtput(field, header2 | type);
					action = Upward;
					goto l6;
				}
			} else {
				child = field;
				field = parentField;
				parentField = longAt(field);
				longAtput(field, child);
				field -= BytesPerWord;
				action = StartField;
				goto l6;
			}
		l6:	/* end upward */;
		}
	}
	statMarkCount = statMarkCountLocal;
}


/*	Mark and trace all oops in the interpreter's state. */
/*	Assume: All traced variables contain valid oops. */

sqInt markAndTraceInterpreterOops(void) {
    sqInt oop;
    sqInt i;

	/* begin compilerMarkHook */
	if (compilerInitialized) {
		compilerMark();
	}
	markAndTrace(specialObjectsOop);
	if (compilerInitialized) {
		markAndTrace(receiver);
		markAndTrace(method);
	} else {
		markAndTrace(activeContext);
	}
	markAndTrace(messageSelector);
	markAndTrace(newMethod);
	markAndTrace(methodClass);
	markAndTrace(lkupClass);
	markAndTrace(receiverClass);
	for (i = 1; i <= remapBufferCount; i += 1) {
		oop = remapBuffer[i];
		if (!((oop & 1))) {
			markAndTrace(oop);
		}
	}
	for (i = 1; i <= jmpDepth; i += 1) {
		oop = suspendedCallbacks[i];
		if (!((oop & 1))) {
			markAndTrace(oop);
		}
		oop = suspendedMethods[i];
		if (!((oop & 1))) {
			markAndTrace(oop);
		}
	}
}


/*	Mark phase of the mark and sweep garbage collector. Set 
	the mark bits of all reachable objects. Free chunks are 
	untouched by this process. */
/*	Assume: All non-free objects are initially unmarked. Root 
	objects were unmarked when they were made roots. (Make 
	sure this stays true!!). */

sqInt markPhase(void) {
    sqInt oop;
    sqInt i;

	freeContexts = NilContext;

	/* trace the interpreter's objects, including the active stack 
	and special objects array */

	freeLargeContexts = NilContext;
	markAndTraceInterpreterOops();

	/* trace the roots */

	statSpecialMarkCount = statMarkCount;
	for (i = 1; i <= rootTableCount; i += 1) {
		oop = rootTable[i];
		markAndTrace(oop);
	}
	for (i = 1; i <= extraRootCount; i += 1) {
		oop = (extraRoots[i])[0];
		if (!((oop & 1))) {
			markAndTrace(oop);
		}
	}
}

sqInt methodArgumentCount(void) {
	return argumentCount;
}

sqInt methodPrimitiveIndex(void) {
	return primitiveIndex;
}


/*	The module with the given name was just unloaded. 
	Make sure we have no dangling references. */

EXPORT(sqInt) moduleUnloaded(char * aModuleName) {
	if ((strcmp(aModuleName, "SurfacePlugin")) == 0) {

		/* Surface plugin went away. Should never happen. But  then, who knows */

		showSurfaceFn = 0;
	}
}


/*	For access from BitBlt module */

sqInt nilObject(void) {
	return nilObj;
}


/*	Return the number of non-weak fields in oop (i.e. the number of fixed fields).
	Note: The following is copied from fixedFieldsOf:format:length: since we do know
	the format of the oop (e.g. format = 4) and thus don't need the length. */

sqInt nonWeakFieldsOf(sqInt oop) {
    sqInt classFormat;
    sqInt class;
    sqInt ccIndex;

	if (!(((((usqInt) (longAt(oop))) >> 8) & 15) == 4)) {
		error("Called fixedFieldsOfWeak: with a non-weak oop");
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		class = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(oop - BaseHeaderSize)) & AllButTypeMask;
		goto l1;
	} else {
		class = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	classFormat = (longAt((class + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1;
	return (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
}


/*	Record that the given oop in the old object area points to an 
	object in the young area. 
	HeaderLoc is usually = oop, but may be an addr in a 
	forwarding block. */

sqInt noteAsRootheaderLoc(sqInt oop, sqInt headerLoc) {
    sqInt header;

	header = longAt(headerLoc);
	if ((header & RootBit) == 0) {
		if (rootTableCount < RootTableRedZone) {

			/* record oop as root only if not already recorded */
			/* record root if there is enough room in the roots 
					table  */

			rootTableCount += 1;
			rootTable[rootTableCount] = oop;
			longAtput(headerLoc, header | RootBit);
		} else {
			if (rootTableCount < RootTableSize) {

				/* we're getting in the red zone */
				/* but there's still space to record it */

				rootTableCount += 1;
				rootTable[rootTableCount] = oop;
				longAtput(headerLoc, header | RootBit);
				allocationCount = allocationsBetweenGCs + 1;
			}
		}
	}
}


/*	This should never be called: either the compiler is uninitialised (in which case the hooks should never be reached) or the compiler initialisation should have replaced all the hook with their external implementations. */

sqInt nullCompilerHook(void) {
	error("uninitialised compiler hook called");
	return 0;
}


/*	Return the object or free chunk immediately following the 
	given object or free chunk in memory. Return endOfMemory 
	when enumeration is complete. */

sqInt objectAfter(sqInt oop) {
    sqInt sz;
    sqInt header;

	if (DoAssertionChecks) {
		if ((((usqInt) oop)) >= (((usqInt) endOfMemory))) {
			error("no objects after the end of memory");
		}
	}
	if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
		sz = (longAt(oop)) & AllButTypeMask;
	} else {
		/* begin sizeBitsOf: */
		header = longAt(oop);
		if ((header & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
			goto l1;
		} else {
			sz = header & SizeMask;
			goto l1;
		}
	l1:	/* end sizeBitsOf: */;
	}
	return (oop + sz) + (headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
}


/*	This message is deprecated but supported for a while via a tweak to sqVirtualMachine.[ch] Use fetchLong32, fetchLong64 or fetchPointer instead for new code */

sqInt obsoleteDontUseThisFetchWordofObject(sqInt fieldIndex, sqInt oop) {
	return long32At((oop + BaseHeaderSize) + (fieldIndex << 2));
}


/*	If this is a pointers object, check that its fields are all okay oops. */

sqInt okayFields(sqInt oop) {
    sqInt i;
    sqInt c;
    sqInt fieldOop;
    sqInt ccIndex;

	if ((oop == null) || (oop == 0)) {
		return 1;
	}
	if ((oop & 1)) {
		return 1;
	}
	okayOop(oop);
	oopHasOkayClass(oop);
	if (!(((oop & 1) == 0) && (((((usqInt) (longAt(oop))) >> 8) & 15) <= 4))) {
		return 1;
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		c = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		c = (longAt(oop - BaseHeaderSize)) & AllButTypeMask;
		goto l1;
	} else {
		c = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	if ((c == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassMethodContext << ShiftForWord)))) || (c == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassBlockContext << ShiftForWord))))) {
		i = (CtxtTempFrameStart + (fetchStackPointerOf(oop))) - 1;
	} else {
		i = (lengthOf(oop)) - 1;
	}
	while (i >= 0) {
		fieldOop = longAt((oop + BaseHeaderSize) + (i << ShiftForWord));
		if (!((fieldOop & 1))) {
			okayOop(fieldOop);
			oopHasOkayClass(fieldOop);
		}
		i -= 1;
	}
}


/*	Verify that the given oop is legitimate. Check address, header, and size but not class. */

sqInt okayOop(sqInt signedOop) {
    usqInt oop;
    sqInt unusedBit;
    sqInt sz;
    sqInt type;
    sqInt fmt;
    sqInt header;


	/* address and size checks */

	oop = ((usqInt) signedOop);
	if ((oop & 1)) {
		return 1;
	}
	if (!(oop < endOfMemory)) {
		error("oop is not a valid address");
	}
	if (!((oop % BytesPerWord) == 0)) {
		error("oop is not a word-aligned address");
	}
	/* begin sizeBitsOf: */
	header = longAt(oop);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
		goto l1;
	} else {
		sz = header & SizeMask;
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	if (!((oop + sz) < endOfMemory)) {
		error("oop size would make it extend beyond the end of memory");
	}
	type = (longAt(oop)) & TypeMask;
	if (type == HeaderTypeFree) {
		error("oop is a free chunk, not an object");
	}
	if (type == HeaderTypeShort) {
		if (((((usqInt) (longAt(oop))) >> 12) & 31) == 0) {
			error("cannot have zero compact class field in a short header");
		}
	}
	if (type == HeaderTypeClass) {
		if (!((oop >= BytesPerWord) && (((longAt(oop - BytesPerWord)) & TypeMask) == type))) {
			error("class header word has wrong type");
		}
	}
	if (type == HeaderTypeSizeAndClass) {
		if (!((oop >= (BytesPerWord * 2)) && ((((longAt(oop - (BytesPerWord * 2))) & TypeMask) == type) && (((longAt(oop - BytesPerWord)) & TypeMask) == type)))) {
			error("class header word has wrong type");
		}
	}
	fmt = (((usqInt) (longAt(oop))) >> 8) & 15;
	if ((fmt == 5) || (fmt == 7)) {
		error("oop has an unknown format type");
	}
	unusedBit = 536870912;
	if (BytesPerWord == 8) {
		unusedBit = unusedBit << 16;
		unusedBit = unusedBit << 16;
	}
	if (!(((longAt(oop)) & unusedBit) == 0)) {
		error("unused header bit 30 is set; should be zero");
	}
	if ((((longAt(oop)) & RootBit) == 1) && (oop >= youngStart)) {
		error("root bit is set in a young object");
	}
	return 1;
}


/*	Similar to oopHasOkayClass:, except that it only returns true or false. */

sqInt oopHasAcceptableClass(sqInt signedOop) {
    usqInt oop;
    sqInt formatMask;
    usqInt oopClass;
    sqInt behaviorFormatBits;
    sqInt oopFormatBits;

	if ((signedOop & 1)) {
		return 1;
	}
	oop = ((usqInt) signedOop);
	if (!(oop < endOfMemory)) {
		return 0;
	}
	if (!((oop % BytesPerWord) == 0)) {
		return 0;
	}
	if (!((oop + (sizeBitsOf(oop))) < endOfMemory)) {
		return 0;
	}
	oopClass = ((usqInt) (fetchClassOf(oop)));
	if ((oopClass & 1)) {
		return 0;
	}
	if (!(oopClass < endOfMemory)) {
		return 0;
	}
	if (!((oopClass % BytesPerWord) == 0)) {
		return 0;
	}
	if (!((oopClass + (sizeBitsOf(oopClass))) < endOfMemory)) {
		return 0;
	}
	if (!((((oopClass & 1) == 0) && (((((usqInt) (longAt(oopClass))) >> 8) & 15) <= 4)) && ((lengthOf(oopClass)) >= 3))) {
		return 0;
	}
	if (((oop & 1) == 0) && (((((usqInt) (longAt(oop))) >> 8) & 15) >= 8)) {

		/* ignore extra bytes size bits */

		formatMask = 3072;
	} else {
		formatMask = 3840;
	}
	behaviorFormatBits = ((longAt((oopClass + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1) & formatMask;
	oopFormatBits = (longAt(oop)) & formatMask;
	if (!(behaviorFormatBits == oopFormatBits)) {
		return 0;
	}
	return 1;
}


/*	Attempt to verify that the given oop has a reasonable behavior. The class must be a valid, non-integer oop and must not be nilObj. It must be a pointers object with three or more fields. Finally, the instance specification field of the behavior must match that of the instance. */

sqInt oopHasOkayClass(sqInt signedOop) {
    usqInt oop;
    sqInt formatMask;
    usqInt oopClass;
    sqInt behaviorFormatBits;
    sqInt oopFormatBits;

	oop = ((usqInt) signedOop);
	okayOop(oop);
	oopClass = ((usqInt) (fetchClassOf(oop)));
	if ((oopClass & 1)) {
		error("a SmallInteger is not a valid class or behavior");
	}
	okayOop(oopClass);
	if (!((((oopClass & 1) == 0) && (((((usqInt) (longAt(oopClass))) >> 8) & 15) <= 4)) && ((lengthOf(oopClass)) >= 3))) {
		error("a class (behavior) must be a pointers object of size >= 3");
	}
	if (((oop & 1) == 0) && (((((usqInt) (longAt(oop))) >> 8) & 15) >= 8)) {

		/* ignore extra bytes size bits */

		formatMask = 3072;
	} else {
		formatMask = 3840;
	}
	behaviorFormatBits = ((longAt((oopClass + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1) & formatMask;
	oopFormatBits = (longAt(oop)) & formatMask;
	if (!(behaviorFormatBits == oopFormatBits)) {
		error("object and its class (behavior) formats differ");
	}
	return 1;
}


/*	Note: May be called by translated primitive code. */

sqInt pop(sqInt nItems) {
	stackPointer -= nItems * BytesPerWord;
}

sqInt popthenPush(sqInt nItems, sqInt oop) {
    sqInt sp;

	longAtput(sp = stackPointer - ((nItems - 1) * BytesPerWord), oop);
	stackPointer = sp;
}


/*	Note: May be called by translated primitive code. */

double popFloat(void) {
    double  result;
    sqInt top;
    sqInt top1;
    sqInt cl;
    sqInt ccIndex;

	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	top = top1;
	/* begin assertClassOf:is: */
	if ((top & 1)) {
		successFlag = 0;
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(top))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(top - BaseHeaderSize)) & AllButTypeMask;
	} else {
		cl = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
	}
	/* begin success: */
	successFlag = (cl == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) && successFlag;
l1:	/* end assertClassOf:is: */;
	if (successFlag) {
		;
		fetchFloatAtinto(top + BaseHeaderSize, result);
	}
	return result;
}


/*	Pop and return the possibly remapped object from the remap buffer. */

sqInt popRemappableOop(void) {
    sqInt oop;

	oop = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	return oop;
}

sqInt popStack(void) {
    sqInt top;

	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	return top;
}


/*	Note - integerValue is interpreted as POSITIVE, eg, as the result of
		Bitmap>at:, or integer>bitAnd:. */

sqInt positive32BitIntegerFor(sqInt integerValue) {
    sqInt newLargeInteger;

	if (integerValue >= 0) {
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) integerValue)) ^ ((((int) integerValue)) << 1)) >= 0)
# else
			((integerValue >= -1073741824) && (integerValue <= 1073741823))
# endif  // SQ_HOST32
		) {
			return ((integerValue << 1) | 1);
		}
	}
	if (BytesPerWord == 4) {

		/* Faster instantiateSmallClass: currently only works with integral word size. */

		newLargeInteger = instantiateSmallClasssizeInBytes(longAt((specialObjectsOop + BaseHeaderSize) + (ClassLargePositiveInteger << ShiftForWord)), BaseHeaderSize + 4);
	} else {

		/* Cant use instantiateSmallClass: due to integral word requirement. */

		newLargeInteger = instantiateClassindexableSize(longAt((specialObjectsOop + BaseHeaderSize) + (ClassLargePositiveInteger << ShiftForWord)), 4);
	}
	byteAtput((newLargeInteger + BaseHeaderSize) + 3, (((usqInt) integerValue) >> 24) & 255);
	byteAtput((newLargeInteger + BaseHeaderSize) + 2, (((usqInt) integerValue) >> 16) & 255);
	byteAtput((newLargeInteger + BaseHeaderSize) + 1, (((usqInt) integerValue) >> 8) & 255);
	byteAtput((newLargeInteger + BaseHeaderSize) + 0, integerValue & 255);
	return newLargeInteger;
}


/*	Convert the given object into an integer value.
	The object may be either a positive ST integer or a four-byte LargePositiveInteger. */

sqInt positive32BitValueOf(sqInt oop) {
    sqInt sz;
    sqInt value;
    sqInt header;
    sqInt sz1;
    sqInt cl;
    sqInt ccIndex;

	if ((oop & 1)) {
		value = (oop >> 1);
		if (value < 0) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		return value;
	}
	/* begin assertClassOf:is: */
	if ((oop & 1)) {
		successFlag = 0;
		goto l2;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(oop - BaseHeaderSize)) & AllButTypeMask;
	} else {
		cl = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
	}
	/* begin success: */
	successFlag = (cl == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassLargePositiveInteger << ShiftForWord)))) && successFlag;
l2:	/* end assertClassOf:is: */;
	if (successFlag) {
		/* begin lengthOf: */
		header = longAt(oop);
		/* begin lengthOf:baseHeader:format: */
		if ((header & TypeMask) == HeaderTypeSizeAndClass) {
			sz1 = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
		} else {
			sz1 = header & SizeMask;
		}
		sz1 -= header & Size4Bit;
		if (((((usqInt) header) >> 8) & 15) <= 4) {
			sz = ((usqInt) (sz1 - BaseHeaderSize)) >> ShiftForWord;
			goto l1;
		}
		if (((((usqInt) header) >> 8) & 15) < 8) {
			sz = ((usqInt) (sz1 - BaseHeaderSize)) >> 2;
			goto l1;
		} else {
			sz = (sz1 - BaseHeaderSize) - (((((usqInt) header) >> 8) & 15) & 3);
			goto l1;
		}
		sz = null;
	l1:	/* end lengthOf: */;
		if (!(sz == 4)) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	if (successFlag) {
		return (((byteAt((oop + BaseHeaderSize) + 0)) + ((byteAt((oop + BaseHeaderSize) + 1)) << 8)) + ((byteAt((oop + BaseHeaderSize) + 2)) << 16)) + ((byteAt((oop + BaseHeaderSize) + 3)) << 24);
	}
}


/*	Note - integerValue is interpreted as POSITIVE, eg, as the result of
		Bitmap>at:, or integer>bitAnd:. */

sqInt positive64BitIntegerFor(sqLong integerValue) {
    sqInt sz;
    sqInt highWord;
    sqInt i;
    sqInt value;
    sqInt newLargeInteger;

	if ((sizeof(integerValue)) == 4) {
		return positive32BitIntegerFor(integerValue);
	}

	/* shift is coerced to usqInt otherwise */

	highWord = integerValue >> 32;
	if (highWord == 0) {
		return positive32BitIntegerFor(integerValue);
	}
	sz = 5;
	if (!((highWord = ((usqInt) highWord) >> 8) == 0)) {
		sz += 1;
	}
	if (!((highWord = ((usqInt) highWord) >> 8) == 0)) {
		sz += 1;
	}
	if (!((highWord = ((usqInt) highWord) >> 8) == 0)) {
		sz += 1;
	}
	newLargeInteger = instantiateClassindexableSize(longAt((specialObjectsOop + BaseHeaderSize) + (ClassLargePositiveInteger << ShiftForWord)), sz);
	for (i = 0; i <= (sz - 1); i += 1) {
		value = (integerValue >> (i * 8)) & 255;
		byteAtput((newLargeInteger + BaseHeaderSize) + i, value);
	}
	return newLargeInteger;
}


/*	Convert the given object into an integer value.
	The object may be either a positive ST integer or a eight-byte LargePositiveInteger. */

sqLong positive64BitValueOf(sqInt oop) {
    sqInt sz;
    sqInt i;
    sqLong value;
    sqInt szsqLong;
    sqInt header;
    sqInt sz1;
    sqInt cl;
    sqInt ccIndex;

	if ((oop & 1)) {
		value = (oop >> 1);
		if (value < 0) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		return value;
	}
	/* begin assertClassOf:is: */
	if ((oop & 1)) {
		successFlag = 0;
		goto l2;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(oop - BaseHeaderSize)) & AllButTypeMask;
	} else {
		cl = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
	}
	/* begin success: */
	successFlag = (cl == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassLargePositiveInteger << ShiftForWord)))) && successFlag;
l2:	/* end assertClassOf:is: */;
	if (!(successFlag)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	szsqLong = sizeof(sqLong);
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz1 = header & SizeMask;
	}
	sz1 -= header & Size4Bit;
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		sz = ((usqInt) (sz1 - BaseHeaderSize)) >> ShiftForWord;
		goto l1;
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		sz = ((usqInt) (sz1 - BaseHeaderSize)) >> 2;
		goto l1;
	} else {
		sz = (sz1 - BaseHeaderSize) - (((((usqInt) header) >> 8) & 15) & 3);
		goto l1;
	}
	sz = null;
l1:	/* end lengthOf: */;
	if (sz > szsqLong) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	value = 0;
	for (i = 0; i <= (sz - 1); i += 1) {
		value += (((sqLong) (byteAt((oop + BaseHeaderSize) + i)))) << (i * 8);
	}
	return value;
}


/*	oop is an old object. If valueObj is young, mark the object as a root. */

sqInt possibleRootStoreIntovalue(sqInt oop, sqInt valueObj) {
    sqInt header;

	if (((((usqInt) valueObj)) >= (((usqInt) youngStart))) && (!((valueObj & 1)))) {
		/* begin noteAsRoot:headerLoc: */
		header = longAt(oop);
		if ((header & RootBit) == 0) {
			if (rootTableCount < RootTableRedZone) {
				rootTableCount += 1;
				rootTable[rootTableCount] = oop;
				longAtput(oop, header | RootBit);
			} else {
				if (rootTableCount < RootTableSize) {
					rootTableCount += 1;
					rootTable[rootTableCount] = oop;
					longAtput(oop, header | RootBit);
					allocationCount = allocationsBetweenGCs + 1;
				}
			}
		}
	}
}


/*	Mark the active and home contexts as roots if old. This 
	allows the interpreter to use storePointerUnchecked to 
	store into them. */

sqInt postGCAction(void) {
    sqInt delta;
    sqInt limit;

	if (compilerInitialized) {
		compilerPostGC();
	} else {
		if ((((usqInt) activeContext)) < (((usqInt) youngStart))) {
			beRootIfOld(activeContext);
		}
		if ((((usqInt) theHomeContext)) < (((usqInt) youngStart))) {
			beRootIfOld(theHomeContext);
		}
	}
	if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) > (((usqInt) shrinkThreshold))) {
		/* begin shrinkObjectMemory: */
		delta = ((longAt(freeBlock)) & AllButTypeMask) - growHeadroom;
		statShrinkMemory += 1;
		limit = sqShrinkMemoryBy(memoryLimit, delta);
		if (!(limit == memoryLimit)) {
			memoryLimit = limit - 24;
			initializeMemoryFirstFree(freeBlock);
		}
	}
	/* begin signalSemaphoreWithIndex: */
	if (gcSemaphoreIndex <= 0) {
		goto l1;
	}
	if (semaphoresUseBufferA) {
		if (semaphoresToSignalCountA < SemaphoresToSignalSize) {
			semaphoresToSignalCountA += 1;
			semaphoresToSignalA[semaphoresToSignalCountA] = gcSemaphoreIndex;
		}
	} else {
		if (semaphoresToSignalCountB < SemaphoresToSignalSize) {
			semaphoresToSignalCountB += 1;
			semaphoresToSignalB[semaphoresToSignalCountB] = gcSemaphoreIndex;
		}
	}
	/* begin forceInterruptCheck */
	interruptCheckCounter = -1000;
	nextPollTick = 0;
l1:	/* end signalSemaphoreWithIndex: */;
}


/*	Prepare the active process to be recognizable for execution.
	Required for the initial process which is not event triggered. */

EXPORT(sqInt) prepareActiveProcess(void) {
    sqInt activeProc;
    sqInt valuePointer;

	vmRecursionDepth = 0;
	activeProc = longAt(((longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord))) + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
	/* begin storePointer:ofObject:withValue: */
	valuePointer = nilObj;
	if ((((usqInt) activeProc)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(activeProc, valuePointer);
	}
	longAtput((activeProc + BaseHeaderSize) + (MyListIndex << ShiftForWord), valuePointer);
}


/*	Ensure that there are enough forwarding blocks to 
	accomodate this become, then prepare forwarding blocks for 
	the pointer swap. Return true if successful. */
/*	Details: Doing a GC might generate enough space for 
	forwarding blocks if we're short. However, this is an 
	uncommon enough case that it is better handled by primitive 
	fail code at the Smalltalk level. */
/*	Important note on multiple references to same object  - since the preparation of
	fwdBlocks is NOT idempotent we get VM crashes if the same object is referenced more
	than once in such a way as to require multiple fwdBlocks.
	oop1 forwardBecome: oop1 is ok since only a single fwdBlock is needed.
	oop1 become: oop1 would fail because the second fwdBlock woudl not have the actual object
	header but rather the mutated ref to the first fwdBlock.
	Further problems can arise with an array1 or array2 that refer multiply to the same 
	object. This would notbe expected input for programmer writen code but might arise from
	automatic usage such as in ImageSegment loading.
	To avoid the simple and rather common case of oop1 become*: oop1, we skip such pairs
	and simply avoid making fwdBlocks - it is redundant anyway */

sqInt prepareForwardingTableForBecomingwithtwoWay(sqInt array1, sqInt array2, sqInt twoWayFlag) {
    sqInt fieldOffset;
    sqInt oop1;
    sqInt entriesAvailable;
    sqInt entriesNeeded;
    sqInt fwdBlock;
    sqInt oop2;
    sqInt fwdBlkSize;
    sqInt originalHeader;
    sqInt originalHeaderType;
    sqInt originalHeader1;
    sqInt originalHeaderType1;
    sqInt sz;
    sqInt header;
    sqInt contextSize;
    sqInt fmt;
    sqInt methodHeader;
    sqInt sp;
    sqInt header1;
    sqInt type;


	/* need enough entries for all oops */
	/* Note: Forward blocks must be quadword aligned - see fwdTableInit:. */

	entriesNeeded = ((sqInt) (lastPointerOf(array1)) >> 2);
	if (twoWayFlag) {

		/* Double the number of blocks for two-way become */

		entriesNeeded = entriesNeeded * 2;
		fwdBlkSize = BytesPerWord * 2;
	} else {

		/* One-way become needs backPointers in fwd blocks. */

		fwdBlkSize = BytesPerWord * 4;
	}
	entriesAvailable = fwdTableInit(fwdBlkSize);
	if (entriesAvailable < entriesNeeded) {
		initializeMemoryFirstFree(freeBlock);
		return 0;
	}
	/* begin lastPointerOf: */
	header = longAt(array1);
	fmt = (((usqInt) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && ((((((usqInt) header) >> 12) & 31) == 13) || ((((((usqInt) header) >> 12) & 31) == 14) || (((((usqInt) header) >> 12) & 31) == 4)))) {
			/* begin fetchStackPointerOf: */
			sp = longAt((array1 + BaseHeaderSize) + (StackPointerIndex << ShiftForWord));
			if (!((sp & 1))) {
				contextSize = 0;
				goto l4;
			}
			contextSize = (sp >> 1);
		l4:	/* end fetchStackPointerOf: */;
			fieldOffset = (CtxtTempFrameStart + contextSize) * BytesPerWord;
			goto l3;
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(array1);
		/* begin rightType: */
		if ((header1 & SizeMask) == 0) {
			type = HeaderTypeSizeAndClass;
			goto l5;
		} else {
			if ((header1 & CompactClassMask) == 0) {
				type = HeaderTypeClass;
				goto l5;
			} else {
				type = HeaderTypeShort;
				goto l5;
			}
		}
	l5:	/* end rightType: */;
		if (type == HeaderTypeSizeAndClass) {
			sz = (longAt(array1 - (BytesPerWord * 2))) & AllButTypeMask;
			goto l6;
		} else {
			sz = header1 & SizeMask;
			goto l6;
		}
	l6:	/* end sizeBitsOfSafe: */;
		fieldOffset = sz - BaseHeaderSize;
		goto l3;
	}
	if (fmt < 12) {
		fieldOffset = 0;
		goto l3;
	}
	methodHeader = longAt(array1 + BaseHeaderSize);
	fieldOffset = (((((usqInt) methodHeader) >> 10) & 255) * BytesPerWord) + BaseHeaderSize;
l3:	/* end lastPointerOf: */;
	while (fieldOffset >= BaseHeaderSize) {
		oop1 = longAt(array1 + fieldOffset);

		/* if oop1 == oop2, no need to do any work for this pair.
			May still be other entries in the arrays though so keep looking */

		oop2 = longAt(array2 + fieldOffset);
		if (!(oop1 == oop2)) {
			/* begin fwdBlockGet: */
			fwdTableNext += fwdBlkSize;
			if (fwdTableNext <= fwdTableLast) {
				fwdBlock = fwdTableNext;
				goto l2;
			} else {
				fwdBlock = null;
				goto l2;
			}
		l2:	/* end fwdBlockGet: */;
			/* begin initForwardBlock:mapping:to:withBackPtr: */
			originalHeader1 = longAt(oop1);
			if (DoAssertionChecks) {
				if (fwdBlock == null) {
					error("ran out of forwarding blocks in become");
				}
				if ((originalHeader1 & MarkBit) != 0) {
					error("object already has a forwarding table entry");
				}
			}
			originalHeaderType1 = originalHeader1 & TypeMask;
			longAtput(fwdBlock, oop2);
			longAtput(fwdBlock + BytesPerWord, originalHeader1);
			if (!twoWayFlag) {
				longAtput(fwdBlock + (BytesPerWord * 2), oop1);
			}
			longAtput(oop1, (((usqInt) fwdBlock) >> 1) | (MarkBit | originalHeaderType1));
			if (twoWayFlag) {
				/* begin fwdBlockGet: */
				fwdTableNext += fwdBlkSize;
				if (fwdTableNext <= fwdTableLast) {
					fwdBlock = fwdTableNext;
					goto l1;
				} else {
					fwdBlock = null;
					goto l1;
				}
			l1:	/* end fwdBlockGet: */;
				/* begin initForwardBlock:mapping:to:withBackPtr: */
				originalHeader = longAt(oop2);
				if (DoAssertionChecks) {
					if (fwdBlock == null) {
						error("ran out of forwarding blocks in become");
					}
					if ((originalHeader & MarkBit) != 0) {
						error("object already has a forwarding table entry");
					}
				}
				originalHeaderType = originalHeader & TypeMask;
				longAtput(fwdBlock, oop1);
				longAtput(fwdBlock + BytesPerWord, originalHeader);
				if (!twoWayFlag) {
					longAtput(fwdBlock + (BytesPerWord * 2), oop2);
				}
				longAtput(oop2, (((usqInt) fwdBlock) >> 1) | (MarkBit | originalHeaderType));
			}
		}
		fieldOffset -= BytesPerWord;
	}
	return 1;
}

sqInt primitiveAdd(void) {
    sqInt integerResult;
    sqInt sp;

	/* begin pop2AndPushIntegerIfOK: */
	integerResult = (stackIntegerValue(1)) + (stackIntegerValue(0));
	if (successFlag) {
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) integerResult)) ^ ((((int) integerResult)) << 1)) >= 0)
# else
			((integerResult >= -1073741824) && (integerResult <= 1073741823))
# endif  // SQ_HOST32
		) {
			/* begin pop:thenPush: */
			longAtput(sp = stackPointer - ((2 - 1) * BytesPerWord), ((integerResult << 1) | 1));
			stackPointer = sp;
		} else {
			successFlag = 0;
		}
	}
}

sqInt primitiveArctan(void) {
    double  rcvr;

	rcvr = popFloat();
	if (successFlag) {
		pushFloat(atan(rcvr));
	} else {
		/* begin unPop: */
		stackPointer += 1 * BytesPerWord;
	}
}


/*	We must flush the method cache here, to eliminate stale references
	to mutated classes and/or selectors. */

sqInt primitiveArrayBecome(void) {
    sqInt arg;
    sqInt rcvr;
    sqInt successValue;

	arg = longAt(stackPointer);
	rcvr = longAt(stackPointer - (1 * BytesPerWord));
	/* begin success: */
	successValue = becomewithtwoWaycopyHash(rcvr, arg, 1, 1);
	successFlag = successValue && successFlag;
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * BytesPerWord;
	}
}


/*	We must flush the method cache here, to eliminate stale references
	to mutated classes and/or selectors. */

sqInt primitiveArrayBecomeOneWay(void) {
    sqInt arg;
    sqInt rcvr;
    sqInt successValue;

	arg = longAt(stackPointer);
	rcvr = longAt(stackPointer - (1 * BytesPerWord));
	/* begin success: */
	successValue = becomewithtwoWaycopyHash(rcvr, arg, 0, 1);
	successFlag = successValue && successFlag;
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * BytesPerWord;
	}
}


/*	Similar to primitiveArrayBecomeOneWay but accepts a third argument whether to copy
	the receiver's identity hash over the argument's identity hash. */

sqInt primitiveArrayBecomeOneWayCopyHash(void) {
    sqInt arg;
    sqInt rcvr;
    sqInt copyHashFlag;
    sqInt successValue;

	/* begin booleanValueOf: */
	if ((longAt(stackPointer)) == trueObj) {
		copyHashFlag = 1;
		goto l1;
	}
	if ((longAt(stackPointer)) == falseObj) {
		copyHashFlag = 0;
		goto l1;
	}
	successFlag = 0;
	copyHashFlag = null;
l1:	/* end booleanValueOf: */;
	arg = longAt(stackPointer - (1 * BytesPerWord));
	rcvr = longAt(stackPointer - (2 * BytesPerWord));
	/* begin success: */
	successValue = becomewithtwoWaycopyHash(rcvr, arg, 0, copyHashFlag);
	successFlag = successValue && successFlag;
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * BytesPerWord;
	}
}

sqInt primitiveAsFloat(void) {
    sqInt arg;
    sqInt integerPointer;
    sqInt top;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		arg = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		arg = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	if (successFlag) {
		pushFloat(((double) arg));
	} else {
		/* begin unPop: */
		stackPointer += 1 * BytesPerWord;
	}
}

sqInt primitiveAsOop(void) {
    sqInt thisReceiver;
    sqInt sp;

	thisReceiver = longAt(stackPointer);
	/* begin success: */
	successFlag = (!((thisReceiver & 1))) && successFlag;
	if (successFlag) {
		/* begin pop:thenPushInteger: */
		longAtput(sp = stackPointer - ((1 - 1) * BytesPerWord), ((((((usqInt) (longAt(thisReceiver))) >> 17) & 4095) << 1) | 1));
		stackPointer = sp;
	}
}

sqInt primitiveAt(void) {
	commonAt(0);
}

sqInt primitiveAtEnd(void) {
    sqInt stream;
    sqInt index;
    sqInt limit;
    sqInt sp;
    sqInt sp1;
    sqInt top;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	stream = top;
	successFlag = (((stream & 1) == 0) && (((((usqInt) (longAt(stream))) >> 8) & 15) <= 4)) && ((lengthOf(stream)) >= (StreamReadLimitIndex + 1));
	if (successFlag) {
		index = fetchIntegerofObject(StreamIndexIndex, stream);
		limit = fetchIntegerofObject(StreamReadLimitIndex, stream);
	}
	if (successFlag) {
		/* begin pushBool: */
		if (index >= limit) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		stackPointer += 1 * BytesPerWord;
	}
}

sqInt primitiveAtPut(void) {
	commonAtPut(0);
}


/*	Set the cursor to the given shape. The Mac only supports 16x16 pixel cursors. Cursor offsets are handled by Smalltalk. */

sqInt primitiveBeCursor(void) {
    sqInt ourCursor;
    sqInt maskObj;
    sqInt offsetY;
    sqInt offsetX;
    sqInt offsetObj;
    sqInt cursorObj;
    sqInt i;
    sqInt extentY;
    sqInt maskBitsIndex;
    sqInt extentX;
    sqInt bitsObj;
    sqInt depth;
    sqInt cursorBitsIndex;
    sqInt successValue;
    sqInt successValue1;
    sqInt successValue2;
    sqInt successValue3;
    sqInt successValue4;
    sqInt successValue5;
    sqInt successValue6;
    sqInt successValue7;
    sqInt successValue8;
    sqInt successValue9;
    sqInt successValue10;
    sqInt successValue11;
    sqInt successValue12;

	flag("Dan");
	if (BytesPerWord == 8) {
		/* begin pop: */
		stackPointer -= argumentCount * BytesPerWord;
		return null;
	}
	if (argumentCount == 0) {
		cursorObj = longAt(stackPointer);
		maskBitsIndex = null;
	}
	if (argumentCount == 1) {
		cursorObj = longAt(stackPointer - (1 * BytesPerWord));
		maskObj = longAt(stackPointer);
	}
	/* begin success: */
	successFlag = (argumentCount < 2) && successFlag;
	/* begin success: */
	successValue11 = (((cursorObj & 1) == 0) && (((((usqInt) (longAt(cursorObj))) >> 8) & 15) <= 4)) && ((lengthOf(cursorObj)) >= 5);
	successFlag = successValue11 && successFlag;
	if (successFlag) {
		bitsObj = longAt((cursorObj + BaseHeaderSize) + (0 << ShiftForWord));
		extentX = fetchIntegerofObject(1, cursorObj);
		extentY = fetchIntegerofObject(2, cursorObj);
		depth = fetchIntegerofObject(3, cursorObj);
		offsetObj = longAt((cursorObj + BaseHeaderSize) + (4 << ShiftForWord));
	}
	/* begin success: */
	successValue12 = (((offsetObj & 1) == 0) && (((((usqInt) (longAt(offsetObj))) >> 8) & 15) <= 4)) && ((lengthOf(offsetObj)) >= 2);
	successFlag = successValue12 && successFlag;
	if (successFlag) {
		offsetX = fetchIntegerofObject(0, offsetObj);
		offsetY = fetchIntegerofObject(1, offsetObj);
		if ((argumentCount == 0) && (depth == 32)) {
			/* begin success: */
			successValue = (extentX > 0) && (extentY > 0);
			successFlag = successValue && successFlag;
			/* begin success: */
			successValue1 = (offsetX >= (extentX * -1)) && (offsetX <= 0);
			successFlag = successValue1 && successFlag;
			/* begin success: */
			successValue2 = (offsetY >= (extentY * -1)) && (offsetY <= 0);
			successFlag = successValue2 && successFlag;
			cursorBitsIndex = bitsObj + BaseHeaderSize;
			/* begin success: */
			successValue3 = (((bitsObj & 1) == 0) && (((((usqInt) (longAt(bitsObj))) >> 8) & 15) == 6)) && ((lengthOf(bitsObj)) == (extentX * extentY));
			successFlag = successValue3 && successFlag;
			;
		} else {
			/* begin success: */
			successValue4 = (extentX == 16) && ((extentY == 16) && (depth == 1));
			successFlag = successValue4 && successFlag;
			/* begin success: */
			successValue5 = (offsetX >= -16) && (offsetX <= 0);
			successFlag = successValue5 && successFlag;
			/* begin success: */
			successValue6 = (offsetY >= -16) && (offsetY <= 0);
			successFlag = successValue6 && successFlag;
			/* begin success: */
			successValue7 = (((bitsObj & 1) == 0) && (((((usqInt) (longAt(bitsObj))) >> 8) & 15) == 6)) && ((lengthOf(bitsObj)) == 16);
			successFlag = successValue7 && successFlag;
			cursorBitsIndex = bitsObj + BaseHeaderSize;
			;
		}
	}
	if (argumentCount == 1) {
		/* begin success: */
		successValue10 = (((maskObj & 1) == 0) && (((((usqInt) (longAt(maskObj))) >> 8) & 15) <= 4)) && ((lengthOf(maskObj)) >= 5);
		successFlag = successValue10 && successFlag;
		if (successFlag) {
			bitsObj = longAt((maskObj + BaseHeaderSize) + (0 << ShiftForWord));
			extentX = fetchIntegerofObject(1, maskObj);
			extentY = fetchIntegerofObject(2, maskObj);
			depth = fetchIntegerofObject(3, maskObj);
		}
		if (successFlag) {
			/* begin success: */
			successValue8 = (extentX == 16) && ((extentY == 16) && (depth == 1));
			successFlag = successValue8 && successFlag;
			/* begin success: */
			successValue9 = (((bitsObj & 1) == 0) && (((((usqInt) (longAt(bitsObj))) >> 8) & 15) == 6)) && ((lengthOf(bitsObj)) == 16);
			successFlag = successValue9 && successFlag;
			maskBitsIndex = bitsObj + BaseHeaderSize;
		}
	}
	if (successFlag) {
		if (argumentCount == 0) {
			if (depth == 32) {
				if (!(ioSetCursorARGB(cursorBitsIndex, extentX, extentY, offsetX, offsetY))) {
					/* begin success: */
					successFlag = 0 && successFlag;
					return null;
				}
			} else {
				ioSetCursor(cursorBitsIndex, offsetX, offsetY);
			}
		} else {
			ioSetCursorWithMask(cursorBitsIndex, maskBitsIndex, offsetX, offsetY);
		}
		/* begin pop: */
		stackPointer -= argumentCount * BytesPerWord;
	}
}


/*	Record the system Display object in the specialObjectsTable. */

sqInt primitiveBeDisplay(void) {
    sqInt rcvr;
    sqInt oop;
    sqInt successValue;

	rcvr = longAt(stackPointer);
	/* begin success: */
	successValue = (((rcvr & 1) == 0) && (((((usqInt) (longAt(rcvr))) >> 8) & 15) <= 4)) && ((lengthOf(rcvr)) >= 4);
	successFlag = successValue && successFlag;
	if (successFlag) {
		/* begin storePointer:ofObject:withValue: */
		oop = specialObjectsOop;
		if ((((usqInt) oop)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(oop, rcvr);
		}
		longAtput((oop + BaseHeaderSize) + (TheDisplay << ShiftForWord), rcvr);
	}
}


/*	make the basic beep noise */

sqInt primitiveBeep(void) {
	ioBeep();
}

sqInt primitiveBitAnd(void) {
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt object;
    sqInt sp;
    sqInt top;
    sqInt top1;
    sqInt top2;
    sqInt top11;

	/* begin popPos32BitInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	top = top1;
	integerArgument = positive32BitValueOf(top);
	/* begin popPos32BitInteger */
	/* begin popStack */
	top11 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	top2 = top11;
	integerReceiver = positive32BitValueOf(top2);
	if (successFlag) {
		/* begin push: */
		object = positive32BitIntegerFor(integerReceiver & integerArgument);
		longAtput(sp = stackPointer + BytesPerWord, object);
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
	}
}

sqInt primitiveBitOr(void) {
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt object;
    sqInt sp;
    sqInt top;
    sqInt top1;
    sqInt top2;
    sqInt top11;

	/* begin popPos32BitInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	top = top1;
	integerArgument = positive32BitValueOf(top);
	/* begin popPos32BitInteger */
	/* begin popStack */
	top11 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	top2 = top11;
	integerReceiver = positive32BitValueOf(top2);
	if (successFlag) {
		/* begin push: */
		object = positive32BitIntegerFor(integerReceiver | integerArgument);
		longAtput(sp = stackPointer + BytesPerWord, object);
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
	}
}

sqInt primitiveBitShift(void) {
    sqInt integerArgument;
    sqInt shifted;
    sqInt integerReceiver;
    sqInt integerPointer;
    sqInt object;
    sqInt sp;
    sqInt top;
    sqInt top2;
    sqInt top1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integerArgument = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerArgument = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	/* begin popPos32BitInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	top2 = top1;
	integerReceiver = positive32BitValueOf(top2);
	if (successFlag) {
		if (integerArgument >= 0) {
			/* begin success: */
			successFlag = (integerArgument <= 31) && successFlag;
			shifted = integerReceiver << integerArgument;
			/* begin success: */
			successFlag = ((((usqInt) shifted) >> integerArgument) == integerReceiver) && successFlag;
		} else {
			/* begin success: */
			successFlag = (integerArgument >= -31) && successFlag;
			shifted = ((integerArgument < 0) ? ((usqInt) integerReceiver >> -integerArgument) : ((usqInt) integerReceiver << integerArgument));
		}
	}
	if (successFlag) {
		/* begin push: */
		object = positive32BitIntegerFor(shifted);
		longAtput(sp = stackPointer + BytesPerWord, object);
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
	}
}

sqInt primitiveBitXor(void) {
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt object;
    sqInt sp;
    sqInt top;
    sqInt top1;
    sqInt top2;
    sqInt top11;

	/* begin popPos32BitInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	top = top1;
	integerArgument = positive32BitValueOf(top);
	/* begin popPos32BitInteger */
	/* begin popStack */
	top11 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	top2 = top11;
	integerReceiver = positive32BitValueOf(top2);
	if (successFlag) {
		/* begin push: */
		object = positive32BitIntegerFor(integerReceiver ^ integerArgument);
		longAtput(sp = stackPointer + BytesPerWord, object);
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
	}
}

sqInt primitiveBlockCopy(void) {
    sqInt methodContext;
    sqInt context;
    sqInt initialIP;
    sqInt newContext;
    sqInt contextSize;
    sqInt header;
    sqInt oop;
    sqInt sp;

	context = longAt(stackPointer - (1 * BytesPerWord));
	if (((longAt((context + BaseHeaderSize) + (MethodIndex << ShiftForWord))) & 1)) {

		/* context is a block; get the context of its enclosing method */

		methodContext = longAt((context + BaseHeaderSize) + (HomeIndex << ShiftForWord));
	} else {
		methodContext = context;
	}
	/* begin sizeBitsOf: */
	header = longAt(methodContext);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		contextSize = (longAt(methodContext - (BytesPerWord * 2))) & LongSizeMask;
		goto l1;
	} else {
		contextSize = header & SizeMask;
		goto l1;
	}
l1:	/* end sizeBitsOf: */;

	/* context is no longer needed and is not preserved across allocation */
	/* remap methodContext in case GC happens during allocation */

	context = null;
	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = methodContext;
	newContext = instantiateContextsizeInBytes(longAt((specialObjectsOop + BaseHeaderSize) + (ClassBlockContext << ShiftForWord)), contextSize);
	/* begin popRemappableOop */
	oop = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	methodContext = oop;

	/* Was instructionPointer + 3, but now it's greater by 1 due to preIncrement */
	/* Assume: have just allocated a new context; it must be young.
	 Thus, can use uncheck stores. See the comment in fetchContextRegisters. */

	initialIP = (((((instructionPointer + 1) + 3) - (method + BaseHeaderSize)) << 1) | 1);
	longAtput((newContext + BaseHeaderSize) + (InitialIPIndex << ShiftForWord), initialIP);
	longAtput((newContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord), initialIP);
	/* begin storeStackPointerValue:inContext: */
	longAtput((newContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord), ((0 << 1) | 1));
	longAtput((newContext + BaseHeaderSize) + (BlockArgumentCountIndex << ShiftForWord), longAt(stackPointer - (0 * BytesPerWord)));
	longAtput((newContext + BaseHeaderSize) + (HomeIndex << ShiftForWord), methodContext);
	longAtput((newContext + BaseHeaderSize) + (SenderIndex << ShiftForWord), nilObj);
	/* begin pop:thenPush: */
	longAtput(sp = stackPointer - ((2 - 1) * BytesPerWord), newContext);
	stackPointer = sp;
}


/*	Reports bytes available at this moment. For more meaningful 
	results, calls to this primitive should be preceeded by a full 
	or incremental garbage collection. */

sqInt primitiveBytesLeft(void) {
    sqInt aBool;
    sqInt sp;
    sqInt integerVal;
    sqInt sp1;

	if (argumentCount == 0) {
		/* begin pop:thenPushInteger: */
		longAtput(sp = stackPointer - ((1 - 1) * BytesPerWord), ((((longAt(freeBlock)) & AllButTypeMask) << 1) | 1));
		stackPointer = sp;
		return null;
	}
	if (argumentCount == 1) {
		/* begin booleanValueOf: */
		if ((longAt(stackPointer)) == trueObj) {
			aBool = 1;
			goto l1;
		}
		if ((longAt(stackPointer)) == falseObj) {
			aBool = 0;
			goto l1;
		}
		successFlag = 0;
		aBool = null;
	l1:	/* end booleanValueOf: */;
		if (!(successFlag)) {
			return null;
		}
		/* begin pop:thenPushInteger: */
		integerVal = ((longAt(freeBlock)) & AllButTypeMask) + (sqMemoryExtraBytesLeft(aBool));
		longAtput(sp1 = stackPointer - ((2 - 1) * BytesPerWord), ((integerVal << 1) | 1));
		stackPointer = sp1;
		return null;
	}
	/* begin primitiveFail */
	successFlag = 0;
	return null;
}


/*	Perform a function call to a foreign function.
	Only invoked from method containing explicit external call spec.
	Due to this we use the pluggable prim mechanism explicitly here
	(the first literal of any FFI spec'ed method is an ExternalFunction
	and not an array as used in the pluggable primitive mechanism). */

sqInt primitiveCalloutToFFI(void) {
    static char *functionName = "primitiveCallout";
    static char *moduleName = "SqueakFFIPrims";
    static void *function = 0;

	if (function == 0) {
		function = ioLoadExternalFunctionOfLengthFromModuleOfLength(oopForPointer(functionName), 16, oopForPointer(moduleName), 14);
		if (function == 0) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	return ((sqInt (*)(void))function)();
}


/*	Primitive. Change the class of the receiver into the class of the argument given that the format of the receiver matches the format of the argument's class. Fail if receiver or argument are SmallIntegers, or the receiver is an instance of a compact class and the argument isn't, or when the argument's class is compact and the receiver isn't, or when the format of the receiver is different from the format of the argument's class, or when the arguments class is fixed and the receiver's size differs from the size that an instance of the argument's class should have. */

sqInt primitiveChangeClass(void) {
    sqInt arg;
    sqInt argClass;
    sqInt rcvr;
    sqInt oop;
    sqInt oop1;
    sqInt ccIndex;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * BytesPerWord));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		arg = null;
		goto l1;
	}
	arg = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * BytesPerWord));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rcvr = null;
		goto l2;
	}
	rcvr = oop1;
l2:	/* end stackObjectValue: */;
	/* begin fetchClassOf: */
	if ((arg & 1)) {
		argClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l3;
	}
	ccIndex = (((usqInt) (longAt(arg))) >> 12) & 31;
	if (ccIndex == 0) {
		argClass = (longAt(arg - BaseHeaderSize)) & AllButTypeMask;
		goto l3;
	} else {
		argClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	changeClassOfto(rcvr, argClass);
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * BytesPerWord;
	}
	return null;
}


/*	Primitive. Change the class of the receiver into the class of the argument given that the format of the receiver matches the format of the argument's class. Fail if receiver or argument are SmallIntegers, or the receiver is an instance of a compact class and the argument isn't, or when the argument's class is compact and the receiver isn't, or when the format of the receiver is different from the format of the argument's class, or when the arguments class is fixed and the receiver's size differs from the size that an instance of the argument's class should have. */

EXPORT(sqInt) primitiveChangeClassWithClass(void) {
    sqInt argClass;
    sqInt rcvr;
    sqInt oop;
    sqInt oop1;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * BytesPerWord));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		argClass = null;
		goto l1;
	}
	argClass = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * BytesPerWord));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rcvr = null;
		goto l2;
	}
	rcvr = oop1;
l2:	/* end stackObjectValue: */;
	changeClassOfto(rcvr, argClass);
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * BytesPerWord;
	}
	return null;
}

sqInt primitiveClass(void) {
    sqInt instance;
    sqInt oop;
    sqInt sp;
    sqInt ccIndex;

	instance = longAt(stackPointer);
	/* begin pop:thenPush: */
	/* begin fetchClassOf: */
	if ((instance & 1)) {
		oop = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(instance))) >> 12) & 31;
	if (ccIndex == 0) {
		oop = (longAt(instance - BaseHeaderSize)) & AllButTypeMask;
		goto l1;
	} else {
		oop = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	longAtput(sp = stackPointer - (((argumentCount + 1) - 1) * BytesPerWord), oop);
	stackPointer = sp;
}


/*	When called with a single string argument, post the string to 
	the clipboard. When called with zero arguments, return a 
	string containing the current clipboard contents. */

sqInt primitiveClipboardText(void) {
    sqInt sz;
    sqInt s;
    sqInt sp;

	if (argumentCount == 1) {
		s = longAt(stackPointer);
		if (!(((s & 1) == 0) && (((((usqInt) (longAt(s))) >> 8) & 15) >= 8))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		if (successFlag) {
			sz = stSizeOf(s);
			clipboardWriteFromAt(sz, s + BaseHeaderSize, 0);
			/* begin pop: */
			stackPointer -= 1 * BytesPerWord;
		}
	} else {
		sz = clipboardSize();
		if (!(sufficientSpaceToAllocate(sz))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		s = instantiateClassindexableSize(longAt((specialObjectsOop + BaseHeaderSize) + (ClassString << ShiftForWord)), sz);
		clipboardReadIntoAt(sz, s + BaseHeaderSize, 0);
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((1 - 1) * BytesPerWord), s);
		stackPointer = sp;
	}
}


/*	Return a shallow copy of the receiver. */

sqInt primitiveClone(void) {
    sqInt newCopy;
    sqInt sp;

	newCopy = clone(longAt(stackPointer));
	if (newCopy == 0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin pop:thenPush: */
	longAtput(sp = stackPointer - ((1 - 1) * BytesPerWord), newCopy);
	stackPointer = sp;
}

sqInt primitiveClosureCopyWithCopiedValues(void) {
    sqInt copiedValues;
    sqInt numCopiedValues;
    sqInt i;
    sqInt numArgs;
    sqInt newClosure;
    sqInt integerPointer;
    sqInt successValue;
    sqInt sz;
    sqInt header;
    sqInt initialIP;
    sqInt newClosure1;
    sqInt sp;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		numArgs = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		numArgs = 0;
		goto l1;
	}
	numArgs = null;
l1:	/* end stackIntegerValue: */;
	copiedValues = longAt(stackPointer);
	/* begin success: */
	successValue = (fetchClassOf(copiedValues)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassArray << ShiftForWord)));
	successFlag = successValue && successFlag;
	if (!(successFlag)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin fetchWordLengthOf: */
	/* begin sizeBitsOf: */
	header = longAt(copiedValues);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(copiedValues - (BytesPerWord * 2))) & LongSizeMask;
		goto l2;
	} else {
		sz = header & SizeMask;
		goto l2;
	}
l2:	/* end sizeBitsOf: */;
	numCopiedValues = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
	/* begin closureNumArgs:instructionPointer:numCopiedValues: */
	initialIP = (instructionPointer + 2) - (method + BaseHeaderSize);
	newClosure1 = instantiateSmallClasssizeInBytes(longAt((specialObjectsOop + BaseHeaderSize) + (ClassBlockClosure << ShiftForWord)), (BytesPerWord * (ClosureFirstCopiedValueIndex + numCopiedValues)) + BaseHeaderSize);
	longAtput((newClosure1 + BaseHeaderSize) + (ClosureStartPCIndex << ShiftForWord), ((initialIP << 1) | 1));
	longAtput((newClosure1 + BaseHeaderSize) + (ClosureNumArgsIndex << ShiftForWord), ((numArgs << 1) | 1));
	newClosure = newClosure1;
	longAtput((newClosure + BaseHeaderSize) + (ClosureOuterContextIndex << ShiftForWord), longAt(stackPointer - (2 * BytesPerWord)));
	if (numCopiedValues > 0) {

		/* Allocation may have done a GC and copiedValues may have moved. */

		copiedValues = longAt(stackPointer);
		for (i = 0; i <= (numCopiedValues - 1); i += 1) {
			longAtput((newClosure + BaseHeaderSize) + ((i + ClosureFirstCopiedValueIndex) << ShiftForWord), longAt((copiedValues + BaseHeaderSize) + (i << ShiftForWord)));
		}
	}
	/* begin pop:thenPush: */
	longAtput(sp = stackPointer - ((3 - 1) * BytesPerWord), newClosure);
	stackPointer = sp;
}

sqInt primitiveClosureValue(void) {
    sqInt blockArgumentCount;
    sqInt closureMethod;
    sqInt blockClosure;
    sqInt outerContext;

	blockClosure = longAt(stackPointer - (argumentCount * BytesPerWord));
	blockArgumentCount = ((longAt((blockClosure + BaseHeaderSize) + (ClosureNumArgsIndex << ShiftForWord))) >> 1);
	if (!(argumentCount == blockArgumentCount)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	outerContext = longAt((blockClosure + BaseHeaderSize) + (ClosureOuterContextIndex << ShiftForWord));
	if (!(((outerContext & 1) == 0) && ((((((usqInt) (longAt(outerContext))) >> 12) & 31) == 13) || ((((((usqInt) (longAt(outerContext))) >> 12) & 31) == 14) || (((((usqInt) (longAt(outerContext))) >> 12) & 31) == 4))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}

	/* Check if the closure's method is actually a CompiledMethod. */

	closureMethod = longAt((outerContext + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	if (!(((closureMethod & 1) == 0) && (((((usqInt) (longAt(closureMethod))) >> 8) & 15) >= 12))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	activateNewClosureMethod(blockClosure);
	/* begin quickCheckForInterrupts */
	if ((interruptCheckCounter -= 1) <= 0) {
		checkForInterrupts();
	}
}


/*	An exact clone of primitiveClosureValue except that this version will not
	 check for interrupts on stack overflow. */

sqInt primitiveClosureValueNoContextSwitch(void) {
    sqInt blockArgumentCount;
    sqInt closureMethod;
    sqInt blockClosure;
    sqInt outerContext;

	blockClosure = longAt(stackPointer - (argumentCount * BytesPerWord));
	blockArgumentCount = ((longAt((blockClosure + BaseHeaderSize) + (ClosureNumArgsIndex << ShiftForWord))) >> 1);
	if (!(argumentCount == blockArgumentCount)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	outerContext = longAt((blockClosure + BaseHeaderSize) + (ClosureOuterContextIndex << ShiftForWord));
	if (!(((outerContext & 1) == 0) && ((((((usqInt) (longAt(outerContext))) >> 12) & 31) == 13) || ((((((usqInt) (longAt(outerContext))) >> 12) & 31) == 14) || (((((usqInt) (longAt(outerContext))) >> 12) & 31) == 4))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}

	/* Check if the closure's method is actually a CompiledMethod. */

	closureMethod = longAt((outerContext + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	if (!(((closureMethod & 1) == 0) && (((((usqInt) (longAt(closureMethod))) >> 8) & 15) >= 12))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	activateNewClosureMethod(blockClosure);
}

sqInt primitiveClosureValueWithArgs(void) {
    sqInt blockArgumentCount;
    sqInt cntxSize;
    sqInt closureMethod;
    sqInt arraySize;
    sqInt blockClosure;
    sqInt outerContext;
    sqInt argumentArray;
    sqInt index;
    sqInt sp;
    sqInt sz;
    sqInt header;
    sqInt sz1;
    sqInt header1;
    sqInt top;

	argumentArray = longAt(stackPointer);
	if (!(((argumentArray & 1) == 0) && (((((usqInt) (longAt(argumentArray))) >> 8) & 15) == 2))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin fetchWordLengthOf: */
	/* begin sizeBitsOf: */
	header = longAt(argumentArray);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(argumentArray - (BytesPerWord * 2))) & LongSizeMask;
		goto l1;
	} else {
		sz = header & SizeMask;
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	arraySize = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
	/* begin fetchWordLengthOf: */
	/* begin sizeBitsOf: */
	header1 = longAt(activeContext);
	if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(activeContext - (BytesPerWord * 2))) & LongSizeMask;
		goto l2;
	} else {
		sz1 = header1 & SizeMask;
		goto l2;
	}
l2:	/* end sizeBitsOf: */;
	cntxSize = ((usqInt) (sz1 - BaseHeaderSize)) >> ShiftForWord;
	if (!(((((usqInt) ((stackPointer - activeContext) - BaseHeaderSize)) >> ShiftForWord) + arraySize) < cntxSize)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	blockClosure = longAt(stackPointer - (argumentCount * BytesPerWord));
	blockArgumentCount = ((longAt((blockClosure + BaseHeaderSize) + (ClosureNumArgsIndex << ShiftForWord))) >> 1);
	if (!(arraySize == blockArgumentCount)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	outerContext = longAt((blockClosure + BaseHeaderSize) + (ClosureOuterContextIndex << ShiftForWord));
	if (!(((outerContext & 1) == 0) && ((((((usqInt) (longAt(outerContext))) >> 12) & 31) == 13) || ((((((usqInt) (longAt(outerContext))) >> 12) & 31) == 14) || (((((usqInt) (longAt(outerContext))) >> 12) & 31) == 4))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}

	/* Check if the closure's method is actually a CompiledMethod. */

	closureMethod = longAt((outerContext + BaseHeaderSize) + (MethodIndex << ShiftForWord));
	if (!(((closureMethod & 1) == 0) && (((((usqInt) (longAt(closureMethod))) >> 8) & 15) >= 12))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	index = 1;
	while (index <= arraySize) {
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, longAt((argumentArray + BaseHeaderSize) + ((index - 1) << ShiftForWord)));
		stackPointer = sp;
		index += 1;
	}
	argumentCount = arraySize;
	activateNewClosureMethod(blockClosure);
	/* begin quickCheckForInterrupts */
	if ((interruptCheckCounter -= 1) <= 0) {
		checkForInterrupts();
	}
}


/*	Fill the receiver, which must be an indexable bytes or words 
	objects, with the given integer value. */

sqInt primitiveConstantFill(void) {
    usqInt end;
    usqInt i;
    sqInt fillValue;
    sqInt rcvr;
    sqInt rcvrIsBytes;
    sqInt successValue;
    sqInt successValue1;

	fillValue = positive32BitValueOf(longAt(stackPointer));
	rcvr = longAt(stackPointer - (1 * BytesPerWord));
	/* begin success: */
	successValue1 = ((rcvr & 1) == 0) && (isWordsOrBytesNonInt(rcvr));
	successFlag = successValue1 && successFlag;
	rcvrIsBytes = ((rcvr & 1) == 0) && (((((usqInt) (longAt(rcvr))) >> 8) & 15) >= 8);
	if (rcvrIsBytes) {
		/* begin success: */
		successValue = (fillValue >= 0) && (fillValue <= 255);
		successFlag = successValue && successFlag;
	}
	if (successFlag) {
		end = rcvr + (sizeBitsOf(rcvr));
		i = rcvr + BaseHeaderSize;
		if (rcvrIsBytes) {
			while (i < end) {
				byteAtput(i, fillValue);
				i += 1;
			}
		} else {
			while (i < end) {
				long32Atput(i, fillValue);
				i += 4;
			}
		}
		/* begin pop: */
		stackPointer -= 1 * BytesPerWord;
	}
}


/*	Primitive. Copy the state of the receiver from the argument. 
		Fail if receiver and argument are of a different class. 
		Fail if the receiver or argument are non-pointer objects.
		Fail if receiver and argument have different lengths (for indexable objects).
	 */

sqInt primitiveCopyObject(void) {
    sqInt arg;
    sqInt length;
    sqInt i;
    sqInt rcvr;
    sqInt oop;
    sqInt oop1;
    sqInt header;
    sqInt sz;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (0 * BytesPerWord));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		arg = null;
		goto l1;
	}
	arg = oop;
l1:	/* end stackObjectValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (1 * BytesPerWord));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rcvr = null;
		goto l2;
	}
	rcvr = oop1;
l2:	/* end stackObjectValue: */;
	if (!successFlag) {
		return null;
	}
	if (!(((rcvr & 1) == 0) && (((((usqInt) (longAt(rcvr))) >> 8) & 15) <= 4))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((fetchClassOf(rcvr)) == (fetchClassOf(arg)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin lengthOf: */
	header = longAt(rcvr);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(rcvr - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz = header & SizeMask;
	}
	sz -= header & Size4Bit;
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		length = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
		goto l3;
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		length = ((usqInt) (sz - BaseHeaderSize)) >> 2;
		goto l3;
	} else {
		length = (sz - BaseHeaderSize) - (((((usqInt) header) >> 8) & 15) & 3);
		goto l3;
	}
	length = null;
l3:	/* end lengthOf: */;
	if (!(length == (lengthOf(arg)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	for (i = 0; i <= (length - 1); i += 1) {
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) rcvr)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(rcvr, longAt((arg + BaseHeaderSize) + (i << ShiftForWord)));
		}
		longAtput((rcvr + BaseHeaderSize) + (i << ShiftForWord), longAt((arg + BaseHeaderSize) + (i << ShiftForWord)));
	}
	/* begin pop: */
	stackPointer -= 1 * BytesPerWord;
}


/*	Set or clear the flag that controls whether modifications of 
	the Display object are propagated to the underlying 
	platform's screen. */

sqInt primitiveDeferDisplayUpdates(void) {
    sqInt flag;

	flag = longAt(stackPointer);
	if (flag == trueObj) {
		deferDisplayUpdates = 1;
	} else {
		if (flag == falseObj) {
			deferDisplayUpdates = 0;
		} else {
			/* begin primitiveFail */
			successFlag = 0;
		}
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * BytesPerWord;
	}
}


/*	Pass in a non-negative value to disable the architectures powermanager if any, zero to enable. This is a named (not numbered) primitive in the null module (ie the VM) */

EXPORT(sqInt) primitiveDisablePowerManager(void) {
    sqInt integer;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integer = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integer = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	if (successFlag) {
		ioDisablePowerManager(integer);
		/* begin pop: */
		stackPointer -= 1 * BytesPerWord;
	}
}

sqInt primitiveDiv(void) {
    sqInt quotient;
    sqInt sp;

	quotient = doPrimitiveDivby(longAt(stackPointer - (1 * BytesPerWord)), longAt(stackPointer));
	/* begin pop2AndPushIntegerIfOK: */
	if (successFlag) {
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) quotient)) ^ ((((int) quotient)) << 1)) >= 0)
# else
			((quotient >= -1073741824) && (quotient <= 1073741823))
# endif  // SQ_HOST32
		) {
			/* begin pop:thenPush: */
			longAtput(sp = stackPointer - ((2 - 1) * BytesPerWord), ((quotient << 1) | 1));
			stackPointer = sp;
		} else {
			successFlag = 0;
		}
	}
}

sqInt primitiveDivide(void) {
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt integerPointer;
    sqInt integerPointer1;
    sqInt sp;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integerReceiver = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerReceiver = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		integerArgument = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerArgument = 0;
		goto l2;
	}
l2:	/* end checkedIntegerValueOf: */;
	if ((integerArgument != 0) && ((integerReceiver % integerArgument) == 0)) {
		/* begin pop2AndPushIntegerIfOK: */
		if (successFlag) {
			if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
				(((((int) (integerReceiver / integerArgument))) ^ ((((int) (integerReceiver / integerArgument))) << 1)) >= 0)
# else
				(((integerReceiver / integerArgument) >= -1073741824) && ((integerReceiver / integerArgument) <= 1073741823))
# endif  // SQ_HOST32
			) {
				/* begin pop:thenPush: */
				longAtput(sp = stackPointer - ((2 - 1) * BytesPerWord), (((integerReceiver / integerArgument) << 1) | 1));
				stackPointer = sp;
			} else {
				successFlag = 0;
			}
		}
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
}

EXPORT(sqInt) primitiveDoDialog(void) {
	ioDoDialog();
}


/*	Simulate an primitiveExternalCall invocation (e.g. for the Debugger).  Do not cache anything.
	 e.g. ContextPart>>tryNamedPrimitiveIn: aCompiledMethod for: aReceiver withArgs: arguments */

sqInt primitiveDoNamedPrimitiveWithArgs(void) {
    sqInt functionName;
    sqInt functionLength;
    sqInt methodArg;
    sqInt moduleName;
    sqInt arraySize;
    sqInt methodHeader;
    sqInt spec;
    sqInt moduleLength;
    sqInt argumentArray;
    sqInt index;
    void (*addr)();
    sqInt successValue;
    sqInt sp;
    sqInt sp1;
    sqInt sz;
    sqInt header;
    sqInt successValue1;
    sqInt oop;
    sqInt successValue2;
    sqInt oop1;
    sqInt header1;
    sqInt sz1;
    sqInt cntxSize;
    sqInt header2;
    sqInt sz2;
    sqInt oop2;
    sqInt cl;
    sqInt ccIndex;

	argumentArray = longAt(stackPointer);
	if (!(((argumentArray & 1) == 0) && (((((usqInt) (longAt(argumentArray))) >> 8) & 15) == 2))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin fetchWordLengthOf: */
	/* begin sizeBitsOf: */
	header = longAt(argumentArray);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(argumentArray - (BytesPerWord * 2))) & LongSizeMask;
		goto l1;
	} else {
		sz = header & SizeMask;
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	arraySize = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
	/* begin success: */
	/* begin roomToPushNArgs: */
	if (((longAt((method + BaseHeaderSize) + (HeaderIndex << ShiftForWord))) & LargeContextBit) != 0) {
		cntxSize = (((sqInt) LargeContextSize >> 2)) - ReceiverIndex;
	} else {
		cntxSize = (((sqInt) SmallContextSize >> 2)) - ReceiverIndex;
	}
	successValue1 = ((((usqInt) ((stackPointer - activeContext) - BaseHeaderSize)) >> ShiftForWord) + arraySize) <= cntxSize;
	successFlag = successValue1 && successFlag;
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (2 * BytesPerWord));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		methodArg = null;
		goto l2;
	}
	methodArg = oop;
l2:	/* end stackObjectValue: */;
	if (!(successFlag)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(((((usqInt) (longAt(methodArg))) >> 8) & 15) >= 12)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	methodHeader = longAt((methodArg + BaseHeaderSize) + (HeaderIndex << ShiftForWord));
	if (!(((((usqInt) methodHeader) >> 10) & 255) > 2)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin assertClassOf:is: */
	oop2 = spec = longAt((methodArg + BaseHeaderSize) + (1 << ShiftForWord));
	if ((oop2 & 1)) {
		successFlag = 0;
		goto l5;
	}
	ccIndex = (((usqInt) (longAt(oop2))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(oop2 - BaseHeaderSize)) & AllButTypeMask;
	} else {
		cl = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
	}
	/* begin success: */
	successFlag = (cl == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassArray << ShiftForWord)))) && successFlag;
l5:	/* end assertClassOf:is: */;
	if (!(successFlag && (((lengthOf(spec)) == 4) && ((primitiveIndexOfMethodHeader(methodHeader)) == 117)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(((((usqInt) methodHeader) >> 25) & 15) == arraySize)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	moduleName = longAt((spec + BaseHeaderSize) + (0 << ShiftForWord));
	if (moduleName == nilObj) {
		moduleLength = 0;
	} else {
		/* begin success: */
		successValue = ((moduleName & 1) == 0) && (((((usqInt) (longAt(moduleName))) >> 8) & 15) >= 8);
		successFlag = successValue && successFlag;
		/* begin lengthOf: */
		header1 = longAt(moduleName);
		/* begin lengthOf:baseHeader:format: */
		if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
			sz1 = (longAt(moduleName - (BytesPerWord * 2))) & LongSizeMask;
		} else {
			sz1 = header1 & SizeMask;
		}
		sz1 -= header1 & Size4Bit;
		if (((((usqInt) header1) >> 8) & 15) <= 4) {
			moduleLength = ((usqInt) (sz1 - BaseHeaderSize)) >> ShiftForWord;
			goto l3;
		}
		if (((((usqInt) header1) >> 8) & 15) < 8) {
			moduleLength = ((usqInt) (sz1 - BaseHeaderSize)) >> 2;
			goto l3;
		} else {
			moduleLength = (sz1 - BaseHeaderSize) - (((((usqInt) header1) >> 8) & 15) & 3);
			goto l3;
		}
		moduleLength = null;
	l3:	/* end lengthOf: */;
		;
	}
	functionName = longAt((spec + BaseHeaderSize) + (1 << ShiftForWord));
	/* begin success: */
	successValue2 = ((functionName & 1) == 0) && (((((usqInt) (longAt(functionName))) >> 8) & 15) >= 8);
	successFlag = successValue2 && successFlag;
	/* begin lengthOf: */
	header2 = longAt(functionName);
	/* begin lengthOf:baseHeader:format: */
	if ((header2 & TypeMask) == HeaderTypeSizeAndClass) {
		sz2 = (longAt(functionName - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz2 = header2 & SizeMask;
	}
	sz2 -= header2 & Size4Bit;
	if (((((usqInt) header2) >> 8) & 15) <= 4) {
		functionLength = ((usqInt) (sz2 - BaseHeaderSize)) >> ShiftForWord;
		goto l4;
	}
	if (((((usqInt) header2) >> 8) & 15) < 8) {
		functionLength = ((usqInt) (sz2 - BaseHeaderSize)) >> 2;
		goto l4;
	} else {
		functionLength = (sz2 - BaseHeaderSize) - (((((usqInt) header2) >> 8) & 15) & 3);
		goto l4;
	}
	functionLength = null;
l4:	/* end lengthOf: */;
	if (!(successFlag)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	addr = ioLoadExternalFunctionOfLengthFromModuleOfLength(functionName + BaseHeaderSize, functionLength, moduleName + BaseHeaderSize, moduleLength);
	if (addr == 0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin pop: */
	stackPointer -= 1 * BytesPerWord;
	argumentCount = arraySize;
	index = 1;
	while (index <= arraySize) {
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, longAt((argumentArray + BaseHeaderSize) + ((index - 1) << ShiftForWord)));
		stackPointer = sp;
		index += 1;
	}
	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = argumentArray;
	lkupClass = nilObj;
	callExternalPrimitive(addr);
	/* begin popRemappableOop */
	oop1 = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	argumentArray = oop1;
	if (!(successFlag)) {
		/* begin pop:thenPush: */
		longAtput(sp1 = stackPointer - ((arraySize - 1) * BytesPerWord), argumentArray);
		stackPointer = sp1;
		argumentCount = 3;
	}
}

sqInt primitiveDoPrimitiveWithArgs(void) {
    sqInt cntxSize;
    sqInt primIdx;
    sqInt arraySize;
    sqInt argumentArray;
    sqInt index;
    sqInt sp;
    sqInt sp1;
    sqInt sp2;
    sqInt sz;
    sqInt header;
    sqInt sz1;
    sqInt header1;
    sqInt integerPointer;
    sqInt oop;

	argumentArray = longAt(stackPointer);
	/* begin fetchWordLengthOf: */
	/* begin sizeBitsOf: */
	header = longAt(argumentArray);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(argumentArray - (BytesPerWord * 2))) & LongSizeMask;
		goto l1;
	} else {
		sz = header & SizeMask;
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	arraySize = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
	/* begin fetchWordLengthOf: */
	/* begin sizeBitsOf: */
	header1 = longAt(activeContext);
	if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(activeContext - (BytesPerWord * 2))) & LongSizeMask;
		goto l2;
	} else {
		sz1 = header1 & SizeMask;
		goto l2;
	}
l2:	/* end sizeBitsOf: */;
	cntxSize = ((usqInt) (sz1 - BaseHeaderSize)) >> ShiftForWord;
	/* begin success: */
	successFlag = (((((usqInt) ((stackPointer - activeContext) - BaseHeaderSize)) >> ShiftForWord) + arraySize) < cntxSize) && successFlag;
	if (!(((argumentArray & 1) == 0) && (((((usqInt) (longAt(argumentArray))) >> 8) & 15) == 2))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		primIdx = (integerPointer >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		primIdx = 0;
		goto l3;
	}
	primIdx = null;
l3:	/* end stackIntegerValue: */;
	if (!(successFlag)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin pop: */
	stackPointer -= 2 * BytesPerWord;
	primitiveIndex = primIdx;
	argumentCount = arraySize;
	index = 1;
	while (index <= argumentCount) {
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, longAt((argumentArray + BaseHeaderSize) + ((index - 1) << ShiftForWord)));
		stackPointer = sp;
		index += 1;
	}
	/* begin pushRemappableOop: */
	remapBuffer[remapBufferCount += 1] = argumentArray;
	lkupClass = nilObj;
	primitiveResponse();
	/* begin popRemappableOop */
	oop = remapBuffer[remapBufferCount];
	remapBufferCount -= 1;
	argumentArray = oop;
	if (!(successFlag)) {
		/* begin pop: */
		stackPointer -= arraySize * BytesPerWord;
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp1 = stackPointer + BytesPerWord, ((primIdx << 1) | 1));
		stackPointer = sp1;
		/* begin push: */
		longAtput(sp2 = stackPointer + BytesPerWord, argumentArray);
		stackPointer = sp2;
		argumentCount = 2;
	}
}

sqInt primitiveEqual(void) {
    sqInt integerArgument;
    sqInt result;
    sqInt integerReceiver;
    sqInt top;
    sqInt top1;
    sqInt sp;
    sqInt sp1;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerArgument = top;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerReceiver = top1;
	/* begin compare31or32Bits:equal: */
	if (((integerReceiver & 1)) && ((integerArgument & 1))) {
		result = integerReceiver == integerArgument;
		goto l1;
	}
	result = (positive32BitValueOf(integerReceiver)) == (positive32BitValueOf(integerArgument));
l1:	/* end compare31or32Bits:equal: */;
	/* begin checkBooleanResult: */
	if (successFlag) {
		/* begin pushBool: */
		if (result) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
	}
}


/*	is the receiver the same object as the argument? */

sqInt primitiveEquivalent(void) {
    sqInt thisObject;
    sqInt otherObject;
    sqInt top;
    sqInt top1;
    sqInt sp;
    sqInt sp1;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	otherObject = top;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	thisObject = top1;
	/* begin pushBool: */
	if (thisObject == otherObject) {
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, trueObj);
		stackPointer = sp;
	} else {
		/* begin push: */
		longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
		stackPointer = sp1;
	}
}


/*	receiver, args, then method are on top of stack. Execute method against receiver and args */

sqInt primitiveExecuteMethod(void) {
    sqInt top;
    sqInt primBits;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	newMethod = top;
	/* begin primitiveIndexOf: */
	primBits = (((usqInt) (longAt((newMethod + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 1) & 268435967;
	primitiveIndex = (primBits & 511) + (((usqInt) primBits) >> 19);
	/* begin success: */
	successFlag = ((argumentCount - 1) == ((((usqInt) (longAt((newMethod + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 25) & 15)) && successFlag;
	if (successFlag) {
		argumentCount -= 1;
		/* begin executeNewMethod */
		if (primitiveIndex > 0) {
			primitiveResponse();
			if (successFlag) {
				goto l1;
			}
		}
		activateNewMethod();
		/* begin quickCheckForInterrupts */
		if ((interruptCheckCounter -= 1) <= 0) {
			checkForInterrupts();
		}
	l1:	/* end executeNewMethod */;
	} else {
		/* begin unPop: */
		stackPointer += 1 * BytesPerWord;
	}
}


/*	receiver, argsArray, then method are on top of stack.  Execute method against receiver and args */

sqInt primitiveExecuteMethodArgsArray(void) {
    sqInt methodArgument;
    sqInt argCnt;
    sqInt argumentArray;
    sqInt top;
    sqInt top1;
    sqInt dst;
    sqInt in;
    sqInt lastIn;
    sqInt out;
    sqInt primBits;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	methodArgument = top;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	argumentArray = top1;
	if (!(((methodArgument & 1) == 0) && ((((((usqInt) (longAt(newMethod))) >> 8) & 15) >= 12) && (((argumentArray & 1) == 0) && (((((usqInt) (longAt(argumentArray))) >> 8) & 15) == 2))))) {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	argCnt = (((usqInt) (longAt((methodArgument + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 25) & 15;
	if (!(argCnt == (fetchWordLengthOf(argumentArray)))) {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin transfer:from:to: */
	dst = stackPointer + BytesPerWord;
	flag("Dan");
	in = (argumentArray + BaseHeaderSize) - BytesPerWord;
	lastIn = in + (argCnt * BytesPerWord);
	out = dst - BytesPerWord;
	while ((((usqInt) in)) < (((usqInt) lastIn))) {
		longAtput(out += BytesPerWord, longAt(in += BytesPerWord));
	}
	/* begin unPop: */
	stackPointer += argCnt * BytesPerWord;
	newMethod = methodArgument;
	/* begin primitiveIndexOf: */
	primBits = (((usqInt) (longAt((newMethod + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 1) & 268435967;
	primitiveIndex = (primBits & 511) + (((usqInt) primBits) >> 19);
	argumentCount = argCnt;
	/* begin executeNewMethod */
	if (primitiveIndex > 0) {
		primitiveResponse();
		if (successFlag) {
			goto l1;
		}
	}
	activateNewMethod();
	/* begin quickCheckForInterrupts */
	if ((interruptCheckCounter -= 1) <= 0) {
		checkForInterrupts();
	}
l1:	/* end executeNewMethod */;
	successFlag = 1;
}

sqInt primitiveExitToDebugger(void) {
	error("Exit to debugger at user request");
}


/*	Computes E raised to the receiver power. */

sqInt primitiveExp(void) {
    double  rcvr;

	rcvr = popFloat();
	if (successFlag) {
		pushFloat(exp(rcvr));
	} else {
		/* begin unPop: */
		stackPointer += 1 * BytesPerWord;
	}
}


/*	Exponent part of this float. */

sqInt primitiveExponent(void) {
    int  pwr;
    double  frac;
    double  rcvr;
    sqInt sp;

	rcvr = popFloat();
	if (successFlag) {
		frac = frexp(rcvr, &pwr);
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, (((pwr - 1) << 1) | 1));
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 1 * BytesPerWord;
	}
}


/*	Call an external primitive. The external primitive methods 
	contain as first literal an array consisting of: 
	* The module name (String | Symbol) 
	* The function name (String | Symbol) 
	* The session ID (SmallInteger) [OBSOLETE] 
	* The function index (Integer) in the externalPrimitiveTable 
	For fast failures the primitive index of any method where the 
	external prim is not found is rewritten in the method cache 
	with zero. This allows for ultra fast responses as long as the 
	method stays in the cache. 
	The fast failure response relies on lkupClass being properly 
	set. This is done in 
	#addToMethodCacheSel:class:method:primIndex: to 
	compensate for execution of methods that are looked up in a 
	superclass (such as in primitivePerformAt). 
	With the latest modifications (e.g., actually flushing the 
	function addresses from the VM), the session ID is obsolete. 
	But for backward compatibility it is still kept around. Also, a 
	failed lookup is reported specially. If a method has been 
	looked up and not been found, the function address is stored 
	as -1 (e.g., the SmallInteger -1 to distinguish from 
	16rFFFFFFFF which may be returned from the lookup). 
	It is absolutely okay to remove the rewrite if we run into any 
	problems later on. It has an approximate speed difference of 
	30% per failed primitive call which may be noticable but if, 
	for any reasons, we run into problems (like with J3) we can 
	always remove the rewrite. 
	 */

sqInt primitiveExternalCall(void) {
    sqInt functionName;
    sqInt functionLength;
    sqInt moduleName;
    sqInt moduleLength;
    sqInt index;
    sqInt lit;
    void * addr;
    sqInt successValue;
    sqInt successValue1;
    sqInt successValue2;
    sqInt header;
    sqInt sz;
    sqInt header1;
    sqInt sz1;

	/* begin success: */
	successFlag = (((((usqInt) (longAt((newMethod + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 10) & 255) > 0) && successFlag;
	if (!(successFlag)) {
		return null;
	}

	/* Check if it's an array of length 4 */

	lit = longAt((newMethod + BaseHeaderSize) + ((0 + LiteralStart) << ShiftForWord));
	/* begin success: */
	successValue1 = (((lit & 1) == 0) && (((((usqInt) (longAt(lit))) >> 8) & 15) == 2)) && ((lengthOf(lit)) == 4);
	successFlag = successValue1 && successFlag;
	if (!(successFlag)) {
		return null;
	}
	index = longAt((lit + BaseHeaderSize) + (3 << ShiftForWord));
	/* begin checkedIntegerValueOf: */
	if ((index & 1)) {
		index = (index >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	if (!(successFlag)) {
		return null;
	}
	if (index < 0) {
		rewriteMethodCacheSelclassprimIndex(messageSelector, lkupClass, 0);
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	if ((index > 0) && (index <= MaxExternalPrimitiveTableSize)) {
		addr = externalPrimitiveTable[index - 1];
		if (addr != 0) {
			rewriteMethodCacheSelclassprimIndexprimFunction(messageSelector, lkupClass, 1000 + index, addr);
			callExternalPrimitive(addr);
			return null;
		}
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	longAtput((lit + BaseHeaderSize) + (2 << ShiftForWord), ConstZero);
	longAtput((lit + BaseHeaderSize) + (3 << ShiftForWord), ConstZero);
	moduleName = longAt((lit + BaseHeaderSize) + (0 << ShiftForWord));
	if (moduleName == nilObj) {
		moduleLength = 0;
	} else {
		/* begin success: */
		successValue = ((moduleName & 1) == 0) && (((((usqInt) (longAt(moduleName))) >> 8) & 15) >= 8);
		successFlag = successValue && successFlag;
		/* begin lengthOf: */
		header = longAt(moduleName);
		/* begin lengthOf:baseHeader:format: */
		if ((header & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(moduleName - (BytesPerWord * 2))) & LongSizeMask;
		} else {
			sz = header & SizeMask;
		}
		sz -= header & Size4Bit;
		if (((((usqInt) header) >> 8) & 15) <= 4) {
			moduleLength = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
			goto l2;
		}
		if (((((usqInt) header) >> 8) & 15) < 8) {
			moduleLength = ((usqInt) (sz - BaseHeaderSize)) >> 2;
			goto l2;
		} else {
			moduleLength = (sz - BaseHeaderSize) - (((((usqInt) header) >> 8) & 15) & 3);
			goto l2;
		}
		moduleLength = null;
	l2:	/* end lengthOf: */;
		;
	}
	functionName = longAt((lit + BaseHeaderSize) + (1 << ShiftForWord));
	/* begin success: */
	successValue2 = ((functionName & 1) == 0) && (((((usqInt) (longAt(functionName))) >> 8) & 15) >= 8);
	successFlag = successValue2 && successFlag;
	/* begin lengthOf: */
	header1 = longAt(functionName);
	/* begin lengthOf:baseHeader:format: */
	if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(functionName - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz1 = header1 & SizeMask;
	}
	sz1 -= header1 & Size4Bit;
	if (((((usqInt) header1) >> 8) & 15) <= 4) {
		functionLength = ((usqInt) (sz1 - BaseHeaderSize)) >> ShiftForWord;
		goto l3;
	}
	if (((((usqInt) header1) >> 8) & 15) < 8) {
		functionLength = ((usqInt) (sz1 - BaseHeaderSize)) >> 2;
		goto l3;
	} else {
		functionLength = (sz1 - BaseHeaderSize) - (((((usqInt) header1) >> 8) & 15) & 3);
		goto l3;
	}
	functionLength = null;
l3:	/* end lengthOf: */;
	if (!(successFlag)) {
		return null;
	}

	/* Addr ~= 0 indicates we have a compat match later */

	addr = 0;
	if (moduleLength == 0) {

		/* Search the obsolete named primitive table for a match  */
		/* The returned value is the index into the obsolete primitive table. 
			If the index is found, use the 'C-style' version of the lookup.  */

		index = findObsoleteNamedPrimitivelength((pointerForOop(functionName)) + BaseHeaderSize, functionLength);
		if (!(index < 0)) {
			addr = ioLoadFunctionFrom(((char*) ((obsoleteNamedPrimitiveTable[index])[2])), ((char*) ((obsoleteNamedPrimitiveTable[index])[1])));
		}
	}
	if (addr == 0) {

		/* Only if no compat version was found */

		addr = ioLoadExternalFunctionOfLengthFromModuleOfLength(functionName + BaseHeaderSize, functionLength, moduleName + BaseHeaderSize, moduleLength);
	}
	if (addr == 0) {
		index = -1;
	} else {

		/* add the function to the external primitive table */

		index = addToExternalPrimitiveTable(addr);
	}
	/* begin success: */
	successFlag = (index >= 0) && successFlag;
	longAtput((lit + BaseHeaderSize) + (3 << ShiftForWord), ((index << 1) | 1));
	if (successFlag && (addr != 0)) {
		rewriteMethodCacheSelclassprimIndexprimFunction(messageSelector, lkupClass, 1000 + index, addr);
		callExternalPrimitive(addr);
	} else {
		rewriteMethodCacheSelclassprimIndex(messageSelector, lkupClass, 0);
	}
}

sqInt primitiveFail(void) {
	successFlag = 0;
}


/*	Primitive. Search up the context stack for the next method context marked for exception handling starting at the receiver. Return nil if none found */

sqInt primitiveFindHandlerContext(void) {
    sqInt nilOop;
    sqInt thisCntx;
    sqInt sp;
    sqInt top;
    sqInt sp1;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	thisCntx = top;
	nilOop = nilObj;
	do {
		if (isHandlerMarked(thisCntx)) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, thisCntx);
			stackPointer = sp;
			return null;
		}
		thisCntx = longAt((thisCntx + BaseHeaderSize) + (SenderIndex << ShiftForWord));
	} while(!(thisCntx == nilOop));
	/* begin push: */
	longAtput(sp1 = stackPointer + BytesPerWord, nilObj);
	stackPointer = sp1;
	return null;
}


/*	Primitive. Search up the context stack for the next method context marked for unwind handling from the receiver up to but not including the argument. Return nil if none found. */

sqInt primitiveFindNextUnwindContext(void) {
    sqInt nilOop;
    sqInt unwindMarked;
    sqInt thisCntx;
    sqInt aContext;
    sqInt sp;
    sqInt meth;
    sqInt header;
    sqInt pIndex;
    sqInt top;
    sqInt oop;
    sqInt sp1;
    sqInt primBits;
    sqInt top1;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	aContext = top;
	/* begin fetchPointer:ofObject: */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	oop = top1;
	thisCntx = longAt((oop + BaseHeaderSize) + (SenderIndex << ShiftForWord));
	nilOop = nilObj;
	while (!((thisCntx == aContext) || (thisCntx == nilOop))) {
		/* begin isUnwindMarked: */
		header = longAt(thisCntx);
		if (!(((((usqInt) header) >> 12) & 31) == 14)) {
			unwindMarked = 0;
			goto l1;
		}
		meth = longAt((thisCntx + BaseHeaderSize) + (MethodIndex << ShiftForWord));
		/* begin primitiveIndexOf: */
		primBits = (((usqInt) (longAt((meth + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 1) & 268435967;
		pIndex = (primBits & 511) + (((usqInt) primBits) >> 19);
		unwindMarked = pIndex == 198;
	l1:	/* end isUnwindMarked: */;
		if (unwindMarked) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, thisCntx);
			stackPointer = sp;
			return null;
		}
		thisCntx = longAt((thisCntx + BaseHeaderSize) + (SenderIndex << ShiftForWord));
	}
	/* begin push: */
	longAtput(sp1 = stackPointer + BytesPerWord, nilOop);
	stackPointer = sp1;
	return null;
}

sqInt primitiveFloatAdd(void) {
	return primitiveFloatAddtoArg(longAt(stackPointer - (1 * BytesPerWord)), longAt(stackPointer));
}

sqInt primitiveFloatAddtoArg(sqInt rcvrOop, sqInt argOop) {
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * BytesPerWord;
		pushFloat(rcvr + arg);
	}
}

sqInt primitiveFloatDivide(void) {
	return primitiveFloatDividebyArg(longAt(stackPointer - (1 * BytesPerWord)), longAt(stackPointer));
}

sqInt primitiveFloatDividebyArg(sqInt rcvrOop, sqInt argOop) {
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (successFlag) {
		/* begin success: */
		successFlag = (arg != 0.0) && successFlag;
		if (successFlag) {
			/* begin pop: */
			stackPointer -= 2 * BytesPerWord;
			pushFloat(rcvr / arg);
		}
	}
}

sqInt primitiveFloatEqual(void) {
    sqInt aBool;
    sqInt sp;
    sqInt sp1;

	aBool = primitiveFloatEqualtoArg(longAt(stackPointer - (1 * BytesPerWord)), longAt(stackPointer));
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * BytesPerWord;
		/* begin pushBool: */
		if (aBool) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
	}
}

sqInt primitiveFloatEqualtoArg(sqInt rcvrOop, sqInt argOop) {
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (successFlag) {
		return rcvr == arg;
	}
}

sqInt primitiveFloatGreaterthanArg(sqInt rcvrOop, sqInt argOop) {
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (successFlag) {
		return rcvr > arg;
	}
}

sqInt primitiveFloatGreaterOrEqual(void) {
    sqInt aBool;
    sqInt sp;
    sqInt sp1;

	aBool = primitiveFloatGreaterOrEqualtoArg(longAt(stackPointer - (1 * BytesPerWord)), longAt(stackPointer));
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * BytesPerWord;
		/* begin pushBool: */
		if (aBool) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
	}
}

sqInt primitiveFloatGreaterOrEqualtoArg(sqInt rcvrOop, sqInt argOop) {
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (successFlag) {
		return rcvr >= arg;
	}
}

sqInt primitiveFloatGreaterThan(void) {
    sqInt aBool;
    sqInt sp;
    sqInt sp1;

	aBool = primitiveFloatGreaterthanArg(longAt(stackPointer - (1 * BytesPerWord)), longAt(stackPointer));
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * BytesPerWord;
		/* begin pushBool: */
		if (aBool) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
	}
}

sqInt primitiveFloatLessthanArg(sqInt rcvrOop, sqInt argOop) {
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (successFlag) {
		return rcvr < arg;
	}
}

sqInt primitiveFloatLessOrEqual(void) {
    sqInt aBool;
    sqInt sp;
    sqInt sp1;

	aBool = primitiveFloatLessOrEqualtoArg(longAt(stackPointer - (1 * BytesPerWord)), longAt(stackPointer));
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * BytesPerWord;
		/* begin pushBool: */
		if (aBool) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
	}
}

sqInt primitiveFloatLessOrEqualtoArg(sqInt rcvrOop, sqInt argOop) {
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (successFlag) {
		return rcvr <= arg;
	}
}

sqInt primitiveFloatLessThan(void) {
    sqInt aBool;
    sqInt sp;
    sqInt sp1;

	aBool = primitiveFloatLessthanArg(longAt(stackPointer - (1 * BytesPerWord)), longAt(stackPointer));
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * BytesPerWord;
		/* begin pushBool: */
		if (aBool) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
	}
}

sqInt primitiveFloatMultiply(void) {
	return primitiveFloatMultiplybyArg(longAt(stackPointer - (1 * BytesPerWord)), longAt(stackPointer));
}

sqInt primitiveFloatMultiplybyArg(sqInt rcvrOop, sqInt argOop) {
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * BytesPerWord;
		pushFloat(rcvr * arg);
	}
}

sqInt primitiveFloatNotEqual(void) {
    sqInt aBool;
    sqInt sp;
    sqInt sp1;

	aBool = primitiveFloatEqualtoArg(longAt(stackPointer - (1 * BytesPerWord)), longAt(stackPointer));
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * BytesPerWord;
		/* begin pushBool: */
		if (!aBool) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
	}
}

sqInt primitiveFloatSubtract(void) {
	return primitiveFloatSubtractfromArg(longAt(stackPointer - (1 * BytesPerWord)), longAt(stackPointer));
}

sqInt primitiveFloatSubtractfromArg(sqInt rcvrOop, sqInt argOop) {
    double arg;
    double rcvr;

	/* begin loadFloatOrIntFrom: */
	if ((rcvrOop & 1)) {
		rcvr = ((double) ((rcvrOop >> 1)) );
		goto l1;
	}
	if ((fetchClassOfNonInt(rcvrOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		rcvr = floatValueOf(rcvrOop);
		goto l1;
	}
	successFlag = 0;
l1:	/* end loadFloatOrIntFrom: */;
	/* begin loadFloatOrIntFrom: */
	if ((argOop & 1)) {
		arg = ((double) ((argOop >> 1)) );
		goto l2;
	}
	if ((fetchClassOfNonInt(argOop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord)))) {
		arg = floatValueOf(argOop);
		goto l2;
	}
	successFlag = 0;
l2:	/* end loadFloatOrIntFrom: */;
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * BytesPerWord;
		pushFloat(rcvr - arg);
	}
}


/*	Clear the method lookup cache. This must be done after every programming change. */

sqInt primitiveFlushCache(void) {
    sqInt i;
    sqInt aCompiledMethod;

	/* begin flushMethodCache */
	for (i = 1; i <= MethodCacheSize; i += 1) {
		methodCache[i] = 0;
	}
	for (i = 1; i <= AtCacheTotalSize; i += 1) {
		atCache[i] = 0;
	}
	/* begin compilerFlushCacheHook: */
	aCompiledMethod = null;
	if (compilerInitialized) {
		compilerFlushCache(aCompiledMethod);
	}
}


/*	The receiver is a compiledMethod.  Clear all entries in the method lookup cache that refer to this method, presumably because it has been redefined, overridden or removed. */

sqInt primitiveFlushCacheByMethod(void) {
    sqInt oldMethod;
    sqInt i;
    sqInt probe;

	oldMethod = longAt(stackPointer);
	probe = 0;
	for (i = 1; i <= MethodCacheEntries; i += 1) {
		if ((methodCache[probe + MethodCacheMethod]) == oldMethod) {
			methodCache[probe + MethodCacheSelector] = 0;
		}
		probe += MethodCacheEntrySize;
	}
	/* begin compilerFlushCacheHook: */
	if (compilerInitialized) {
		compilerFlushCache(oldMethod);
	}
}


/*	The receiver is a message selector.  Clear all entries in the method lookup cache with this selector, presumably because an associated method has been redefined. */

sqInt primitiveFlushCacheSelective(void) {
    sqInt selector;
    sqInt i;
    sqInt probe;

	selector = longAt(stackPointer);
	probe = 0;
	for (i = 1; i <= MethodCacheEntries; i += 1) {
		if ((methodCache[probe + MethodCacheSelector]) == selector) {
			methodCache[probe + MethodCacheSelector] = 0;
		}
		probe += MethodCacheEntrySize;
	}
}


/*	Primitive. Flush all the existing external primitives in the image thus forcing a reload on next invokation. */

sqInt primitiveFlushExternalPrimitives(void) {
	return flushExternalPrimitives();
}


/*	On some platforms, this primitive forces enqueued display updates to be processed immediately. On others, it does nothing. */

sqInt primitiveForceDisplayUpdate(void) {
	ioForceDisplayUpdate();
}


/*	Set force tenure flag to true, this forces a tenure operation on the next incremental GC */

EXPORT(sqInt) primitiveForceTenure(void) {
	forceTenureFlag = 1;
}


/*	On platforms that support it, this primitive prints the receiver, assumed to be a Form, to the default printer. */

sqInt primitiveFormPrint(void) {
    sqInt landscapeFlag;
    double  vScale;
    sqInt bitsArraySize;
    sqInt wordsPerLine;
    sqInt h;
    sqInt pixelsPerWord;
    sqInt rcvr;
    sqInt depth;
    sqInt ok;
    sqInt bitsArray;
    double  hScale;
    sqInt w;
    sqInt sz;
    sqInt header;
    sqInt fmt;

	/* begin booleanValueOf: */
	if ((longAt(stackPointer)) == trueObj) {
		landscapeFlag = 1;
		goto l2;
	}
	if ((longAt(stackPointer)) == falseObj) {
		landscapeFlag = 0;
		goto l2;
	}
	successFlag = 0;
	landscapeFlag = null;
l2:	/* end booleanValueOf: */;
	vScale = floatValueOf(longAt(stackPointer - (1 * BytesPerWord)));
	hScale = floatValueOf(longAt(stackPointer - (2 * BytesPerWord)));
	rcvr = longAt(stackPointer - (3 * BytesPerWord));
	if ((rcvr & 1)) {
		/* begin success: */
		successFlag = 0 && successFlag;
	}
	if (successFlag) {
		if (!((((rcvr & 1) == 0) && (((((usqInt) (longAt(rcvr))) >> 8) & 15) <= 4)) && ((lengthOf(rcvr)) >= 4))) {
			/* begin success: */
			successFlag = 0 && successFlag;
		}
	}
	if (successFlag) {
		bitsArray = longAt((rcvr + BaseHeaderSize) + (0 << ShiftForWord));
		w = fetchIntegerofObject(1, rcvr);
		h = fetchIntegerofObject(2, rcvr);
		depth = fetchIntegerofObject(3, rcvr);
		if (!((w > 0) && (h > 0))) {
			/* begin success: */
			successFlag = 0 && successFlag;
		}
		pixelsPerWord = 32 / depth;
		wordsPerLine = (w + (pixelsPerWord - 1)) / pixelsPerWord;
		if ((!((rcvr & 1))) && (((bitsArray & 1) == 0) && (isWordsOrBytesNonInt(bitsArray)))) {
			/* begin byteLengthOf: */
			header = longAt(bitsArray);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(bitsArray - (BytesPerWord * 2))) & AllButTypeMask;
			} else {
				sz = header & SizeMask;
			}
			fmt = (((usqInt) header) >> 8) & 15;
			if (fmt < 8) {
				bitsArraySize = sz - BaseHeaderSize;
				goto l1;
			} else {
				bitsArraySize = (sz - BaseHeaderSize) - (fmt & 3);
				goto l1;
			}
		l1:	/* end byteLengthOf: */;
			/* begin success: */
			successFlag = (bitsArraySize == ((wordsPerLine * h) * 4)) && successFlag;
		} else {
			/* begin success: */
			successFlag = 0 && successFlag;
		}
	}
	if (successFlag) {
		if (BytesPerWord == 8) {
			ok = ioFormPrint(bitsArray + 8, w, h, depth, hScale, vScale, landscapeFlag);
		} else {
			ok = ioFormPrint(bitsArray + 4, w, h, depth, hScale, vScale, landscapeFlag);
		}
		/* begin success: */
		successFlag = ok && successFlag;
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 3 * BytesPerWord;
	}
}

sqInt primitiveFractionalPart(void) {
    double  trunc;
    double  frac;
    double  rcvr;

	rcvr = popFloat();
	if (successFlag) {
		frac = modf(rcvr, &trunc);
		pushFloat(frac);
	} else {
		/* begin unPop: */
		stackPointer += 1 * BytesPerWord;
	}
}


/*	Do a full garbage collection and return the number of bytes available (including swap space if dynamic memory management is supported). */

sqInt primitiveFullGC(void) {
    sqInt integerValue;
    sqInt sp;

	/* begin pop: */
	stackPointer -= 1 * BytesPerWord;
	incrementalGC();
	fullGC();
	/* begin pushInteger: */
	integerValue = ((longAt(freeBlock)) & AllButTypeMask) + (sqMemoryExtraBytesLeft(1));
	/* begin push: */
	longAtput(sp = stackPointer + BytesPerWord, ((integerValue << 1) | 1));
	stackPointer = sp;
}


/*	Fetch the system attribute with the given integer ID. The 
	result is a string, which will be empty if the attribute is not 
	defined. */

sqInt primitiveGetAttribute(void) {
    sqInt sz;
    sqInt s;
    sqInt attr;
    sqInt sp;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		attr = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		attr = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	if (successFlag) {
		sz = attributeSize(attr);
	}
	if (successFlag) {
		s = instantiateClassindexableSize(longAt((specialObjectsOop + BaseHeaderSize) + (ClassString << ShiftForWord)), sz);
		getAttributeIntoLength(attr, s + BaseHeaderSize, sz);
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((2 - 1) * BytesPerWord), s);
		stackPointer = sp;
	}
}


/*	Primitive. Return the next input event from the VM event queue. */

sqInt primitiveGetNextEvent(void) {
    sqInt arg;
    int evtBuf[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    sqInt i;
    sqInt value;
    sqInt oop;

	;
	arg = longAt(stackPointer);
	if (!((((arg & 1) == 0) && (((((usqInt) (longAt(arg))) >> 8) & 15) == 2)) && ((slotSizeOf(arg)) == 8))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	ioGetNextEvent(((sqInputEvent*) evtBuf));
	if (!(successFlag)) {
		return null;
	}
	/* begin storeInteger:ofObject:withValue: */
	if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) (evtBuf[0]))) ^ ((((int) (evtBuf[0]))) << 1)) >= 0)
# else
		(((evtBuf[0]) >= -1073741824) && ((evtBuf[0]) <= 1073741823))
# endif  // SQ_HOST32
	) {
		longAtput((arg + BaseHeaderSize) + (0 << ShiftForWord), (((evtBuf[0]) << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	if (!(successFlag)) {
		return null;
	}
	/* begin storeInteger:ofObject:withValue: */
	if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) ((evtBuf[1]) & MillisecondClockMask))) ^ ((((int) ((evtBuf[1]) & MillisecondClockMask))) << 1)) >= 0)
# else
		((((evtBuf[1]) & MillisecondClockMask) >= -1073741824) && (((evtBuf[1]) & MillisecondClockMask) <= 1073741823))
# endif  // SQ_HOST32
	) {
		longAtput((arg + BaseHeaderSize) + (1 << ShiftForWord), ((((evtBuf[1]) & MillisecondClockMask) << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	if (!(successFlag)) {
		return null;
	}
	for (i = 2; i <= 7; i += 1) {
		value = evtBuf[i];
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) value)) ^ ((((int) value)) << 1)) >= 0)
# else
			((value >= -1073741824) && (value <= 1073741823))
# endif  // SQ_HOST32
		) {
			/* begin storeInteger:ofObject:withValue: */
			if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
				(((((int) value)) ^ ((((int) value)) << 1)) >= 0)
# else
				((value >= -1073741824) && (value <= 1073741823))
# endif  // SQ_HOST32
			) {
				longAtput((arg + BaseHeaderSize) + (i << ShiftForWord), ((value << 1) | 1));
			} else {
				/* begin primitiveFail */
				successFlag = 0;
			}
		} else {
			/* begin pushRemappableOop: */
			remapBuffer[remapBufferCount += 1] = arg;
			value = positive32BitIntegerFor(value);
			/* begin popRemappableOop */
			oop = remapBuffer[remapBufferCount];
			remapBufferCount -= 1;
			arg = oop;
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) arg)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(arg, value);
			}
			longAtput((arg + BaseHeaderSize) + (i << ShiftForWord), value);
		}
	}
	if (!(successFlag)) {
		return null;
	}
	/* begin pop: */
	stackPointer -= 1 * BytesPerWord;
}

sqInt primitiveGreaterOrEqual(void) {
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt integerPointer;
    sqInt integerPointer1;
    sqInt sp;
    sqInt sp1;
    sqInt top;
    sqInt top1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integerArgument = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerArgument = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerPointer1 = top1;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		integerReceiver = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerReceiver = 0;
		goto l2;
	}
l2:	/* end checkedIntegerValueOf: */;
	/* begin checkBooleanResult: */
	if (successFlag) {
		/* begin pushBool: */
		if (integerReceiver >= integerArgument) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
	}
}

sqInt primitiveGreaterThan(void) {
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt integerPointer;
    sqInt integerPointer1;
    sqInt top;
    sqInt top1;
    sqInt sp;
    sqInt sp1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integerArgument = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerArgument = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerPointer1 = top1;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		integerReceiver = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerReceiver = 0;
		goto l2;
	}
l2:	/* end checkedIntegerValueOf: */;
	/* begin checkBooleanResult: */
	if (successFlag) {
		/* begin pushBool: */
		if (integerReceiver > integerArgument) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
	}
}


/*	When called with a single string argument, record the string as the current image file name. When called with zero arguments, return a string containing the current image file name. */

sqInt primitiveImageName(void) {
    void * sCRIfn;
    sqInt sz;
    sqInt okToRename;
    sqInt s;
    sqInt sp;
    sqInt cl;
    sqInt ccIndex;

	if (argumentCount == 1) {

		/* If the security plugin can be loaded, use it to check for rename permission.
		If not, assume it's ok */

		sCRIfn = ioLoadFunctionFrom("secCanRenameImage", "SecurityPlugin");
		if (sCRIfn != 0) {
			okToRename =  ((sqInt (*)(void))sCRIfn)();
			if (!(okToRename)) {
				/* begin primitiveFail */
				successFlag = 0;
				return null;
			}
		}
		s = longAt(stackPointer);
		/* begin assertClassOf:is: */
		if ((s & 1)) {
			successFlag = 0;
			goto l1;
		}
		ccIndex = (((usqInt) (longAt(s))) >> 12) & 31;
		if (ccIndex == 0) {
			cl = (longAt(s - BaseHeaderSize)) & AllButTypeMask;
		} else {
			cl = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		}
		/* begin success: */
		successFlag = (cl == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassString << ShiftForWord)))) && successFlag;
	l1:	/* end assertClassOf:is: */;
		if (successFlag) {
			sz = stSizeOf(s);
			imageNamePutLength(s + BaseHeaderSize, sz);
			/* begin pop: */
			stackPointer -= 1 * BytesPerWord;
		}
	} else {
		sz = imageNameSize();
		s = instantiateClassindexableSize(longAt((specialObjectsOop + BaseHeaderSize) + (ClassString << ShiftForWord)), sz);
		imageNameGetLength(s + BaseHeaderSize, sz);
		/* begin pop: */
		stackPointer -= 1 * BytesPerWord;
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, s);
		stackPointer = sp;
	}
}


/*	Do a quick, incremental garbage collection and return the number of bytes immediately available. (Note: more space may be made available by doing a full garbage collection. */

sqInt primitiveIncrementalGC(void) {
    sqInt integerValue;
    sqInt sp;

	/* begin pop: */
	stackPointer -= 1 * BytesPerWord;
	incrementalGC();
	/* begin pushInteger: */
	integerValue = ((longAt(freeBlock)) & AllButTypeMask) + (sqMemoryExtraBytesLeft(0));
	/* begin push: */
	longAtput(sp = stackPointer + BytesPerWord, ((integerValue << 1) | 1));
	stackPointer = sp;
}


/*	Note: We now have 10 bits of primitive index, but they are in two places
	for temporary backward compatibility.  The time to unpack is negligible,
	since the reconstituted full index is stored in the method cache. */

sqInt primitiveIndexOf(sqInt methodPointer) {
    sqInt primBits;

	primBits = (((usqInt) (longAt((methodPointer + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 1) & 268435967;
	return (primBits & 511) + (((usqInt) primBits) >> 19);
}


/*	Note: We now have 10 bits of primitive index, but they are in two places
	for temporary backward compatibility.  The time to unpack is negligible,
	 since the derived primitive function pointer is stored in the method cache. */

sqInt primitiveIndexOfMethodHeader(sqInt methodHeader) {
    sqInt primBits;

	primBits = ((usqInt) methodHeader) >> 1;
	return (primBits & 511) + ((((usqInt) primBits) >> 19) & 512);
}


/*	Register the input semaphore. The argument is an index into the ExternalObjectsArray part of the specialObjectsArray and must have been allocated via 'Smalltalk registerExternalObject: the Semaphore'  */

sqInt primitiveInputSemaphore(void) {
    sqInt arg;

	arg = longAt(stackPointer);
	if ((arg & 1)) {
		ioSetInputSemaphore((arg >> 1));
		if (successFlag) {
			/* begin pop: */
			stackPointer -= 1 * BytesPerWord;
		}
		return null;
	}
}


/*	Return an integer indicating the reason for the most recent input interrupt. */

sqInt primitiveInputWord(void) {
    sqInt sp;

	/* begin pop:thenPushInteger: */
	longAtput(sp = stackPointer - ((1 - 1) * BytesPerWord), ((0 << 1) | 1));
	stackPointer = sp;
}

sqInt primitiveInstVarAt(void) {
    sqInt totalLength;
    sqInt fmt;
    sqInt fixedFields;
    sqInt value;
    sqInt hdr;
    sqInt rcvr;
    sqInt index;
    sqInt sz;
    sqInt sp;
    sqInt integerPointer;
    sqInt classFormat;
    sqInt class;
    sqInt ccIndex;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l4;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l4;
	}
l4:	/* end checkedIntegerValueOf: */;
	rcvr = longAt(stackPointer - (1 * BytesPerWord));
	if (successFlag) {
		hdr = longAt(rcvr);
		fmt = (((usqInt) hdr) >> 8) & 15;
		/* begin lengthOf:baseHeader:format: */
		if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(rcvr - (BytesPerWord * 2))) & LongSizeMask;
		} else {
			sz = hdr & SizeMask;
		}
		sz -= hdr & Size4Bit;
		if (fmt <= 4) {
			totalLength = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
			goto l1;
		}
		if (fmt < 8) {
			totalLength = ((usqInt) (sz - BaseHeaderSize)) >> 2;
			goto l1;
		} else {
			totalLength = (sz - BaseHeaderSize) - (fmt & 3);
			goto l1;
		}
	l1:	/* end lengthOf:baseHeader:format: */;
		/* begin fixedFieldsOf:format:length: */
		if ((fmt > 4) || (fmt == 2)) {
			fixedFields = 0;
			goto l3;
		}
		if (fmt < 2) {
			fixedFields = totalLength;
			goto l3;
		}
		/* begin fetchClassOf: */
		if ((rcvr & 1)) {
			class = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
			goto l5;
		}
		ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
		if (ccIndex == 0) {
			class = (longAt(rcvr - BaseHeaderSize)) & AllButTypeMask;
			goto l5;
		} else {
			class = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
			goto l5;
		}
	l5:	/* end fetchClassOf: */;
		classFormat = (longAt((class + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1;
		fixedFields = (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
	l3:	/* end fixedFieldsOf:format:length: */;
		if (!((index >= 1) && (index <= fixedFields))) {
			successFlag = 0;
		}
	}
	if (successFlag) {
		/* begin subscript:with:format: */
		if (fmt <= 4) {
			value = longAt((rcvr + BaseHeaderSize) + ((index - 1) << ShiftForWord));
			goto l2;
		}
		if (fmt < 8) {
			value = positive32BitIntegerFor(long32At((rcvr + BaseHeaderSize) + ((index - 1) << 2)));
			goto l2;
		} else {
			value = (((byteAt((rcvr + BaseHeaderSize) + (index - 1))) << 1) | 1);
			goto l2;
		}
	l2:	/* end subscript:with:format: */;
	}
	if (successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - (((argumentCount + 1) - 1) * BytesPerWord), value);
		stackPointer = sp;
	}
}

sqInt primitiveInstVarAtPut(void) {
    sqInt newValue;
    sqInt totalLength;
    sqInt fmt;
    sqInt fixedFields;
    sqInt hdr;
    sqInt rcvr;
    sqInt index;
    sqInt sz;
    sqInt valueToStore;
    sqInt sp;
    sqInt integerPointer;
    sqInt classFormat;
    sqInt class;
    sqInt ccIndex;

	newValue = longAt(stackPointer);
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l3;
	}
l3:	/* end checkedIntegerValueOf: */;
	rcvr = longAt(stackPointer - (2 * BytesPerWord));
	if (successFlag) {
		hdr = longAt(rcvr);
		fmt = (((usqInt) hdr) >> 8) & 15;
		/* begin lengthOf:baseHeader:format: */
		if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(rcvr - (BytesPerWord * 2))) & LongSizeMask;
		} else {
			sz = hdr & SizeMask;
		}
		sz -= hdr & Size4Bit;
		if (fmt <= 4) {
			totalLength = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
			goto l1;
		}
		if (fmt < 8) {
			totalLength = ((usqInt) (sz - BaseHeaderSize)) >> 2;
			goto l1;
		} else {
			totalLength = (sz - BaseHeaderSize) - (fmt & 3);
			goto l1;
		}
	l1:	/* end lengthOf:baseHeader:format: */;
		/* begin fixedFieldsOf:format:length: */
		if ((fmt > 4) || (fmt == 2)) {
			fixedFields = 0;
			goto l2;
		}
		if (fmt < 2) {
			fixedFields = totalLength;
			goto l2;
		}
		/* begin fetchClassOf: */
		if ((rcvr & 1)) {
			class = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
			goto l4;
		}
		ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
		if (ccIndex == 0) {
			class = (longAt(rcvr - BaseHeaderSize)) & AllButTypeMask;
			goto l4;
		} else {
			class = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
			goto l4;
		}
	l4:	/* end fetchClassOf: */;
		classFormat = (longAt((class + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1;
		fixedFields = (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
	l2:	/* end fixedFieldsOf:format:length: */;
		if (!((index >= 1) && (index <= fixedFields))) {
			successFlag = 0;
		}
	}
	if (successFlag) {
		/* begin subscript:with:storing:format: */
		if (fmt <= 4) {
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) rcvr)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(rcvr, newValue);
			}
			longAtput((rcvr + BaseHeaderSize) + ((index - 1) << ShiftForWord), newValue);
		} else {
			if (fmt < 8) {
				valueToStore = positive32BitValueOf(newValue);
				if (successFlag) {
					long32Atput((rcvr + BaseHeaderSize) + ((index - 1) << 2), valueToStore);
				}
			} else {
				if (!((newValue & 1))) {
					successFlag = 0;
				}
				valueToStore = (newValue >> 1);
				if (!((valueToStore >= 0) && (valueToStore <= 255))) {
					successFlag = 0;
				}
				if (successFlag) {
					byteAtput((rcvr + BaseHeaderSize) + (index - 1), valueToStore);
				}
			}
		}
	}
	if (successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - (((argumentCount + 1) - 1) * BytesPerWord), newValue);
		stackPointer = sp;
	}
}


/*	Note:  this primitive has been decommissioned.  It is only here for short-term compatibility with an internal 2.3beta-d image that used this.  It did not save much time and it complicated several things.  Plus Jitter will do it right anyway. */

sqInt primitiveInstVarsPutFromStack(void) {
    sqInt offsetBits;
    sqInt i;
    sqInt rcvr;


	/* Mark dirty so stores below can be unchecked */

	rcvr = longAt(stackPointer - (argumentCount * BytesPerWord));
	if ((((usqInt) rcvr)) < (((usqInt) youngStart))) {
		beRootIfOld(rcvr);
	}
	for (i = 0; i <= (argumentCount - 1); i += 1) {
		if ((i & 3) == 0) {
			offsetBits = positive32BitValueOf(longAt((newMethod + BaseHeaderSize) + (((((sqInt) i >> 2)) + LiteralStart) << ShiftForWord)));
		}
		longAtput((rcvr + BaseHeaderSize) + ((offsetBits & 255) << ShiftForWord), longAt(stackPointer - (i * BytesPerWord)));
		offsetBits = ((usqInt) offsetBits) >> 8;
	}
	/* begin pop: */
	stackPointer -= argumentCount * BytesPerWord;
}


/*	Return the 32bit signed integer contents of a words receiver */

sqInt primitiveIntegerAt(void) {
    sqInt sz;
    sqInt value;
    int intValue;
    sqInt rcvr;
    sqInt index;
    sqInt addr;
    sqInt sp;
    sqInt object;
    sqInt sp1;
    sqInt integerPointer;
    sqInt successValue;
    sqInt header;
    sqInt sz1;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l1;
	}
	index = null;
l1:	/* end stackIntegerValue: */;
	rcvr = longAt(stackPointer - (1 * BytesPerWord));
	if ((rcvr & 1)) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	if (!(((rcvr & 1) == 0) && (((((usqInt) (longAt(rcvr))) >> 8) & 15) == 6))) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	/* begin lengthOf: */
	header = longAt(rcvr);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(rcvr - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz1 = header & SizeMask;
	}
	sz1 -= header & Size4Bit;
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		sz = ((usqInt) (sz1 - BaseHeaderSize)) >> ShiftForWord;
		goto l2;
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		sz = ((usqInt) (sz1 - BaseHeaderSize)) >> 2;
		goto l2;
	} else {
		sz = (sz1 - BaseHeaderSize) - (((((usqInt) header) >> 8) & 15) & 3);
		goto l2;
	}
	sz = null;
l2:	/* end lengthOf: */;
	/* begin success: */
	successValue = (index >= 1) && (index <= sz);
	successFlag = successValue && successFlag;
	if (successFlag) {

		/* for zero indexing */

		addr = ((rcvr + BaseHeaderSize) - 4) + (index * 4);
		value = intAt(addr);
		/* begin pop: */
		stackPointer -= 2 * BytesPerWord;
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) value)) ^ ((((int) value)) << 1)) >= 0)
# else
			((value >= -1073741824) && (value <= 1073741823))
# endif  // SQ_HOST32
		) {
			/* begin pushInteger: */
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, ((value << 1) | 1));
			stackPointer = sp;
		} else {

			/* 32 bit int may have been stored in 32 or 64 bit sqInt */

			intValue = value;
			/* begin push: */
			object = signed32BitIntegerFor(intValue);
			longAtput(sp1 = stackPointer + BytesPerWord, object);
			stackPointer = sp1;
		}
	}
}


/*	Return the 32bit signed integer contents of a words receiver */

sqInt primitiveIntegerAtPut(void) {
    sqInt sz;
    sqInt valueOop;
    sqInt value;
    sqInt rcvr;
    sqInt index;
    sqInt addr;
    sqInt sp;
    sqInt integerPointer;
    sqInt header;
    sqInt sz1;

	valueOop = longAt(stackPointer - (0 * BytesPerWord));
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l1;
	}
	index = null;
l1:	/* end stackIntegerValue: */;
	rcvr = longAt(stackPointer - (2 * BytesPerWord));
	if ((rcvr & 1)) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	if (!(((rcvr & 1) == 0) && (((((usqInt) (longAt(rcvr))) >> 8) & 15) == 6))) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	/* begin lengthOf: */
	header = longAt(rcvr);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(rcvr - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz1 = header & SizeMask;
	}
	sz1 -= header & Size4Bit;
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		sz = ((usqInt) (sz1 - BaseHeaderSize)) >> ShiftForWord;
		goto l2;
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		sz = ((usqInt) (sz1 - BaseHeaderSize)) >> 2;
		goto l2;
	} else {
		sz = (sz1 - BaseHeaderSize) - (((((usqInt) header) >> 8) & 15) & 3);
		goto l2;
	}
	sz = null;
l2:	/* end lengthOf: */;
	if (!((index >= 1) && (index <= sz))) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	if ((valueOop & 1)) {
		value = (valueOop >> 1);
	} else {
		value = signed32BitValueOf(valueOop);
	}
	if (successFlag) {

		/* for zero indexing */

		addr = ((rcvr + BaseHeaderSize) - 4) + (index * 4);
		value = intAtput(addr, value);
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((3 - 1) * BytesPerWord), valueOop);
		stackPointer = sp;
	}
}


/*	Register the user interrupt semaphore. If the argument is 
	not a Semaphore, unregister the current interrupt 
	semaphore.  */

sqInt primitiveInterruptSemaphore(void) {
    sqInt arg;
    sqInt oop;
    sqInt oop1;
    sqInt valuePointer;
    sqInt top;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	arg = top;
	if ((fetchClassOf(arg)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassSemaphore << ShiftForWord)))) {
		/* begin storePointer:ofObject:withValue: */
		oop = specialObjectsOop;
		if ((((usqInt) oop)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(oop, arg);
		}
		longAtput((oop + BaseHeaderSize) + (TheInterruptSemaphore << ShiftForWord), arg);
	} else {
		/* begin storePointer:ofObject:withValue: */
		oop1 = specialObjectsOop;
		valuePointer = nilObj;
		if ((((usqInt) oop1)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(oop1, valuePointer);
		}
		longAtput((oop1 + BaseHeaderSize) + (TheInterruptSemaphore << ShiftForWord), valuePointer);
	}
}


/*	Primitive. 'Invoke' an object like a function, sending the special message 
		run: originalSelector with: arguments in: aReceiver.
	 */

sqInt primitiveInvokeObjectAsMethod(void) {
    sqInt newReceiver;
    sqInt runReceiver;
    sqInt runArgs;
    sqInt runSelector;
    sqInt lookupClass;
    sqInt count;
    sqInt src;
    sqInt in;
    sqInt lastIn;
    sqInt out;
    sqInt sp;
    sqInt sp1;
    sqInt sp2;
    sqInt sp3;
    sqInt ccIndex;

	runArgs = instantiateClassindexableSize(longAt((specialObjectsOop + BaseHeaderSize) + (ClassArray << ShiftForWord)), argumentCount);
	beRootIfOld(runArgs);
	/* begin transfer:from:to: */
	count = argumentCount;
	src = stackPointer - ((argumentCount - 1) * BytesPerWord);
	flag("Dan");
	in = src - BytesPerWord;
	lastIn = in + (count * BytesPerWord);
	out = (runArgs + BaseHeaderSize) - BytesPerWord;
	while ((((usqInt) in)) < (((usqInt) lastIn))) {
		longAtput(out += BytesPerWord, longAt(in += BytesPerWord));
	}
	runSelector = messageSelector;
	runReceiver = longAt(stackPointer - (argumentCount * BytesPerWord));
	/* begin pop: */
	stackPointer -= (argumentCount + 1) * BytesPerWord;
	newReceiver = newMethod;
	messageSelector = longAt((specialObjectsOop + BaseHeaderSize) + (SelectorRunWithIn << ShiftForWord));
	argumentCount = 3;
	/* begin push: */
	longAtput(sp = stackPointer + BytesPerWord, newReceiver);
	stackPointer = sp;
	/* begin push: */
	longAtput(sp1 = stackPointer + BytesPerWord, runSelector);
	stackPointer = sp1;
	/* begin push: */
	longAtput(sp2 = stackPointer + BytesPerWord, runArgs);
	stackPointer = sp2;
	/* begin push: */
	longAtput(sp3 = stackPointer + BytesPerWord, runReceiver);
	stackPointer = sp3;
	/* begin fetchClassOf: */
	if ((newReceiver & 1)) {
		lookupClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(newReceiver))) >> 12) & 31;
	if (ccIndex == 0) {
		lookupClass = (longAt(newReceiver - BaseHeaderSize)) & AllButTypeMask;
		goto l1;
	} else {
		lookupClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	findNewMethodInClass(lookupClass);
	executeNewMethodFromCache();
	successFlag = 1;
}


/*	Primitive. Return true if the receiver is an Event VM. 
	Also verify the pending callback sema. */

EXPORT(sqInt) primitiveIsEventVM(void) {
    sqInt trueOrFalse;
    sqInt sp;
    sqInt sp1;

	/* begin pop: */
	stackPointer -= (argumentCount + 1) * BytesPerWord;
	/* begin pushBool: */
	trueOrFalse = (callbackSemaphore()) != null;
	if (trueOrFalse) {
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, trueObj);
		stackPointer = sp;
	} else {
		/* begin push: */
		longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
		stackPointer = sp1;
	}
}


/*	Primitive. Answer whether the argument to the primitive is a root for young space */

EXPORT(sqInt) primitiveIsRoot(void) {
    sqInt oop;
    sqInt sp;
    sqInt sp1;
    sqInt oop1;

	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (0 * BytesPerWord));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		oop = null;
		goto l1;
	}
	oop = oop1;
l1:	/* end stackObjectValue: */;
	if (successFlag) {
		/* begin pop: */
		stackPointer -= (argumentCount + 1) * BytesPerWord;
		/* begin pushBool: */
		if ((longAt(oop)) & RootBit) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
	}
}


/*	Primitive. Answer whether the argument to the primitive resides in young space. */

EXPORT(sqInt) primitiveIsYoung(void) {
    sqInt oop;
    sqInt oop1;
    sqInt sp;
    sqInt sp1;

	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (0 * BytesPerWord));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		oop = null;
		goto l1;
	}
	oop = oop1;
l1:	/* end stackObjectValue: */;
	if (successFlag) {
		/* begin pop: */
		stackPointer -= (argumentCount + 1) * BytesPerWord;
		/* begin pushBool: */
		if ((((usqInt) oop)) >= (((usqInt) youngStart))) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
	}
}


/*	Obsolete on virtually all platforms; old style input polling code.
	Return the next keycode and remove it from the input buffer. The low byte is the 8-bit ISO character. The next four bits are the Smalltalk modifier bits <cmd><option><ctrl><shift>. */

sqInt primitiveKbdNext(void) {
    sqInt keystrokeWord;
    sqInt sp;
    sqInt sp1;

	/* begin pop: */
	stackPointer -= 1 * BytesPerWord;
	keystrokeWord = ioGetKeystroke();
	if (keystrokeWord >= 0) {
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp1 = stackPointer + BytesPerWord, ((keystrokeWord << 1) | 1));
		stackPointer = sp1;
	} else {
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, nilObj);
		stackPointer = sp;
	}
}


/*	Obsolete on virtually all platforms; old style input polling code.
	Return the next keycode and without removing it from the input buffer. The low byte is the 8-bit ISO character. The next four bits are the Smalltalk modifier bits <cmd><option><ctrl><shift>. */

sqInt primitiveKbdPeek(void) {
    sqInt keystrokeWord;
    sqInt sp;
    sqInt sp1;

	/* begin pop: */
	stackPointer -= 1 * BytesPerWord;
	keystrokeWord = ioPeekKeystroke();
	if (keystrokeWord >= 0) {
		/* begin pushInteger: */
		/* begin push: */
		longAtput(sp1 = stackPointer + BytesPerWord, ((keystrokeWord << 1) | 1));
		stackPointer = sp1;
	} else {
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, nilObj);
		stackPointer = sp;
	}
}

sqInt primitiveLessOrEqual(void) {
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt integerPointer;
    sqInt integerPointer1;
    sqInt top;
    sqInt top1;
    sqInt sp;
    sqInt sp1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integerArgument = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerArgument = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerPointer1 = top1;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		integerReceiver = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerReceiver = 0;
		goto l2;
	}
l2:	/* end checkedIntegerValueOf: */;
	/* begin checkBooleanResult: */
	if (successFlag) {
		/* begin pushBool: */
		if (integerReceiver <= integerArgument) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
	}
}

sqInt primitiveLessThan(void) {
    sqInt integerArgument;
    sqInt integerReceiver;
    sqInt integerPointer;
    sqInt integerPointer1;
    sqInt top;
    sqInt top1;
    sqInt sp;
    sqInt sp1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integerArgument = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerArgument = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerPointer1 = top1;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		integerReceiver = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerReceiver = 0;
		goto l2;
	}
l2:	/* end checkedIntegerValueOf: */;
	/* begin checkBooleanResult: */
	if (successFlag) {
		/* begin pushBool: */
		if (integerReceiver < integerArgument) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
	}
}


/*	Primitive. Return the n-th builtin module name. */

sqInt primitiveListBuiltinModule(void) {
    sqInt length;
    sqInt i;
    char * moduleName;
    sqInt nameOop;
    sqInt index;
    sqInt sp;
    sqInt integerPointer;
    sqInt sp1;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l1;
	}
	index = null;
l1:	/* end stackIntegerValue: */;
	if (index <= 0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	moduleName = ioListBuiltinModule(index);
	if (moduleName == null) {
		/* begin pop: */
		stackPointer -= 2 * BytesPerWord;
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, nilObj);
		stackPointer = sp;
		return null;
	}
	length = strlen(moduleName);
	nameOop = instantiateClassindexableSize(longAt((specialObjectsOop + BaseHeaderSize) + (ClassString << ShiftForWord)), length);
	for (i = 0; i <= (length - 1); i += 1) {
		byteAtput((nameOop + BaseHeaderSize) + i, moduleName[i]);
	}
	/* begin forceInterruptCheck */
	interruptCheckCounter = -1000;
	nextPollTick = 0;
	/* begin pop:thenPush: */
	longAtput(sp1 = stackPointer - ((2 - 1) * BytesPerWord), nameOop);
	stackPointer = sp1;
}


/*	Primitive. Return the n-th loaded external module name. */

sqInt primitiveListExternalModule(void) {
    sqInt length;
    sqInt i;
    char * moduleName;
    sqInt nameOop;
    sqInt index;
    sqInt sp;
    sqInt integerPointer;
    sqInt sp1;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l1;
	}
	index = null;
l1:	/* end stackIntegerValue: */;
	if (index <= 0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	moduleName = ioListLoadedModule(index);
	if (moduleName == null) {
		/* begin pop: */
		stackPointer -= 2 * BytesPerWord;
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, nilObj);
		stackPointer = sp;
		return null;
	}
	length = strlen(moduleName);
	nameOop = instantiateClassindexableSize(longAt((specialObjectsOop + BaseHeaderSize) + (ClassString << ShiftForWord)), length);
	for (i = 0; i <= (length - 1); i += 1) {
		byteAtput((nameOop + BaseHeaderSize) + i, moduleName[i]);
	}
	/* begin forceInterruptCheck */
	interruptCheckCounter = -1000;
	nextPollTick = 0;
	/* begin pop:thenPush: */
	longAtput(sp1 = stackPointer - ((2 - 1) * BytesPerWord), nameOop);
	stackPointer = sp1;
}


/*	This primitive is called from Squeak as...
		<imageSegment> loadSegmentFrom: aWordArray outPointers: anArray. */
/*	This primitive will load a binary image segment created by primitiveStoreImageSegment.  It expects the outPointer array to be of the proper size, and the wordArray to be well formed.  It will return as its value the original array of roots, and the erstwhile segmentWordArray will have been truncated to a size of zero.  If this primitive should fail, the segmentWordArray will, sadly, have been reduced to an unrecognizable and unusable jumble.  But what more could you have done with it anyway? */

sqInt primitiveLoadImageSegment(void) {
    sqInt mapOop;
    usqInt segOop;
    sqInt hdrTypeBits;
    usqInt lastPtr;
    sqInt segmentWordArray;
    sqInt doingClass;
    sqInt header;
    sqInt data;
    sqInt fieldOop;
    usqInt fieldPtr;
    usqInt lastOut;
    sqInt extraSize;
    usqInt outPtr;
    usqInt endSeg;
    sqInt outPointerArray;
    sqInt addr;
    sqInt addr1;
    sqInt sp;
    sqInt sz;
    sqInt header1;
    sqInt sz1;
    sqInt header2;

	if (DoAssertionChecks) {
		verifyCleanHeaders();
	}
	outPointerArray = longAt(stackPointer);
	lastOut = outPointerArray + (lastPointerOf(outPointerArray));
	segmentWordArray = longAt(stackPointer - (1 * BytesPerWord));

	/* Essential type checks */

	endSeg = (segmentWordArray + (sizeBitsOf(segmentWordArray))) - BaseHeaderSize;
	if (!((((((usqInt) (longAt(outPointerArray))) >> 8) & 15) == 2) && (((((usqInt) (longAt(segmentWordArray))) >> 8) & 15) == 6))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	data = longAt(segmentWordArray + BaseHeaderSize);
	if (!(((data & 65535) == imageFormatVersionNumber) || ((data & 65535) == (imageFormatForwardCompatibilityVersion())))) {
		/* begin reverseBytesFrom:to: */
		flag("Dan");
		addr1 = segmentWordArray + BaseHeaderSize;
		while ((((usqInt) addr1)) < (((usqInt) (endSeg + BytesPerWord)))) {
			longAtput(addr1, byteSwapped(longAt(addr1)));
			addr1 += BytesPerWord;
		}
		data = longAt(segmentWordArray + BaseHeaderSize);
		if (!(((data & 65535) == imageFormatVersionNumber) || ((data & 65535) == (imageFormatForwardCompatibilityVersion())))) {
			/* begin reverseBytesFrom:to: */
			flag("Dan");
			addr = segmentWordArray + BaseHeaderSize;
			while ((((usqInt) addr)) < (((usqInt) (endSeg + BytesPerWord)))) {
				longAtput(addr, byteSwapped(longAt(addr)));
				addr += BytesPerWord;
			}
			if (DoAssertionChecks) {
				verifyCleanHeaders();
			}
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	if (!(data == (imageSegmentVersion()))) {

		/* Reverse the byte-type objects once */
		/* Oop of first embedded object */

		segOop = ((segmentWordArray + BaseHeaderSize) + BytesPerWord) + (headerTypeBytes[(longAt((segmentWordArray + BaseHeaderSize) + BytesPerWord)) & TypeMask]);
		byteSwapByteObjectsFromto(segOop, endSeg + BytesPerWord);
	}
	segOop = ((segmentWordArray + BaseHeaderSize) + BytesPerWord) + (headerTypeBytes[(longAt((segmentWordArray + BaseHeaderSize) + BytesPerWord)) & TypeMask]);
	while (segOop <= endSeg) {
		if (((longAt(segOop)) & TypeMask) <= 1) {

			/* This object has a class field (type = 0 or 1) -- start with that. */

			fieldPtr = segOop - BytesPerWord;
			doingClass = 1;
		} else {

			/* No class field -- start with first data field */

			fieldPtr = segOop + BaseHeaderSize;
			doingClass = 0;
		}

		/* last field */

		lastPtr = segOop + (lastPointerOf(segOop));
		if (lastPtr > endSeg) {
			if (DoAssertionChecks) {
				verifyCleanHeaders();
			}
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		while (!(fieldPtr > lastPtr)) {

			/* Examine each pointer field */

			fieldOop = longAt(fieldPtr);
			if (doingClass) {
				hdrTypeBits = (longAt(fieldPtr)) & TypeMask;
				fieldOop -= hdrTypeBits;
			}
			if ((fieldOop & 1)) {

				/* Integer -- nothing to do */

				fieldPtr += BytesPerWord;
			} else {
				if (!((fieldOop & 3) == 0)) {
					/* begin primitiveFail */
					successFlag = 0;
					return null;
				}
				if ((fieldOop & 2147483648U) == 0) {

					/* Internal pointer -- add segment offset */

					mapOop = fieldOop + segmentWordArray;
				} else {

					/* External pointer -- look it up in outPointers */

					outPtr = outPointerArray + (fieldOop & 2147483647U);
					if (outPtr > lastOut) {
						/* begin primitiveFail */
						successFlag = 0;
						return null;
					}
					mapOop = longAt(outPtr);
				}
				if (doingClass) {
					longAtput(fieldPtr, mapOop + hdrTypeBits);
					fieldPtr += 8;
					doingClass = 0;
				} else {
					longAtput(fieldPtr, mapOop);
					fieldPtr += BytesPerWord;
				}
				if (segOop < youngStart) {
					possibleRootStoreIntovalue(segOop, mapOop);
				}
			}
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) segOop)) >= (((usqInt) endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(segOop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(segOop)) & AllButTypeMask;
		} else {
			/* begin sizeBitsOf: */
			header1 = longAt(segOop);
			if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(segOop - (BytesPerWord * 2))) & LongSizeMask;
				goto l1;
			} else {
				sz = header1 & SizeMask;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		segOop = (segOop + sz) + (headerTypeBytes[(longAt(segOop + sz)) & TypeMask]);
	}
	segOop = ((segmentWordArray + BaseHeaderSize) + BytesPerWord) + (headerTypeBytes[(longAt((segmentWordArray + BaseHeaderSize) + BytesPerWord)) & TypeMask]);
	while (segOop <= endSeg) {
		if (!(oopHasAcceptableClass(segOop))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}

		/* first field */

		fieldPtr = segOop + BaseHeaderSize;

		/* last field */
		/* Go through all oops, remapping them... */

		lastPtr = segOop + (lastPointerOf(segOop));
		while (!(fieldPtr > lastPtr)) {

			/* Examine each pointer field */

			fieldOop = longAt(fieldPtr);
			if (!(oopHasAcceptableClass(fieldOop))) {
				/* begin primitiveFail */
				successFlag = 0;
				return null;
			}
			fieldPtr += BytesPerWord;
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) segOop)) >= (((usqInt) endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(segOop)) & TypeMask) == HeaderTypeFree) {
			sz1 = (longAt(segOop)) & AllButTypeMask;
		} else {
			/* begin sizeBitsOf: */
			header2 = longAt(segOop);
			if ((header2 & TypeMask) == HeaderTypeSizeAndClass) {
				sz1 = (longAt(segOop - (BytesPerWord * 2))) & LongSizeMask;
				goto l2;
			} else {
				sz1 = header2 & SizeMask;
				goto l2;
			}
		l2:	/* end sizeBitsOf: */;
		}
		segOop = (segOop + sz1) + (headerTypeBytes[(longAt(segOop + sz1)) & TypeMask]);
	}
	extraSize = headerTypeBytes[(longAt(segmentWordArray)) & TypeMask];
	hdrTypeBits = (longAt(segmentWordArray)) & TypeMask;
	if (extraSize == 8) {
		longAtput(segmentWordArray - extraSize, (BaseHeaderSize + BytesPerWord) + hdrTypeBits);
	} else {
		header = longAt(segmentWordArray);
		longAtput(segmentWordArray, ((header - (header & SizeMask)) + BaseHeaderSize) + BytesPerWord);
	}
	if (DoAssertionChecks) {
		verifyCleanHeaders();
	}
	/* begin pop:thenPush: */
	longAtput(sp = stackPointer - ((3 - 1) * BytesPerWord), ((segmentWordArray + BaseHeaderSize) + BytesPerWord) + (headerTypeBytes[(longAt((segmentWordArray + BaseHeaderSize) + BytesPerWord)) & TypeMask]));
	stackPointer = sp;
}

sqInt primitiveLoadInstVar(void) {
    sqInt thisReceiver;
    sqInt top;
    sqInt sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	thisReceiver = top;
	/* begin push: */
	longAtput(sp = stackPointer + BytesPerWord, longAt((thisReceiver + BaseHeaderSize) + ((primitiveIndex - 264) << ShiftForWord)));
	stackPointer = sp;
}


/*	Natural log. */

sqInt primitiveLogN(void) {
    double  rcvr;

	rcvr = popFloat();
	if (successFlag) {
		pushFloat(log(rcvr));
	} else {
		/* begin unPop: */
		stackPointer += 1 * BytesPerWord;
	}
}


/*	Register the low-space semaphore. If the argument is not a 
	Semaphore, unregister the current low-space Semaphore. */

sqInt primitiveLowSpaceSemaphore(void) {
    sqInt arg;
    sqInt top;
    sqInt oop;
    sqInt oop1;
    sqInt valuePointer;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	arg = top;
	if ((fetchClassOf(arg)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassSemaphore << ShiftForWord)))) {
		/* begin storePointer:ofObject:withValue: */
		oop = specialObjectsOop;
		if ((((usqInt) oop)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(oop, arg);
		}
		longAtput((oop + BaseHeaderSize) + (TheLowSpaceSemaphore << ShiftForWord), arg);
	} else {
		/* begin storePointer:ofObject:withValue: */
		oop1 = specialObjectsOop;
		valuePointer = nilObj;
		if ((((usqInt) oop1)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(oop1, valuePointer);
		}
		longAtput((oop1 + BaseHeaderSize) + (TheLowSpaceSemaphore << ShiftForWord), valuePointer);
	}
}

sqInt primitiveMakePoint(void) {
    sqInt argument;
    sqInt pt;
    sqInt rcvr;
    sqInt pointResult;
    sqInt pointResult1;
    sqInt valuePointer;
    sqInt pointResult2;
    sqInt valuePointer1;
    sqInt valuePointer2;
    sqInt sp;

	argument = longAt(stackPointer);
	rcvr = longAt(stackPointer - (1 * BytesPerWord));
	if ((rcvr & 1)) {
		if ((argument & 1)) {
			/* begin makePointwithxValue:yValue: */
			pointResult = instantiateSmallClasssizeInBytes(longAt((specialObjectsOop + BaseHeaderSize) + (ClassPoint << ShiftForWord)), 3 * BytesPerWord);
			longAtput((pointResult + BaseHeaderSize) + (XIndex << ShiftForWord), ((((rcvr >> 1)) << 1) | 1));
			longAtput((pointResult + BaseHeaderSize) + (YIndex << ShiftForWord), ((((argument >> 1)) << 1) | 1));
			pt = pointResult;
		} else {
			/* begin makePointwithxValue:yValue: */
			pointResult1 = instantiateSmallClasssizeInBytes(longAt((specialObjectsOop + BaseHeaderSize) + (ClassPoint << ShiftForWord)), 3 * BytesPerWord);
			longAtput((pointResult1 + BaseHeaderSize) + (XIndex << ShiftForWord), ((((rcvr >> 1)) << 1) | 1));
			longAtput((pointResult1 + BaseHeaderSize) + (YIndex << ShiftForWord), ((0 << 1) | 1));
			pt = pointResult1;
			/* begin storePointer:ofObject:withValue: */
			valuePointer = longAt(stackPointer - (0 * BytesPerWord));
			if ((((usqInt) pt)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(pt, valuePointer);
			}
			longAtput((pt + BaseHeaderSize) + (1 << ShiftForWord), valuePointer);
		}
	} else {
		if (!((fetchClassOf(rcvr)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord))))) {
			/* begin success: */
			successFlag = 0 && successFlag;
			return null;
		}
		/* begin makePointwithxValue:yValue: */
		pointResult2 = instantiateSmallClasssizeInBytes(longAt((specialObjectsOop + BaseHeaderSize) + (ClassPoint << ShiftForWord)), 3 * BytesPerWord);
		longAtput((pointResult2 + BaseHeaderSize) + (XIndex << ShiftForWord), ((0 << 1) | 1));
		longAtput((pointResult2 + BaseHeaderSize) + (YIndex << ShiftForWord), ((0 << 1) | 1));
		pt = pointResult2;
		/* begin storePointer:ofObject:withValue: */
		valuePointer1 = longAt(stackPointer - (1 * BytesPerWord));
		if ((((usqInt) pt)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(pt, valuePointer1);
		}
		longAtput((pt + BaseHeaderSize) + (0 << ShiftForWord), valuePointer1);
		/* begin storePointer:ofObject:withValue: */
		valuePointer2 = longAt(stackPointer - (0 * BytesPerWord));
		if ((((usqInt) pt)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(pt, valuePointer2);
		}
		longAtput((pt + BaseHeaderSize) + (1 << ShiftForWord), valuePointer2);
	}
	/* begin pop:thenPush: */
	longAtput(sp = stackPointer - ((2 - 1) * BytesPerWord), pt);
	stackPointer = sp;
}


/*	Primitive. Mark the method for exception handling. The primitive must fail after marking the context so that the regular code is run. */

sqInt primitiveMarkHandlerMethod(void) {
	/* begin primitiveFail */
	successFlag = 0;
	return null;
}


/*	Primitive. Mark the method for exception unwinding. The primitive must fail after marking the context so that the regular code is run. */

sqInt primitiveMarkUnwindMethod(void) {
	/* begin primitiveFail */
	successFlag = 0;
	return null;
}


/*	Return the method an external primitive was defined in */

sqInt primitiveMethod(void) {
	return newMethod;
}


/*	Return the value of the millisecond clock as an integer. Note that the millisecond clock wraps around periodically. On some platforms it can wrap daily. The range is limited to SmallInteger maxVal / 2 to allow delays of up to that length without overflowing a SmallInteger. */

sqInt primitiveMillisecondClock(void) {
    sqInt oop;
    sqInt sp;

	/* begin pop:thenPush: */
	oop = ((((ioMSecs()) & MillisecondClockMask) << 1) | 1);
	longAtput(sp = stackPointer - ((1 - 1) * BytesPerWord), oop);
	stackPointer = sp;
}

sqInt primitiveMod(void) {
    sqInt mod;
    sqInt sp;

	mod = doPrimitiveModby(longAt(stackPointer - (1 * BytesPerWord)), longAt(stackPointer));
	/* begin pop2AndPushIntegerIfOK: */
	if (successFlag) {
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) mod)) ^ ((((int) mod)) << 1)) >= 0)
# else
			((mod >= -1073741824) && (mod <= 1073741823))
# endif  // SQ_HOST32
		) {
			/* begin pop:thenPush: */
			longAtput(sp = stackPointer - ((2 - 1) * BytesPerWord), ((mod << 1) | 1));
			stackPointer = sp;
		} else {
			successFlag = 0;
		}
	}
}


/*	Obsolete on virtually all platforms; old style input polling code.
	Return the mouse button state. The low three bits encode the state of the <red><yellow><blue> mouse buttons. The next four bits encode the Smalltalk modifier bits <cmd><option><ctrl><shift>. */

sqInt primitiveMouseButtons(void) {
    sqInt buttonWord;
    sqInt sp;

	/* begin pop: */
	stackPointer -= 1 * BytesPerWord;
	buttonWord = ioGetButtonState();
	/* begin pushInteger: */
	/* begin push: */
	longAtput(sp = stackPointer + BytesPerWord, ((buttonWord << 1) | 1));
	stackPointer = sp;
}


/*	Obsolete on virtually all platforms; old style input polling code.
	Return a Point indicating current position of the mouse. Note that mouse coordinates may be negative if the mouse moves above or to the left of the top-left corner of the Smalltalk window. */

sqInt primitiveMousePoint(void) {
    sqInt y;
    sqInt pointWord;
    sqInt x;
    sqInt object;
    sqInt sp;
    sqInt pointResult;

	/* begin pop: */
	stackPointer -= 1 * BytesPerWord;
	pointWord = ioMousePoint();
	/* begin signExtend16: */
	if ((((((usqInt) pointWord) >> 16) & 65535) & 32768) == 0) {
		x = (((usqInt) pointWord) >> 16) & 65535;
		goto l1;
	} else {
		x = ((((usqInt) pointWord) >> 16) & 65535) - 65536;
		goto l1;
	}
l1:	/* end signExtend16: */;
	/* begin signExtend16: */
	if (((pointWord & 65535) & 32768) == 0) {
		y = pointWord & 65535;
		goto l2;
	} else {
		y = (pointWord & 65535) - 65536;
		goto l2;
	}
l2:	/* end signExtend16: */;
	/* begin push: */
	/* begin makePointwithxValue:yValue: */
	pointResult = instantiateSmallClasssizeInBytes(longAt((specialObjectsOop + BaseHeaderSize) + (ClassPoint << ShiftForWord)), 3 * BytesPerWord);
	longAtput((pointResult + BaseHeaderSize) + (XIndex << ShiftForWord), ((x << 1) | 1));
	longAtput((pointResult + BaseHeaderSize) + (YIndex << ShiftForWord), ((y << 1) | 1));
	object = pointResult;
	longAtput(sp = stackPointer + BytesPerWord, object);
	stackPointer = sp;
}

sqInt primitiveMultiply(void) {
    sqInt integerArg;
    sqInt integerResult;
    sqInt integerRcvr;
    sqInt integerPointer;
    sqInt integerPointer1;
    sqInt sp;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integerRcvr = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerRcvr = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		integerArg = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerArg = 0;
		goto l2;
	}
l2:	/* end checkedIntegerValueOf: */;
	if (successFlag) {

		/* check for C overflow by seeing if computation is reversible */

		integerResult = integerRcvr * integerArg;
		if ((integerArg == 0) || ((integerResult / integerArg) == integerRcvr)) {
			/* begin pop2AndPushIntegerIfOK: */
			if (successFlag) {
				if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
					(((((int) integerResult)) ^ ((((int) integerResult)) << 1)) >= 0)
# else
					((integerResult >= -1073741824) && (integerResult <= 1073741823))
# endif  // SQ_HOST32
				) {
					/* begin pop:thenPush: */
					longAtput(sp = stackPointer - ((2 - 1) * BytesPerWord), ((integerResult << 1) | 1));
					stackPointer = sp;
				} else {
					successFlag = 0;
				}
			}
		} else {
			/* begin primitiveFail */
			successFlag = 0;
		}
	}
}


/*	Allocate a new fixed-size instance. Fail if the allocation would leave less than lowSpaceThreshold bytes free. May cause a GC */

sqInt primitiveNew(void) {
    sqInt spaceOkay;
    sqInt class;
    sqInt object;
    sqInt sp;
    sqInt format;
    usqInt minFree;
    usqInt minFree1;


	/* The following may cause GC! */

	class = longAt(stackPointer);
	/* begin sufficientSpaceToInstantiate:indexableSize: */
	format = (((usqInt) ((longAt((class + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1)) >> 8) & 15;
	if ((0 > 0) && (format < 2)) {
		spaceOkay = 0;
		goto l1;
	}
	if (format < 8) {
		if (isExcessiveAllocationRequestshift(0, ShiftForWord)) {
			spaceOkay = 0;
			goto l1;
		}
		/* begin sufficientSpaceToAllocate: */
		minFree = (lowSpaceThreshold + (2500 + (0 * BytesPerWord))) + BaseHeaderSize;
		if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) >= (((usqInt) minFree))) {
			spaceOkay = 1;
			goto l2;
		} else {
			spaceOkay = sufficientSpaceAfterGC(minFree);
			goto l2;
		}
	l2:	/* end sufficientSpaceToAllocate: */;
		goto l1;
	} else {
		if (isExcessiveAllocationRequestshift(0, 0)) {
			spaceOkay = 0;
			goto l1;
		}
		/* begin sufficientSpaceToAllocate: */
		minFree1 = (lowSpaceThreshold + (2500 + 0)) + BaseHeaderSize;
		if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) >= (((usqInt) minFree1))) {
			spaceOkay = 1;
			goto l3;
		} else {
			spaceOkay = sufficientSpaceAfterGC(minFree1);
			goto l3;
		}
	l3:	/* end sufficientSpaceToAllocate: */;
		goto l1;
	}
l1:	/* end sufficientSpaceToInstantiate:indexableSize: */;
	/* begin success: */
	successFlag = spaceOkay && successFlag;
	if (successFlag) {
		/* begin push: */
		object = instantiateClassindexableSize(popStack(), 0);
		longAtput(sp = stackPointer + BytesPerWord, object);
		stackPointer = sp;
	}
}

sqInt primitiveNewMethod(void) {
    sqInt bytecodeCount;
    sqInt header;
    sqInt i;
    sqInt literalCount;
    sqInt size;
    sqInt class;
    sqInt theMethod;
    sqInt top;
    sqInt integerPointer;
    sqInt top1;
    sqInt top2;
    sqInt sp;
    sqInt valuePointer;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	header = top;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerPointer = top1;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		bytecodeCount = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		bytecodeCount = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	/* begin success: */
	successFlag = ((header & 1)) && successFlag;
	if (!(successFlag)) {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
		return null;
	}
	/* begin popStack */
	top2 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	class = top2;
	size = ((((((usqInt) header) >> 10) & 255) + 1) * BytesPerWord) + bytecodeCount;
	theMethod = instantiateClassindexableSize(class, size);
	longAtput((theMethod + BaseHeaderSize) + (HeaderIndex << ShiftForWord), header);
	literalCount = (((usqInt) header) >> 10) & 255;
	for (i = 1; i <= literalCount; i += 1) {
		/* begin storePointer:ofObject:withValue: */
		valuePointer = nilObj;
		if ((((usqInt) theMethod)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(theMethod, valuePointer);
		}
		longAtput((theMethod + BaseHeaderSize) + (i << ShiftForWord), valuePointer);
	}
	/* begin push: */
	longAtput(sp = stackPointer + BytesPerWord, theMethod);
	stackPointer = sp;
}


/*	Allocate a new indexable instance. Fail if the allocation would leave less than lowSpaceThreshold bytes free. */

sqInt primitiveNewWithArg(void) {
    sqInt spaceOkay;
    usqInt size;
    sqInt class;
    sqInt format;
    sqInt oop;
    sqInt sp;
    usqInt minFree;
    usqInt minFree1;

	size = positive32BitValueOf(longAt(stackPointer));
	class = longAt(stackPointer - (1 * BytesPerWord));
	/* begin success: */
	successFlag = (size >= 0) && successFlag;
	if (successFlag) {
		/* begin sufficientSpaceToInstantiate:indexableSize: */
		format = (((usqInt) ((longAt((class + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1)) >> 8) & 15;
		if ((size > 0) && (format < 2)) {
			spaceOkay = 0;
			goto l1;
		}
		if (format < 8) {
			if (isExcessiveAllocationRequestshift(size, ShiftForWord)) {
				spaceOkay = 0;
				goto l1;
			}
			/* begin sufficientSpaceToAllocate: */
			minFree = (lowSpaceThreshold + (2500 + (size * BytesPerWord))) + BaseHeaderSize;
			if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) >= (((usqInt) minFree))) {
				spaceOkay = 1;
				goto l2;
			} else {
				spaceOkay = sufficientSpaceAfterGC(minFree);
				goto l2;
			}
		l2:	/* end sufficientSpaceToAllocate: */;
			goto l1;
		} else {
			if (isExcessiveAllocationRequestshift(size, 0)) {
				spaceOkay = 0;
				goto l1;
			}
			/* begin sufficientSpaceToAllocate: */
			minFree1 = (lowSpaceThreshold + (2500 + size)) + BaseHeaderSize;
			if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) >= (((usqInt) minFree1))) {
				spaceOkay = 1;
				goto l3;
			} else {
				spaceOkay = sufficientSpaceAfterGC(minFree1);
				goto l3;
			}
		l3:	/* end sufficientSpaceToAllocate: */;
			goto l1;
		}
	l1:	/* end sufficientSpaceToInstantiate:indexableSize: */;
		/* begin success: */
		successFlag = spaceOkay && successFlag;
		class = longAt(stackPointer - (1 * BytesPerWord));
	}
	if (successFlag) {
		/* begin pop:thenPush: */
		oop = instantiateClassindexableSize(class, size);
		longAtput(sp = stackPointer - ((2 - 1) * BytesPerWord), oop);
		stackPointer = sp;
	}
}


/*	PrimitiveNext will succeed only if the stream's array is in the atCache.
	Otherwise failure will lead to proper message lookup of at: and
	subsequent installation in the cache if appropriate. */

sqInt primitiveNext(void) {
    sqInt stream;
    sqInt result;
    sqInt atIx;
    sqInt array;
    sqInt index;
    sqInt limit;
    sqInt sp;

	stream = longAt(stackPointer);
	if (!((((stream & 1) == 0) && (((((usqInt) (longAt(stream))) >> 8) & 15) <= 4)) && ((lengthOf(stream)) >= (StreamReadLimitIndex + 1)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	array = longAt((stream + BaseHeaderSize) + (StreamArrayIndex << ShiftForWord));
	index = fetchIntegerofObject(StreamIndexIndex, stream);
	limit = fetchIntegerofObject(StreamReadLimitIndex, stream);
	atIx = array & AtCacheMask;
	if (!((index < limit) && ((atCache[atIx + AtCacheOop]) == array))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	index += 1;

	/* Above may cause GC, so can't use stream, array etc. below it */

	result = commonVariableatcacheIndex(array, index, atIx);
	if (successFlag) {
		stream = longAt(stackPointer);
		/* begin storeInteger:ofObject:withValue: */
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) index)) ^ ((((int) index)) << 1)) >= 0)
# else
			((index >= -1073741824) && (index <= 1073741823))
# endif  // SQ_HOST32
		) {
			longAtput((stream + BaseHeaderSize) + (StreamIndexIndex << ShiftForWord), ((index << 1) | 1));
		} else {
			/* begin primitiveFail */
			successFlag = 0;
		}
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((1 - 1) * BytesPerWord), result);
		stackPointer = sp;
		return null;
	}
}

sqInt primitiveNextInstance(void) {
    sqInt object;
    sqInt instance;
    sqInt sp;
    sqInt thisClass;
    sqInt classPointer;
    sqInt thisObj;
    sqInt ccIndex;
    sqInt ccIndex1;

	object = longAt(stackPointer);
	/* begin instanceAfter: */
	/* begin fetchClassOf: */
	if ((object & 1)) {
		classPointer = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l3;
	}
	ccIndex1 = (((usqInt) (longAt(object))) >> 12) & 31;
	if (ccIndex1 == 0) {
		classPointer = (longAt(object - BaseHeaderSize)) & AllButTypeMask;
		goto l3;
	} else {
		classPointer = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex1 - 1) << ShiftForWord));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	thisObj = accessibleObjectAfter(object);
	while (!(thisObj == null)) {
		/* begin fetchClassOf: */
		if ((thisObj & 1)) {
			thisClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
			goto l2;
		}
		ccIndex = (((usqInt) (longAt(thisObj))) >> 12) & 31;
		if (ccIndex == 0) {
			thisClass = (longAt(thisObj - BaseHeaderSize)) & AllButTypeMask;
			goto l2;
		} else {
			thisClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
			goto l2;
		}
	l2:	/* end fetchClassOf: */;
		if (thisClass == classPointer) {
			instance = thisObj;
			goto l1;
		}
		thisObj = accessibleObjectAfter(thisObj);
	}
	instance = nilObj;
l1:	/* end instanceAfter: */;
	if (instance == nilObj) {
		/* begin primitiveFail */
		successFlag = 0;
	} else {
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - (((argumentCount + 1) - 1) * BytesPerWord), instance);
		stackPointer = sp;
	}
}


/*	Return the object following the receiver in the heap. Return the SmallInteger zero when there are no more objects. */

sqInt primitiveNextObject(void) {
    sqInt object;
    sqInt instance;
    sqInt sp;
    sqInt sp1;

	object = longAt(stackPointer);
	instance = accessibleObjectAfter(object);
	if (instance == null) {
		/* begin pop:thenPushInteger: */
		longAtput(sp = stackPointer - (((argumentCount + 1) - 1) * BytesPerWord), ((0 << 1) | 1));
		stackPointer = sp;
	} else {
		/* begin pop:thenPush: */
		longAtput(sp1 = stackPointer - (((argumentCount + 1) - 1) * BytesPerWord), instance);
		stackPointer = sp1;
	}
}


/*	PrimitiveNextPut will succeed only if the stream's array is in the atPutCache.
	Otherwise failure will lead to proper message lookup of at:put: and
	subsequent installation in the cache if appropriate. */

sqInt primitiveNextPut(void) {
    sqInt stream;
    sqInt value;
    sqInt atIx;
    sqInt array;
    sqInt index;
    sqInt limit;
    sqInt sp;
    sqInt valToPut;
    sqInt fmt;
    sqInt fixedFields;
    sqInt stSize;

	value = longAt(stackPointer);
	stream = longAt(stackPointer - (1 * BytesPerWord));
	if (!((((stream & 1) == 0) && (((((usqInt) (longAt(stream))) >> 8) & 15) <= 4)) && ((lengthOf(stream)) >= (StreamReadLimitIndex + 1)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	array = longAt((stream + BaseHeaderSize) + (StreamArrayIndex << ShiftForWord));
	index = fetchIntegerofObject(StreamIndexIndex, stream);
	limit = fetchIntegerofObject(StreamReadLimitIndex, stream);
	atIx = (array & AtCacheMask) + AtPutBase;
	if (!((index < limit) && ((atCache[atIx + AtCacheOop]) == array))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	index += 1;
	/* begin commonVariable:at:put:cacheIndex: */
	stSize = atCache[atIx + AtCacheSize];
	if (((((usqInt) index)) >= (((usqInt) 1))) && ((((usqInt) index)) <= (((usqInt) stSize)))) {
		fmt = atCache[atIx + AtCacheFmt];
		if (fmt <= 4) {
			fixedFields = atCache[atIx + AtCacheFixedFields];
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) array)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(array, value);
			}
			longAtput((array + BaseHeaderSize) + (((index + fixedFields) - 1) << ShiftForWord), value);
			goto l1;
		}
		if (fmt < 8) {
			valToPut = positive32BitValueOf(value);
			if (successFlag) {
				long32Atput((array + BaseHeaderSize) + ((index - 1) << 2), valToPut);
			}
			goto l1;
		}
		if (fmt >= 16) {
			valToPut = asciiOfCharacter(value);
			if (!(successFlag)) {
				goto l1;
			}
		} else {
			valToPut = value;
		}
		if ((valToPut & 1)) {
			valToPut = (valToPut >> 1);
			if (!((valToPut >= 0) && (valToPut <= 255))) {
				/* begin primitiveFail */
				successFlag = 0;
				goto l1;
			}
			byteAtput((array + BaseHeaderSize) + (index - 1), valToPut);
			goto l1;
		}
	}
	/* begin primitiveFail */
	successFlag = 0;
l1:	/* end commonVariable:at:put:cacheIndex: */;
	if (successFlag) {
		/* begin storeInteger:ofObject:withValue: */
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) index)) ^ ((((int) index)) << 1)) >= 0)
# else
			((index >= -1073741824) && (index <= 1073741823))
# endif  // SQ_HOST32
		) {
			longAtput((stream + BaseHeaderSize) + (StreamIndexIndex << ShiftForWord), ((index << 1) | 1));
		} else {
			/* begin primitiveFail */
			successFlag = 0;
		}
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((2 - 1) * BytesPerWord), value);
		stackPointer = sp;
		return null;
	}
}


/*	A placeholder for primitives that haven't been implemented or are being withdrawn gradually. Just absorbs any arguments and returns the receiver. */

sqInt primitiveNoop(void) {
	/* begin pop: */
	stackPointer -= argumentCount * BytesPerWord;
}

sqInt primitiveNotEqual(void) {
    sqInt integerArgument;
    sqInt result;
    sqInt integerReceiver;
    sqInt top;
    sqInt top1;
    sqInt sp;
    sqInt sp1;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerArgument = top;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerReceiver = top1;
	result = !(compare31or32Bitsequal(integerReceiver, integerArgument));
	/* begin checkBooleanResult: */
	if (successFlag) {
		/* begin pushBool: */
		if (result) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
	} else {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
	}
}


/*	Defined for CompiledMethods only */

sqInt primitiveObjectAt(void) {
    sqInt thisReceiver;
    sqInt index;
    sqInt sp;
    sqInt integerPointer;
    sqInt top;
    sqInt top1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l1;
	}
	index = null;
l1:	/* end popInteger */;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	thisReceiver = top1;
	/* begin success: */
	successFlag = (index > 0) && successFlag;
	/* begin success: */
	successFlag = (index <= (((((usqInt) (longAt((thisReceiver + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 10) & 255) + LiteralStart)) && successFlag;
	if (successFlag) {
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, longAt((thisReceiver + BaseHeaderSize) + ((index - 1) << ShiftForWord)));
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
	}
}


/*	Defined for CompiledMethods only */

sqInt primitiveObjectAtPut(void) {
    sqInt newValue;
    sqInt thisReceiver;
    sqInt index;
    sqInt sp;
    sqInt top;
    sqInt integerPointer;
    sqInt top1;
    sqInt top2;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	newValue = top;
	/* begin popInteger */
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerPointer = top1;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l1;
	}
	index = null;
l1:	/* end popInteger */;
	/* begin popStack */
	top2 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	thisReceiver = top2;
	/* begin success: */
	successFlag = (index > 0) && successFlag;
	/* begin success: */
	successFlag = (index <= (((((usqInt) (longAt((thisReceiver + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 10) & 255) + LiteralStart)) && successFlag;
	if (successFlag) {
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) thisReceiver)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(thisReceiver, newValue);
		}
		longAtput((thisReceiver + BaseHeaderSize) + ((index - 1) << ShiftForWord), newValue);
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, newValue);
		stackPointer = sp;
	} else {
		/* begin unPop: */
		stackPointer += 3 * BytesPerWord;
	}
}

sqInt primitiveObjectPointsTo(void) {
    sqInt thang;
    sqInt i;
    sqInt rcvr;
    sqInt lastField;
    sqInt top;
    sqInt top1;
    sqInt sp;
    sqInt sp1;
    sqInt sp2;
    sqInt sp11;
    sqInt sz;
    sqInt header;
    sqInt contextSize;
    sqInt fmt;
    sqInt methodHeader;
    sqInt sp3;
    sqInt sp12;
    sqInt sp4;
    sqInt header1;
    sqInt type;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	thang = top;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	rcvr = top1;
	if ((rcvr & 1)) {
		/* begin pushBool: */
		if (0) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
		return null;
	}
	/* begin lastPointerOf: */
	header = longAt(rcvr);
	fmt = (((usqInt) header) >> 8) & 15;
	if (fmt <= 4) {
		if ((fmt == 3) && ((((((usqInt) header) >> 12) & 31) == 13) || ((((((usqInt) header) >> 12) & 31) == 14) || (((((usqInt) header) >> 12) & 31) == 4)))) {
			/* begin fetchStackPointerOf: */
			sp4 = longAt((rcvr + BaseHeaderSize) + (StackPointerIndex << ShiftForWord));
			if (!((sp4 & 1))) {
				contextSize = 0;
				goto l2;
			}
			contextSize = (sp4 >> 1);
		l2:	/* end fetchStackPointerOf: */;
			lastField = (CtxtTempFrameStart + contextSize) * BytesPerWord;
			goto l1;
		}
		/* begin sizeBitsOfSafe: */
		header1 = longAt(rcvr);
		/* begin rightType: */
		if ((header1 & SizeMask) == 0) {
			type = HeaderTypeSizeAndClass;
			goto l3;
		} else {
			if ((header1 & CompactClassMask) == 0) {
				type = HeaderTypeClass;
				goto l3;
			} else {
				type = HeaderTypeShort;
				goto l3;
			}
		}
	l3:	/* end rightType: */;
		if (type == HeaderTypeSizeAndClass) {
			sz = (longAt(rcvr - (BytesPerWord * 2))) & AllButTypeMask;
			goto l4;
		} else {
			sz = header1 & SizeMask;
			goto l4;
		}
	l4:	/* end sizeBitsOfSafe: */;
		lastField = sz - BaseHeaderSize;
		goto l1;
	}
	if (fmt < 12) {
		lastField = 0;
		goto l1;
	}
	methodHeader = longAt(rcvr + BaseHeaderSize);
	lastField = (((((usqInt) methodHeader) >> 10) & 255) * BytesPerWord) + BaseHeaderSize;
l1:	/* end lastPointerOf: */;
	for (i = BaseHeaderSize; i <= lastField; i += BytesPerWord) {
		if ((longAt(rcvr + i)) == thang) {
			/* begin pushBool: */
			if (1) {
				/* begin push: */
				longAtput(sp2 = stackPointer + BytesPerWord, trueObj);
				stackPointer = sp2;
			} else {
				/* begin push: */
				longAtput(sp11 = stackPointer + BytesPerWord, falseObj);
				stackPointer = sp11;
			}
			return null;
		}
	}
	/* begin pushBool: */
	if (0) {
		/* begin push: */
		longAtput(sp3 = stackPointer + BytesPerWord, trueObj);
		stackPointer = sp3;
	} else {
		/* begin push: */
		longAtput(sp12 = stackPointer + BytesPerWord, falseObj);
		stackPointer = sp12;
	}
}


/*	Primitive. Invoke an obsolete indexed primitive. */

sqInt primitiveObsoleteIndexedPrimitive(void) {
    char * functionName;
    char * pluginName;
    void * functionAddress;

	functionAddress = ((void *) ((obsoleteIndexedPrimitiveTable[primitiveIndex])[2]));
	if (!(functionAddress == null)) {
		return ((sqInt (*)(void))functionAddress)();
	}
	pluginName = (obsoleteIndexedPrimitiveTable[primitiveIndex])[0];
	functionName = (obsoleteIndexedPrimitiveTable[primitiveIndex])[1];
	if ((pluginName == null) && (functionName == null)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	functionAddress = ioLoadFunctionFrom(functionName, pluginName);
	if (!(functionAddress == 0)) {
		(obsoleteIndexedPrimitiveTable[primitiveIndex])[2] = (((char*) functionAddress));
		return ((sqInt (*)(void))functionAddress)();
	}
	/* begin primitiveFail */
	successFlag = 0;
	return null;
}

sqInt primitivePerform(void) {
    sqInt newReceiver;
    sqInt performMethod;
    sqInt i;
    sqInt performSelector;
    sqInt selectorIndex;
    sqInt lookupClass;
    sqInt fieldIndex;
    sqInt oop;
    sqInt valuePointer;
    sqInt oop1;
    sqInt valuePointer1;
    sqInt count;
    sqInt fromOop;
    sqInt toOop;
    sqInt fromIndex;
    sqInt lastFrom;
    sqInt toIndex;
    sqInt ccIndex;

	performSelector = messageSelector;
	performMethod = newMethod;
	messageSelector = longAt(stackPointer - ((argumentCount - 1) * BytesPerWord));

	/* NOTE: the following lookup may fail and be converted to #doesNotUnderstand:, so we must adjust argumentCount and slide args now, so that would work. */
	/* Slide arguments down over selector */

	newReceiver = longAt(stackPointer - (argumentCount * BytesPerWord));
	argumentCount -= 1;
	selectorIndex = (((usqInt) ((stackPointer - activeContext) - BaseHeaderSize)) >> ShiftForWord) - argumentCount;
	/* begin transfer:fromIndex:ofObject:toIndex:ofObject: */
	count = argumentCount;
	fromOop = activeContext;
	toOop = activeContext;
	flag("Dan");
	fromIndex = fromOop + ((selectorIndex + 1) * BytesPerWord);
	toIndex = toOop + (selectorIndex * BytesPerWord);
	lastFrom = fromIndex + (count * BytesPerWord);
	while ((((usqInt) fromIndex)) < (((usqInt) lastFrom))) {
		fromIndex += BytesPerWord;
		toIndex += BytesPerWord;
		longAtput(toIndex, longAt(fromIndex));
	}
	/* begin pop: */
	stackPointer -= 1 * BytesPerWord;
	/* begin fetchClassOf: */
	if ((newReceiver & 1)) {
		lookupClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(newReceiver))) >> 12) & 31;
	if (ccIndex == 0) {
		lookupClass = (longAt(newReceiver - BaseHeaderSize)) & AllButTypeMask;
		goto l1;
	} else {
		lookupClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	findNewMethodInClass(lookupClass);
	if (((((usqInt) (longAt(newMethod))) >> 8) & 15) >= 12) {
		/* begin success: */
		successFlag = (((((usqInt) (longAt((newMethod + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 25) & 15) == argumentCount) && successFlag;
	}
	if (successFlag) {
		executeNewMethodFromCache();
		successFlag = 1;
	} else {
		for (i = 1; i <= argumentCount; i += 1) {
			/* begin storePointer:ofObject:withValue: */
			fieldIndex = ((argumentCount - i) + 1) + selectorIndex;
			oop = activeContext;
			valuePointer = longAt((activeContext + BaseHeaderSize) + (((argumentCount - i) + selectorIndex) << ShiftForWord));
			if ((((usqInt) oop)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(oop, valuePointer);
			}
			longAtput((oop + BaseHeaderSize) + (fieldIndex << ShiftForWord), valuePointer);
		}
		/* begin unPop: */
		stackPointer += 1 * BytesPerWord;
		/* begin storePointer:ofObject:withValue: */
		oop1 = activeContext;
		valuePointer1 = messageSelector;
		if ((((usqInt) oop1)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(oop1, valuePointer1);
		}
		longAtput((oop1 + BaseHeaderSize) + (selectorIndex << ShiftForWord), valuePointer1);
		argumentCount += 1;
		newMethod = performMethod;
		messageSelector = performSelector;
	}
}


/*	Common routine used by perform:withArgs: and perform:withArgs:inSuperclass: */
/*	NOTE:  The case of doesNotUnderstand: is not a failure to perform.
	The only failures are arg types and consistency of argumentCount. */

sqInt primitivePerformAt(sqInt lookupClass) {
    sqInt performArgCount;
    sqInt cntxSize;
    sqInt performMethod;
    sqInt performSelector;
    sqInt arraySize;
    sqInt argumentArray;
    sqInt index;
    sqInt sz;
    sqInt header;
    sqInt sz1;
    sqInt header1;
    sqInt sp;
    sqInt sp1;
    sqInt sp2;
    sqInt top;
    sqInt top1;

	argumentArray = longAt(stackPointer);
	if (!(((argumentArray & 1) == 0) && (((((usqInt) (longAt(argumentArray))) >> 8) & 15) == 2))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (successFlag) {
		/* begin fetchWordLengthOf: */
		/* begin sizeBitsOf: */
		header = longAt(argumentArray);
		if ((header & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(argumentArray - (BytesPerWord * 2))) & LongSizeMask;
			goto l1;
		} else {
			sz = header & SizeMask;
			goto l1;
		}
	l1:	/* end sizeBitsOf: */;
		arraySize = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
		/* begin fetchWordLengthOf: */
		/* begin sizeBitsOf: */
		header1 = longAt(activeContext);
		if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
			sz1 = (longAt(activeContext - (BytesPerWord * 2))) & LongSizeMask;
			goto l2;
		} else {
			sz1 = header1 & SizeMask;
			goto l2;
		}
	l2:	/* end sizeBitsOf: */;
		cntxSize = ((usqInt) (sz1 - BaseHeaderSize)) >> ShiftForWord;
		/* begin success: */
		successFlag = (((((usqInt) ((stackPointer - activeContext) - BaseHeaderSize)) >> ShiftForWord) + arraySize) < cntxSize) && successFlag;
	}
	if (!(successFlag)) {
		return null;
	}
	performSelector = messageSelector;
	performMethod = newMethod;

	/* pop the arg array and the selector, then push the args out of the array, as if they were on the stack */

	performArgCount = argumentCount;
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	messageSelector = top1;
	index = 1;
	while (index <= arraySize) {
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, longAt((argumentArray + BaseHeaderSize) + ((index - 1) << ShiftForWord)));
		stackPointer = sp;
		index += 1;
	}
	argumentCount = arraySize;
	findNewMethodInClass(lookupClass);
	if (((((usqInt) (longAt(newMethod))) >> 8) & 15) >= 12) {
		/* begin success: */
		successFlag = (((((usqInt) (longAt((newMethod + BaseHeaderSize) + (HeaderIndex << ShiftForWord)))) >> 25) & 15) == argumentCount) && successFlag;
	}
	if (successFlag) {
		executeNewMethodFromCache();
		successFlag = 1;
	} else {
		/* begin pop: */
		stackPointer -= argumentCount * BytesPerWord;
		/* begin push: */
		longAtput(sp1 = stackPointer + BytesPerWord, messageSelector);
		stackPointer = sp1;
		/* begin push: */
		longAtput(sp2 = stackPointer + BytesPerWord, argumentArray);
		stackPointer = sp2;
		messageSelector = performSelector;
		newMethod = performMethod;
		argumentCount = performArgCount;
	}
}

sqInt primitivePerformInSuperclass(void) {
    sqInt currentClass;
    sqInt rcvr;
    sqInt lookupClass;
    sqInt sp;
    sqInt ccIndex;
    sqInt top;

	lookupClass = longAt(stackPointer);
	rcvr = longAt(stackPointer - (argumentCount * BytesPerWord));
	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		currentClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		currentClass = (longAt(rcvr - BaseHeaderSize)) & AllButTypeMask;
		goto l1;
	} else {
		currentClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	while (currentClass != lookupClass) {
		currentClass = longAt((currentClass + BaseHeaderSize) + (SuperclassIndex << ShiftForWord));
		if (currentClass == nilObj) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	primitivePerformAt(lookupClass);
	if (!(successFlag)) {
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, lookupClass);
		stackPointer = sp;
	}
}

sqInt primitivePerformWithArgs(void) {
    sqInt rcvr;
    sqInt lookupClass;
    sqInt ccIndex;

	rcvr = longAt(stackPointer - (argumentCount * BytesPerWord));
	/* begin fetchClassOf: */
	if ((rcvr & 1)) {
		lookupClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(rcvr))) >> 12) & 31;
	if (ccIndex == 0) {
		lookupClass = (longAt(rcvr - BaseHeaderSize)) & AllButTypeMask;
		goto l1;
	} else {
		lookupClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	primitivePerformAt(lookupClass);
}

sqInt primitivePushFalse(void) {
    sqInt top;
    sqInt sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	/* begin push: */
	longAtput(sp = stackPointer + BytesPerWord, falseObj);
	stackPointer = sp;
}

sqInt primitivePushMinusOne(void) {
    sqInt top;
    sqInt sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	/* begin push: */
	longAtput(sp = stackPointer + BytesPerWord, ConstMinusOne);
	stackPointer = sp;
}

sqInt primitivePushNil(void) {
    sqInt top;
    sqInt sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	/* begin push: */
	longAtput(sp = stackPointer + BytesPerWord, nilObj);
	stackPointer = sp;
}

sqInt primitivePushOne(void) {
    sqInt top;
    sqInt sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	/* begin push: */
	longAtput(sp = stackPointer + BytesPerWord, ConstOne);
	stackPointer = sp;
}


/*		no-op, really...
	thisReceiver := self popStack.
	self push: thisReceiver
 */

sqInt primitivePushSelf(void) {
}

sqInt primitivePushTrue(void) {
    sqInt top;
    sqInt sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	/* begin push: */
	longAtput(sp = stackPointer + BytesPerWord, trueObj);
	stackPointer = sp;
}

sqInt primitivePushTwo(void) {
    sqInt top;
    sqInt sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	/* begin push: */
	longAtput(sp = stackPointer + BytesPerWord, ConstTwo);
	stackPointer = sp;
}

sqInt primitivePushZero(void) {
    sqInt top;
    sqInt sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	/* begin push: */
	longAtput(sp = stackPointer + BytesPerWord, ConstZero);
	stackPointer = sp;
}

sqInt primitiveQuit(void) {
	ioExit();
}


/*	Rounds negative results towards zero. */

sqInt primitiveQuo(void) {
    sqInt integerArg;
    sqInt integerResult;
    sqInt integerRcvr;
    sqInt integerPointer;
    sqInt integerPointer1;
    sqInt sp;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		integerRcvr = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerRcvr = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		integerArg = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		integerArg = 0;
		goto l2;
	}
l2:	/* end checkedIntegerValueOf: */;
	/* begin success: */
	successFlag = (integerArg != 0) && successFlag;
	if (successFlag) {
		if (integerRcvr > 0) {
			if (integerArg > 0) {
				integerResult = integerRcvr / integerArg;
			} else {
				integerResult = 0 - (integerRcvr / (0 - integerArg));
			}
		} else {
			if (integerArg > 0) {
				integerResult = 0 - ((0 - integerRcvr) / integerArg);
			} else {
				integerResult = (0 - integerRcvr) / (0 - integerArg);
			}
		}
	}
	/* begin pop2AndPushIntegerIfOK: */
	if (successFlag) {
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) integerResult)) ^ ((((int) integerResult)) << 1)) >= 0)
# else
			((integerResult >= -1073741824) && (integerResult <= 1073741823))
# endif  // SQ_HOST32
		) {
			/* begin pop:thenPush: */
			longAtput(sp = stackPointer - ((2 - 1) * BytesPerWord), ((integerResult << 1) | 1));
			stackPointer = sp;
		} else {
			successFlag = 0;
		}
	}
}


/*	Relinquish the processor for up to the given number of microseconds. The exact behavior of this primitive is platform dependent. */

sqInt primitiveRelinquishProcessor(void) {
    sqInt microSecs;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		microSecs = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		microSecs = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	if (successFlag) {
		ioRelinquishProcessorForMicroseconds(microSecs);
		/* begin pop: */
		stackPointer -= 1 * BytesPerWord;
	}
}


/*	NB: tpr removed the timer checks here and moved them to the primitiveExternalCall method.
	We make the possibly unwarranted assumption that numbered prims are quick and external prims are slow. */

sqInt primitiveResponse(void) {
    sqInt delta;
    sqInt primIdx;
    sqInt nArgs;

	if (DoBalanceChecks) {

		/* check stack balance */

		nArgs = argumentCount;
		delta = stackPointer - activeContext;
	}
	primIdx = primitiveIndex;

	/* self dispatchOn: primitiveIndex in: primitiveTable. */

	successFlag = 1;
	dispatchFunctionPointerOnin(primIdx, primitiveTable);
	if (DoBalanceChecks) {
		if (!(balancedStackafterPrimitivewithArgs(delta, primIdx, nArgs))) {
			printUnbalancedStack(primIdx);
		}
	}

	/* clear out primIndex so VM knows we're no longer in primitive */

	primitiveIndex = 0;
	return successFlag;
}


/*	put this process on the scheduler's lists thus allowing it to proceed next time there is a chance for processes of it's priority level */

sqInt primitiveResume(void) {
    sqInt proc;


	/* rcvr */
	/* self success: ((self fetchClassOf: proc) = (self splObj: ClassProcess)). */

	proc = longAt(stackPointer);
	if (successFlag) {
		resume(proc);
	}
}


/*	Primitive. Answer a copy (snapshot) element of the root table.
	The primitive can cause GC itself and if so the return value may
	be inaccurate - in this case one should guard the read operation
	by looking at the gc counter statistics. */

EXPORT(sqInt) primitiveRootTable(void) {
    sqInt oop;
    sqInt sz;
    sqInt i;
    sqInt valuePointer;
    sqInt sp;

	sz = rootTableCount;

	/* can cause GC */

	oop = instantiateClassindexableSize(longAt((specialObjectsOop + BaseHeaderSize) + (ClassArray << ShiftForWord)), sz);
	if (sz > rootTableCount) {
		sz = rootTableCount;
	}
	for (i = 1; i <= sz; i += 1) {
		/* begin storePointer:ofObject:withValue: */
		valuePointer = rootTable[i];
		if ((((usqInt) oop)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(oop, valuePointer);
		}
		longAtput((oop + BaseHeaderSize) + ((i - 1) << ShiftForWord), valuePointer);
	}
	/* begin pop: */
	stackPointer -= (argumentCount + 1) * BytesPerWord;
	/* begin push: */
	longAtput(sp = stackPointer + BytesPerWord, oop);
	stackPointer = sp;
}


/*	Primitive. Answer the nth element of the root table.
	This primitive avoids the creation of an extra array;
	it is intended for enumerations of the form:
		index := 1.
		[root := Smalltalk rootTableAt: index.
		root == nil] whileFalse:[index := index + 1].
	 */

EXPORT(sqInt) primitiveRootTableAt(void) {
    sqInt index;
    sqInt successValue;
    sqInt sp;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	/* begin success: */
	successValue = (index > 0) && (index <= rootTableCount);
	successFlag = successValue && successFlag;
	if (successFlag) {
		/* begin pop: */
		stackPointer -= (argumentCount + 1) * BytesPerWord;
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, rootTable[index]);
		stackPointer = sp;
	}
}


/*	The character scanner primitive. */

sqInt primitiveScanCharacters(void) {
    sqInt ascii;
    sqInt stopReason;
    sqInt nextDestX;
    sqInt scanStartIndex;
    sqInt nilOop;
    sqInt scanMap;
    sqInt scanStopIndex;
    sqInt scanDestX;
    sqInt sourceX;
    sqInt scanLastIndex;
    sqInt kernDelta;
    sqInt rcvr;
    sqInt stops;
    sqInt maxGlyph;
    sqInt sourceX2;
    sqInt scanRightX;
    sqInt scanXTable;
    sqInt glyphIndex;
    sqInt sourceString;
    sqInt sp;
    sqInt sp1;
    sqInt integerPointer;
    sqInt oop;
    sqInt integerPointer1;
    sqInt oop1;
    sqInt integerPointer2;
    sqInt integerPointer3;
    sqInt oop2;
    sqInt sp2;

	if (!(argumentCount == 6)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		kernDelta = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		kernDelta = 0;
		goto l1;
	}
	kernDelta = null;
l1:	/* end stackIntegerValue: */;
	/* begin stackObjectValue: */
	oop = longAt(stackPointer - (1 * BytesPerWord));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		stops = null;
		goto l2;
	}
	stops = oop;
l2:	/* end stackObjectValue: */;
	if (!(((stops & 1) == 0) && (((((usqInt) (longAt(stops))) >> 8) & 15) == 2))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((slotSizeOf(stops)) >= 258)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (2 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		scanRightX = (integerPointer1 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		scanRightX = 0;
		goto l3;
	}
	scanRightX = null;
l3:	/* end stackIntegerValue: */;
	/* begin stackObjectValue: */
	oop1 = longAt(stackPointer - (3 * BytesPerWord));
	if ((oop1 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		sourceString = null;
		goto l4;
	}
	sourceString = oop1;
l4:	/* end stackObjectValue: */;
	if (!(((sourceString & 1) == 0) && (((((usqInt) (longAt(sourceString))) >> 8) & 15) >= 8))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (4 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer2 & 1)) {
		scanStopIndex = (integerPointer2 >> 1);
		goto l5;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		scanStopIndex = 0;
		goto l5;
	}
	scanStopIndex = null;
l5:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer3 = longAt(stackPointer - (5 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer3 & 1)) {
		scanStartIndex = (integerPointer3 >> 1);
		goto l6;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		scanStartIndex = 0;
		goto l6;
	}
	scanStartIndex = null;
l6:	/* end stackIntegerValue: */;
	if (!((scanStartIndex > 0) && ((scanStopIndex > 0) && (scanStopIndex <= (byteSizeOf(sourceString)))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin stackObjectValue: */
	oop2 = longAt(stackPointer - (6 * BytesPerWord));
	if ((oop2 & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		rcvr = null;
		goto l7;
	}
	rcvr = oop2;
l7:	/* end stackObjectValue: */;
	if (!((((rcvr & 1) == 0) && (((((usqInt) (longAt(rcvr))) >> 8) & 15) <= 4)) && ((slotSizeOf(rcvr)) >= 4))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	scanDestX = fetchIntegerofObject(0, rcvr);
	scanLastIndex = fetchIntegerofObject(1, rcvr);
	scanXTable = longAt((rcvr + BaseHeaderSize) + (2 << ShiftForWord));
	scanMap = longAt((rcvr + BaseHeaderSize) + (3 << ShiftForWord));
	if (!((((scanXTable & 1) == 0) && (((((usqInt) (longAt(scanXTable))) >> 8) & 15) == 2)) && (((scanMap & 1) == 0) && (((((usqInt) (longAt(scanMap))) >> 8) & 15) == 2)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((slotSizeOf(scanMap)) == 256)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(successFlag)) {
		return null;
	}

	/* Okay, here we go. We have eliminated nearly all failure 
	conditions, to optimize the inner fetches. */

	maxGlyph = (slotSizeOf(scanXTable)) - 2;
	scanLastIndex = scanStartIndex;
	nilOop = nilObj;
	while (scanLastIndex <= scanStopIndex) {

		/* Known to be okay since scanStartIndex > 0 and scanStopIndex <= sourceString size */
		/* Known to be okay since stops size >= 258 */

		ascii = byteAt((sourceString + BaseHeaderSize) + (scanLastIndex - 1));
		if (!((stopReason = longAt((stops + BaseHeaderSize) + (ascii << ShiftForWord))) == nilOop)) {
			if (!(
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
				(((((int) scanDestX)) ^ ((((int) scanDestX)) << 1)) >= 0)
# else
				((scanDestX >= -1073741824) && (scanDestX <= 1073741823))
# endif  // SQ_HOST32
			)) {
				/* begin primitiveFail */
				successFlag = 0;
				return null;
			}
			/* begin storeInteger:ofObject:withValue: */
			if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
				(((((int) scanDestX)) ^ ((((int) scanDestX)) << 1)) >= 0)
# else
				((scanDestX >= -1073741824) && (scanDestX <= 1073741823))
# endif  // SQ_HOST32
			) {
				longAtput((rcvr + BaseHeaderSize) + (0 << ShiftForWord), ((scanDestX << 1) | 1));
			} else {
				/* begin primitiveFail */
				successFlag = 0;
			}
			/* begin storeInteger:ofObject:withValue: */
			if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
				(((((int) scanLastIndex)) ^ ((((int) scanLastIndex)) << 1)) >= 0)
# else
				((scanLastIndex >= -1073741824) && (scanLastIndex <= 1073741823))
# endif  // SQ_HOST32
			) {
				longAtput((rcvr + BaseHeaderSize) + (1 << ShiftForWord), ((scanLastIndex << 1) | 1));
			} else {
				/* begin primitiveFail */
				successFlag = 0;
			}
			/* begin pop: */
			stackPointer -= 7 * BytesPerWord;
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, stopReason);
			stackPointer = sp;
			return null;
		}

		/* fail if the glyphIndex is out of range */

		glyphIndex = fetchIntegerofObject(ascii, scanMap);
		if ((!successFlag) || ((glyphIndex < 0) || (glyphIndex > maxGlyph))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		sourceX = fetchIntegerofObject(glyphIndex, scanXTable);

		/* Above may fail if non-integer entries in scanXTable */

		sourceX2 = fetchIntegerofObject(glyphIndex + 1, scanXTable);
		if (!successFlag) {
			return null;
		}
		nextDestX = (scanDestX + sourceX2) - sourceX;
		if (nextDestX > scanRightX) {
			if (!(
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
				(((((int) scanDestX)) ^ ((((int) scanDestX)) << 1)) >= 0)
# else
				((scanDestX >= -1073741824) && (scanDestX <= 1073741823))
# endif  // SQ_HOST32
			)) {
				/* begin primitiveFail */
				successFlag = 0;
				return null;
			}
			/* begin storeInteger:ofObject:withValue: */
			if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
				(((((int) scanDestX)) ^ ((((int) scanDestX)) << 1)) >= 0)
# else
				((scanDestX >= -1073741824) && (scanDestX <= 1073741823))
# endif  // SQ_HOST32
			) {
				longAtput((rcvr + BaseHeaderSize) + (0 << ShiftForWord), ((scanDestX << 1) | 1));
			} else {
				/* begin primitiveFail */
				successFlag = 0;
			}
			/* begin storeInteger:ofObject:withValue: */
			if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
				(((((int) scanLastIndex)) ^ ((((int) scanLastIndex)) << 1)) >= 0)
# else
				((scanLastIndex >= -1073741824) && (scanLastIndex <= 1073741823))
# endif  // SQ_HOST32
			) {
				longAtput((rcvr + BaseHeaderSize) + (1 << ShiftForWord), ((scanLastIndex << 1) | 1));
			} else {
				/* begin primitiveFail */
				successFlag = 0;
			}
			/* begin pop: */
			stackPointer -= 7 * BytesPerWord;
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, longAt((stops + BaseHeaderSize) + ((CrossedX - 1) << ShiftForWord)));
			stackPointer = sp1;
			return null;
		}
		scanDestX = nextDestX + kernDelta;
		scanLastIndex += 1;
	}
	if (!(
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) scanDestX)) ^ ((((int) scanDestX)) << 1)) >= 0)
# else
		((scanDestX >= -1073741824) && (scanDestX <= 1073741823))
# endif  // SQ_HOST32
	)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin storeInteger:ofObject:withValue: */
	if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) scanDestX)) ^ ((((int) scanDestX)) << 1)) >= 0)
# else
		((scanDestX >= -1073741824) && (scanDestX <= 1073741823))
# endif  // SQ_HOST32
	) {
		longAtput((rcvr + BaseHeaderSize) + (0 << ShiftForWord), ((scanDestX << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	/* begin storeInteger:ofObject:withValue: */
	if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) scanStopIndex)) ^ ((((int) scanStopIndex)) << 1)) >= 0)
# else
		((scanStopIndex >= -1073741824) && (scanStopIndex <= 1073741823))
# endif  // SQ_HOST32
	) {
		longAtput((rcvr + BaseHeaderSize) + (1 << ShiftForWord), ((scanStopIndex << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
	/* begin pop: */
	stackPointer -= 7 * BytesPerWord;
	/* begin push: */
	longAtput(sp2 = stackPointer + BytesPerWord, longAt((stops + BaseHeaderSize) + ((EndOfRun - 1) << ShiftForWord)));
	stackPointer = sp2;
	return null;
}


/*	Return a SmallInteger indicating the current depth of the OS screen. Negative values are used to imply LSB type pixel format an there is some support in the VM for handling either MSB or LSB */

EXPORT(sqInt) primitiveScreenDepth(void) {
    sqInt depth;
    sqInt sp;

	depth = ioScreenDepth();
	if (!successFlag) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin pop:thenPushInteger: */
	longAtput(sp = stackPointer - ((1 - 1) * BytesPerWord), ((depth << 1) | 1));
	stackPointer = sp;
}


/*	Return a point indicating the current size of the Smalltalk window. Currently there is a limit of 65535 in each direction because the point is encoded into a single 32bit value in the image header. This might well become a problem one day */

sqInt primitiveScreenSize(void) {
    sqInt pointWord;
    sqInt object;
    sqInt sp;
    sqInt pointResult;

	/* begin pop: */
	stackPointer -= 1 * BytesPerWord;
	pointWord = ioScreenSize();
	/* begin push: */
	/* begin makePointwithxValue:yValue: */
	pointResult = instantiateSmallClasssizeInBytes(longAt((specialObjectsOop + BaseHeaderSize) + (ClassPoint << ShiftForWord)), 3 * BytesPerWord);
	longAtput((pointResult + BaseHeaderSize) + (XIndex << ShiftForWord), ((((((usqInt) pointWord) >> 16) & 65535) << 1) | 1));
	longAtput((pointResult + BaseHeaderSize) + (YIndex << ShiftForWord), (((pointWord & 65535) << 1) | 1));
	object = pointResult;
	longAtput(sp = stackPointer + BytesPerWord, object);
	stackPointer = sp;
}


/*	Return the number of seconds since January 1, 1901 as an integer. */

sqInt primitiveSecondsClock(void) {
    sqInt oop;
    sqInt sp;

	/* begin pop:thenPush: */
	oop = positive32BitIntegerFor(ioSeconds());
	longAtput(sp = stackPointer - ((1 - 1) * BytesPerWord), oop);
	stackPointer = sp;
}


/*	Set to OS to the requested display mode.
	See also DisplayScreen setDisplayDepth:extent:fullscreen: */

sqInt primitiveSetDisplayMode(void) {
    sqInt okay;
    sqInt fsFlag;
    sqInt d;
    sqInt h;
    sqInt w;
    sqInt sp;
    sqInt sp1;
    sqInt integerPointer;
    sqInt integerPointer1;
    sqInt integerPointer2;

	/* begin booleanValueOf: */
	if ((longAt(stackPointer)) == trueObj) {
		fsFlag = 1;
		goto l1;
	}
	if ((longAt(stackPointer)) == falseObj) {
		fsFlag = 0;
		goto l1;
	}
	successFlag = 0;
	fsFlag = null;
l1:	/* end booleanValueOf: */;
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (1 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		h = (integerPointer >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		h = 0;
		goto l2;
	}
	h = null;
l2:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (2 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		w = (integerPointer1 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		w = 0;
		goto l3;
	}
	w = null;
l3:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (3 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer2 & 1)) {
		d = (integerPointer2 >> 1);
		goto l4;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		d = 0;
		goto l4;
	}
	d = null;
l4:	/* end stackIntegerValue: */;
	if (successFlag) {
		okay = ioSetDisplayMode(w, h, d, fsFlag);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 5 * BytesPerWord;
		/* begin pushBool: */
		if (okay) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
	}
}


/*	On platforms that support it, set full-screen mode to the value of the boolean argument. */

sqInt primitiveSetFullScreen(void) {
    sqInt argOop;

	argOop = longAt(stackPointer);
	if (argOop == trueObj) {
		ioSetFullScreen(1);
	} else {
		if (argOop == falseObj) {
			ioSetFullScreen(0);
		} else {
			/* begin primitiveFail */
			successFlag = 0;
		}
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * BytesPerWord;
	}
}


/*	Primitive. Indicate if the GC logic should have bias to grow */

EXPORT(sqInt) primitiveSetGCBiasToGrow(void) {
    sqInt flag;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		flag = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		flag = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	if (successFlag) {
		gcBiasToGrow = flag;
		/* begin pop: */
		stackPointer -= argumentCount * BytesPerWord;
	}
}


/*	Primitive. If the GC logic has  bias to grow, set growth limit */

EXPORT(sqInt) primitiveSetGCBiasToGrowGCLimit(void) {
    sqInt value;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		value = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		value = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	if (successFlag) {
		gcBiasToGrowGCLimit = value;
		gcBiasToGrowThreshold = youngStart - (((int) memory));
		/* begin pop: */
		stackPointer -= argumentCount * BytesPerWord;
	}
}


/*	Primitive. Indicate the semaphore to be signalled for upon garbage collection */

EXPORT(sqInt) primitiveSetGCSemaphore(void) {
    sqInt index;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	if (successFlag) {
		gcSemaphoreIndex = index;
		/* begin pop: */
		stackPointer -= argumentCount * BytesPerWord;
	}
}


/*	Set the user interrupt keycode. The keycode is an integer whose encoding is described in the comment for primitiveKbdNext. */

sqInt primitiveSetInterruptKey(void) {
    sqInt keycode;
    sqInt integerPointer;
    sqInt top;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		keycode = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		keycode = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	if (successFlag) {
		interruptKeycode = keycode;
	} else {
		/* begin unPop: */
		stackPointer += 1 * BytesPerWord;
	}
}


/*	Treat the receiver, which can be indexible by either bytes or words, as an array of signed 16-bit values. Return the contents of the given index. Note that the index specifies the i-th 16-bit entry, not the i-th byte or word. */

sqInt primitiveShortAt(void) {
    sqInt sz;
    sqInt value;
    sqInt rcvr;
    sqInt index;
    sqInt addr;
    sqInt sp;
    sqInt integerPointer;
    sqInt successValue;
    sqInt successValue1;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		index = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	rcvr = longAt(stackPointer - (1 * BytesPerWord));
	/* begin success: */
	successValue = (!((rcvr & 1))) && (((rcvr & 1) == 0) && (isWordsOrBytesNonInt(rcvr)));
	successFlag = successValue && successFlag;
	if (!(successFlag)) {
		return null;
	}

	/* number of 16-bit fields */

	sz = ((sqInt) ((sizeBitsOf(rcvr)) - BaseHeaderSize) >> 1);
	/* begin success: */
	successValue1 = (index >= 1) && (index <= sz);
	successFlag = successValue1 && successFlag;
	if (successFlag) {
		addr = (rcvr + BaseHeaderSize) + (2 * (index - 1));
		value = shortAt(addr);
		/* begin pop:thenPushInteger: */
		longAtput(sp = stackPointer - ((2 - 1) * BytesPerWord), ((value << 1) | 1));
		stackPointer = sp;
	}
}


/*	Treat the receiver, which can be indexible by either bytes or words, as an array of signed 16-bit values. Set the contents of the given index to the given value. Note that the index specifies the i-th 16-bit entry, not the i-th byte or word. */

sqInt primitiveShortAtPut(void) {
    sqInt sz;
    sqInt value;
    sqInt rcvr;
    sqInt index;
    sqInt addr;
    sqInt integerPointer;
    sqInt integerPointer1;
    sqInt successValue;
    sqInt successValue1;
    sqInt successValue2;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		value = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		value = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (1 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		index = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		index = 0;
		goto l2;
	}
l2:	/* end checkedIntegerValueOf: */;
	rcvr = longAt(stackPointer - (2 * BytesPerWord));
	/* begin success: */
	successValue = (!((rcvr & 1))) && (((rcvr & 1) == 0) && (isWordsOrBytesNonInt(rcvr)));
	successFlag = successValue && successFlag;
	if (!(successFlag)) {
		return null;
	}

	/* number of 16-bit fields */

	sz = ((sqInt) ((sizeBitsOf(rcvr)) - BaseHeaderSize) >> 1);
	/* begin success: */
	successValue1 = (index >= 1) && (index <= sz);
	successFlag = successValue1 && successFlag;
	/* begin success: */
	successValue2 = (value >= -32768) && (value <= 32767);
	successFlag = successValue2 && successFlag;
	if (successFlag) {
		addr = (rcvr + BaseHeaderSize) + (2 * (index - 1));
		shortAtput(addr, value);
		/* begin pop: */
		stackPointer -= 2 * BytesPerWord;
	}
}


/*	Force the given rectangular section of the Display to be 
	copied to the screen. */

sqInt primitiveShowDisplayRect(void) {
    sqInt right;
    sqInt bottom;
    sqInt top;
    sqInt left;
    sqInt integerPointer;
    sqInt integerPointer1;
    sqInt integerPointer2;
    sqInt integerPointer3;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		bottom = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		bottom = 0;
		goto l1;
	}
	bottom = null;
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (1 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		top = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		top = 0;
		goto l2;
	}
	top = null;
l2:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (2 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer2 & 1)) {
		right = (integerPointer2 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		right = 0;
		goto l3;
	}
	right = null;
l3:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer3 = longAt(stackPointer - (3 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer3 & 1)) {
		left = (integerPointer3 >> 1);
		goto l4;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		left = 0;
		goto l4;
	}
	left = null;
l4:	/* end stackIntegerValue: */;
	displayBitsOfLeftTopRightBottom(longAt((specialObjectsOop + BaseHeaderSize) + (TheDisplay << ShiftForWord)), left, top, right, bottom);
	if (successFlag) {
		ioForceDisplayUpdate();
		/* begin pop: */
		stackPointer -= 4 * BytesPerWord;
	}
}


/*	synchromously signal the semaphore. This may change the active process as a result */

sqInt primitiveSignal(void) {
    sqInt sema;
    sqInt cl;
    sqInt ccIndex;


	/* rcvr */

	sema = longAt(stackPointer);
	/* begin assertClassOf:is: */
	if ((sema & 1)) {
		successFlag = 0;
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(sema))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(sema - BaseHeaderSize)) & AllButTypeMask;
	} else {
		cl = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
	}
	/* begin success: */
	successFlag = (cl == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassSemaphore << ShiftForWord)))) && successFlag;
l1:	/* end assertClassOf:is: */;
	if (successFlag) {
		synchronousSignal(sema);
	}
}


/*	Set the low-water mark for free space. When the free space 
	falls below this level, the new and new: primitives fail and 
	system attempts to allocate space (e.g., to create a method 
	context) cause the low-space semaphore (if one is 
	registered) to be signalled. */

sqInt primitiveSignalAtBytesLeft(void) {
    sqInt bytes;
    sqInt integerPointer;
    sqInt top;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		bytes = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		bytes = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	if (successFlag) {
		lowSpaceThreshold = bytes;
	} else {
		lowSpaceThreshold = 0;
		/* begin unPop: */
		stackPointer += 1 * BytesPerWord;
	}
}


/*	Cause the time semaphore, if one has been registered, to
	be signalled when the millisecond clock is greater than or
	equal to the given tick value. A tick value of zero turns off
	timer interrupts. */

sqInt primitiveSignalAtMilliseconds(void) {
    sqInt tick;
    sqInt sema;
    sqInt oop;
    sqInt oop1;
    sqInt valuePointer;
    sqInt integerPointer;
    sqInt top;
    sqInt top1;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		tick = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		tick = 0;
		goto l1;
	}
	tick = null;
l1:	/* end popInteger */;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	sema = top1;
	if (successFlag) {
		if ((fetchClassOf(sema)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassSemaphore << ShiftForWord)))) {
			/* begin storePointer:ofObject:withValue: */
			oop = specialObjectsOop;
			if ((((usqInt) oop)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(oop, sema);
			}
			longAtput((oop + BaseHeaderSize) + (TheTimerSemaphore << ShiftForWord), sema);
			nextWakeupTick = tick;
		} else {
			/* begin storePointer:ofObject:withValue: */
			oop1 = specialObjectsOop;
			valuePointer = nilObj;
			if ((((usqInt) oop1)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(oop1, valuePointer);
			}
			longAtput((oop1 + BaseHeaderSize) + (TheTimerSemaphore << ShiftForWord), valuePointer);
			nextWakeupTick = 0;
		}
	} else {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
	}
}

sqInt primitiveSine(void) {
    double  rcvr;

	rcvr = popFloat();
	if (successFlag) {
		pushFloat(sin(rcvr));
	} else {
		/* begin unPop: */
		stackPointer += 1 * BytesPerWord;
	}
}

sqInt primitiveSize(void) {
    sqInt sz;
    sqInt rcvr;
    sqInt oop;
    sqInt sp;

	rcvr = longAt(stackPointer);
	if ((rcvr & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (((((usqInt) (longAt(rcvr))) >> 8) & 15) < 2) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	sz = stSizeOf(rcvr);
	if (successFlag) {
		/* begin pop:thenPush: */
		oop = positive32BitIntegerFor(sz);
		longAtput(sp = stackPointer - ((1 - 1) * BytesPerWord), oop);
		stackPointer = sp;
	}
}


/*	save a normal snapshot under the same name as it was loaded unless it has been renamed by the last primitiveImageName */

sqInt primitiveSnapshot(void) {
	return snapshot(0);
}


/*	save an embedded snapshot */

sqInt primitiveSnapshotEmbedded(void) {
	return snapshot(1);
}

sqInt primitiveSomeInstance(void) {
    sqInt class;
    sqInt instance;
    sqInt sp;
    sqInt thisClass;
    sqInt thisObj;
    sqInt ccIndex;
    sqInt obj;
    sqInt sz;
    sqInt header;

	class = longAt(stackPointer);
	/* begin initialInstanceOf: */
	/* begin firstAccessibleObject */
	obj = memory + (headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) obj)) < (((usqInt) endOfMemory))) {
		if (!(((longAt(obj)) & TypeMask) == HeaderTypeFree)) {
			thisObj = obj;
			goto l3;
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) obj)) >= (((usqInt) endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(obj)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(obj)) & AllButTypeMask;
		} else {
			/* begin sizeBitsOf: */
			header = longAt(obj);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(obj - (BytesPerWord * 2))) & LongSizeMask;
				goto l4;
			} else {
				sz = header & SizeMask;
				goto l4;
			}
		l4:	/* end sizeBitsOf: */;
		}
		obj = (obj + sz) + (headerTypeBytes[(longAt(obj + sz)) & TypeMask]);
	}
	error("heap is empty");
l3:	/* end firstAccessibleObject */;
	while (!(thisObj == null)) {
		/* begin fetchClassOf: */
		if ((thisObj & 1)) {
			thisClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
			goto l2;
		}
		ccIndex = (((usqInt) (longAt(thisObj))) >> 12) & 31;
		if (ccIndex == 0) {
			thisClass = (longAt(thisObj - BaseHeaderSize)) & AllButTypeMask;
			goto l2;
		} else {
			thisClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
			goto l2;
		}
	l2:	/* end fetchClassOf: */;
		if (thisClass == class) {
			instance = thisObj;
			goto l1;
		}
		thisObj = accessibleObjectAfter(thisObj);
	}
	instance = nilObj;
l1:	/* end initialInstanceOf: */;
	if (instance == nilObj) {
		/* begin primitiveFail */
		successFlag = 0;
	} else {
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - (((argumentCount + 1) - 1) * BytesPerWord), instance);
		stackPointer = sp;
	}
}


/*	Return the first object in the heap. */

sqInt primitiveSomeObject(void) {
    sqInt object;
    sqInt sp;
    sqInt obj;
    sqInt sz;
    sqInt header;

	/* begin pop: */
	stackPointer -= (argumentCount + 1) * BytesPerWord;
	/* begin push: */
	/* begin firstAccessibleObject */
	obj = memory + (headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) obj)) < (((usqInt) endOfMemory))) {
		if (!(((longAt(obj)) & TypeMask) == HeaderTypeFree)) {
			object = obj;
			goto l1;
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) obj)) >= (((usqInt) endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(obj)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(obj)) & AllButTypeMask;
		} else {
			/* begin sizeBitsOf: */
			header = longAt(obj);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(obj - (BytesPerWord * 2))) & LongSizeMask;
				goto l2;
			} else {
				sz = header & SizeMask;
				goto l2;
			}
		l2:	/* end sizeBitsOf: */;
		}
		obj = (obj + sz) + (headerTypeBytes[(longAt(obj + sz)) & TypeMask]);
	}
	error("heap is empty");
l1:	/* end firstAccessibleObject */;
	longAtput(sp = stackPointer + BytesPerWord, object);
	stackPointer = sp;
}


/*	Return the oop of the SpecialObjectsArray. */

sqInt primitiveSpecialObjectsOop(void) {
    sqInt sp;

	/* begin pop:thenPush: */
	longAtput(sp = stackPointer - ((1 - 1) * BytesPerWord), specialObjectsOop);
	stackPointer = sp;
}

sqInt primitiveSquareRoot(void) {
    double  rcvr;

	rcvr = popFloat();
	/* begin success: */
	successFlag = (rcvr >= 0.0) && successFlag;
	if (successFlag) {
		pushFloat(sqrt(rcvr));
	} else {
		/* begin unPop: */
		stackPointer += 1 * BytesPerWord;
	}
}


/*	This primitive is called from Squeak as...
		<imageSegment> storeSegmentFor: arrayOfRoots into: aWordArray outPointers: anArray. */
/*	This primitive will store a binary image segment (in the same format as the Squeak image file) of the receiver and every object in its proper tree of subParts (ie, that is not refered to from anywhere else outside the tree).  All pointers from within the tree to objects outside the tree will be copied into the array of outpointers.  In their place in the image segment will be an oop equal to the offset in the outPointer array (the first would be 4). but with the high bit set. */
/*	The primitive expects the array and wordArray to be more than adequately long.  In this case it returns normally, and truncates the two arrays to exactly the right size.  To simplify truncation, both incoming arrays are required to be 256 bytes or more long (ie with 3-word headers).  If either array is too small, the primitive will fail, but in no other case.

During operation of the primitive, it is necessary to convert from both internal and external oops to their mapped values.  To make this fast, the headers of the original objects in question are replaced by the mapped values (and this is noted by adding the forbidden XX header type).  Tables are kept of both kinds of oops, as well as of the original headers for restoration.

To be specific, there are two similar two-part tables, the outpointer array, and one in the upper fifth of the segmentWordArray.  Each grows oops from the bottom up, and preserved headers from halfway up.

In case of either success or failure, the headers must be restored.  In the event of primitive failure, the table of outpointers must also be nilled out (since the garbage in the high half will not have been discarded. */

sqInt primitiveStoreImageSegment(void) {
    usqInt hdrBaseOut;
    sqInt mapOop;
    usqInt segOop;
    sqInt versionOffset;
    usqInt savedYoungStart;
    sqInt hdrTypeBits;
    usqInt lastPtr;
    sqInt segmentWordArray;
    usqInt lastIn;
    usqInt firstIn;
    sqInt doingClass;
    sqInt header;
    sqInt fieldOop;
    usqInt fieldPtr;
    usqInt lastOut;
    usqInt hdrBaseIn;
    sqInt extraSize;
    usqInt lastSeg;
    sqInt outPointerArray;
    usqInt endSeg;
    usqInt firstOut;
    sqInt arrayOfRoots;
    sqInt i;
    sqInt lastAddr;
    sqInt i1;
    sqInt lastAddr1;
    sqInt i2;
    sqInt lastAddr2;
    sqInt i3;
    sqInt lastAddr3;
    sqInt in;
    sqInt lastIn1;
    sqInt out;
    sqInt in1;
    sqInt lastIn2;
    sqInt out1;
    sqInt sz;
    sqInt header1;

	outPointerArray = longAt(stackPointer);
	segmentWordArray = longAt(stackPointer - (1 * BytesPerWord));

	/* Essential type checks */

	arrayOfRoots = longAt(stackPointer - (2 * BytesPerWord));
	if (!((((((usqInt) (longAt(arrayOfRoots))) >> 8) & 15) == 2) && ((((((usqInt) (longAt(outPointerArray))) >> 8) & 15) == 2) && (((((usqInt) (longAt(segmentWordArray))) >> 8) & 15) == 6)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!((((longAt(outPointerArray)) & TypeMask) == HeaderTypeSizeAndClass) && (((longAt(segmentWordArray)) & TypeMask) == HeaderTypeSizeAndClass))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (DoAssertionChecks) {
		verifyCleanHeaders();
	}
	firstOut = outPointerArray + BaseHeaderSize;
	lastOut = firstOut - BytesPerWord;

	/* top half */

	hdrBaseOut = outPointerArray + (((lastPointerOf(outPointerArray)) / (BytesPerWord * 2)) * BytesPerWord);
	lastSeg = segmentWordArray;

	/* Write a version number for byte order and version check */

	endSeg = (segmentWordArray + (sizeBitsOf(segmentWordArray))) - BytesPerWord;
	versionOffset = BytesPerWord;
	lastSeg += versionOffset;
	if (lastSeg > endSeg) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	longAtput(lastSeg, imageSegmentVersion());

	/* Take 1/8 of seg */

	firstIn = endSeg - (((sizeBitsOf(segmentWordArray)) / (BytesPerWord * 8)) * BytesPerWord);
	lastIn = firstIn - BytesPerWord;

	/* top half of that */
	/* First mark the rootArray and all root objects. */

	hdrBaseIn = firstIn + (((sizeBitsOf(segmentWordArray)) / (BytesPerWord * 16)) * BytesPerWord);
	longAtput(arrayOfRoots, (longAt(arrayOfRoots)) | MarkBit);
	lastPtr = arrayOfRoots + (lastPointerOf(arrayOfRoots));
	fieldPtr = arrayOfRoots + BaseHeaderSize;
	while (fieldPtr <= lastPtr) {
		fieldOop = longAt(fieldPtr);
		if (!((fieldOop & 1))) {
			longAtput(fieldOop, (longAt(fieldOop)) | MarkBit);
		}
		fieldPtr += BytesPerWord;
	}
	savedYoungStart = youngStart;

	/* process all of memory */
	/* clear the recycled context lists */

	youngStart = memory;
	freeContexts = NilContext;
	freeLargeContexts = NilContext;
	markAndTraceInterpreterOops();

	/* Finally unmark the rootArray and all root objects. */

	youngStart = savedYoungStart;
	longAtput(arrayOfRoots, (longAt(arrayOfRoots)) & AllButMarkBit);
	fieldPtr = arrayOfRoots + BaseHeaderSize;
	while (fieldPtr <= lastPtr) {
		fieldOop = longAt(fieldPtr);
		if (!((fieldOop & 1))) {
			longAtput(fieldOop, (longAt(fieldOop)) & AllButMarkBit);
		}
		fieldPtr += BytesPerWord;
	}
	lastIn += BytesPerWord;
	if (lastIn >= hdrBaseIn) {
		successFlag = 0;
	}
	lastSeg = copyObjtoSegmentaddrstopAtsaveOopAtheaderAt(arrayOfRoots, segmentWordArray, lastSeg, firstIn, lastIn, hdrBaseIn + (lastIn - firstIn));
	if (!(successFlag)) {
		lastIn -= BytesPerWord;
		restoreHeadersFromtofromandtofrom(firstIn, lastIn, hdrBaseIn, firstOut, lastOut, hdrBaseOut);
		/* begin primitiveFailAfterCleanup: */
		lastAddr = outPointerArray + (lastPointerOf(outPointerArray));
		i = outPointerArray + BaseHeaderSize;
		while (i <= lastAddr) {
			longAtput(i, nilObj);
			i += BytesPerWord;
		}
		if (DoAssertionChecks) {
			verifyCleanHeaders();
		}
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	segOop = ((segmentWordArray + versionOffset) + BaseHeaderSize) + (headerTypeBytes[(longAt((segmentWordArray + versionOffset) + BaseHeaderSize)) & TypeMask]);
	while (segOop <= lastSeg) {
		if (((longAt(segOop)) & TypeMask) <= 1) {

			/* This object has a class field (type=0 or 1) -- start with that. */

			fieldPtr = segOop - BytesPerWord;
			doingClass = 1;
		} else {

			/* No class field -- start with first data field */

			fieldPtr = segOop + BaseHeaderSize;
			doingClass = 0;
		}

		/* last field */
		/* Go through all oops, remapping them... */

		lastPtr = segOop + (lastPointerOf(segOop));
		while (!(fieldPtr > lastPtr)) {

			/* Examine each pointer field */

			fieldOop = longAt(fieldPtr);
			if (doingClass) {
				hdrTypeBits = fieldOop & TypeMask;
				fieldOop -= hdrTypeBits;
			}
			if ((fieldOop & 1)) {

				/* Just an integer -- nothing to do */

				fieldPtr += BytesPerWord;
			} else {
				header = longAt(fieldOop);
				if ((header & TypeMask) == HeaderTypeFree) {

					/* Has already been forwarded -- this is the link */

					mapOop = header & AllButTypeMask;
				} else {
					if (((longAt(fieldOop)) & MarkBit) == 0) {

						/* Points to an unmarked obj -- an internal pointer.
							Copy the object into the segment, and forward its oop. */

						lastIn += BytesPerWord;
						if (lastIn >= hdrBaseIn) {
							successFlag = 0;
						}
						lastSeg = copyObjtoSegmentaddrstopAtsaveOopAtheaderAt(fieldOop, segmentWordArray, lastSeg, firstIn, lastIn, hdrBaseIn + (lastIn - firstIn));
						if (!(successFlag)) {

							/* Out of space in segment */

							lastIn -= BytesPerWord;
							restoreHeadersFromtofromandtofrom(firstIn, lastIn, hdrBaseIn, firstOut, lastOut, hdrBaseOut);
							/* begin primitiveFailAfterCleanup: */
							lastAddr1 = outPointerArray + (lastPointerOf(outPointerArray));
							i1 = outPointerArray + BaseHeaderSize;
							while (i1 <= lastAddr1) {
								longAtput(i1, nilObj);
								i1 += BytesPerWord;
							}
							if (DoAssertionChecks) {
								verifyCleanHeaders();
							}
							/* begin primitiveFail */
							successFlag = 0;
							return null;
						}
						mapOop = (longAt(fieldOop)) & AllButTypeMask;
					} else {

						/* Points to a marked obj -- an external pointer.
							Map it as a tagged index in outPointers, and forward its oop. */

						lastOut += BytesPerWord;
						if (lastOut >= hdrBaseOut) {

							/* Out of space in outPointerArray */

							lastOut -= BytesPerWord;
							restoreHeadersFromtofromandtofrom(firstIn, lastIn, hdrBaseIn, firstOut, lastOut, hdrBaseOut);
							/* begin primitiveFailAfterCleanup: */
							lastAddr2 = outPointerArray + (lastPointerOf(outPointerArray));
							i2 = outPointerArray + BaseHeaderSize;
							while (i2 <= lastAddr2) {
								longAtput(i2, nilObj);
								i2 += BytesPerWord;
							}
							if (DoAssertionChecks) {
								verifyCleanHeaders();
							}
							/* begin primitiveFail */
							successFlag = 0;
							return null;
						}
						mapOop = (lastOut - outPointerArray) | 2147483648U;
						/* begin forward:to:savingOopAt:andHeaderAt: */
						longAtput(lastOut, fieldOop);
						longAtput(hdrBaseOut + (lastOut - firstOut), longAt(fieldOop));
						longAtput(fieldOop, mapOop + HeaderTypeFree);
					}
				}
				if (doingClass) {
					longAtput(fieldPtr, mapOop + hdrTypeBits);
					fieldPtr += BytesPerWord * 2;
					doingClass = 0;
				} else {
					longAtput(fieldPtr, mapOop);
					fieldPtr += BytesPerWord;
				}
			}
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) segOop)) >= (((usqInt) endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(segOop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(segOop)) & AllButTypeMask;
		} else {
			/* begin sizeBitsOf: */
			header1 = longAt(segOop);
			if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(segOop - (BytesPerWord * 2))) & LongSizeMask;
				goto l1;
			} else {
				sz = header1 & SizeMask;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		segOop = (segOop + sz) + (headerTypeBytes[(longAt(segOop + sz)) & TypeMask]);
	}
	restoreHeadersFromtofromandtofrom(firstIn, lastIn, hdrBaseIn, firstOut, lastOut, hdrBaseOut);
	if ((((outPointerArray + (lastPointerOf(outPointerArray))) - lastOut) < 12) || ((endSeg - lastSeg) < 12)) {
		/* begin primitiveFailAfterCleanup: */
		lastAddr3 = outPointerArray + (lastPointerOf(outPointerArray));
		i3 = outPointerArray + BaseHeaderSize;
		while (i3 <= lastAddr3) {
			longAtput(i3, nilObj);
			i3 += BytesPerWord;
		}
		if (DoAssertionChecks) {
			verifyCleanHeaders();
		}
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	extraSize = headerTypeBytes[(longAt(segmentWordArray)) & TypeMask];

	/* Copy the 3-word wordArray header to establish a free chunk. */

	hdrTypeBits = (longAt(segmentWordArray)) & TypeMask;
	/* begin transfer:from:to: */
	flag("Dan");
	in = (segmentWordArray - extraSize) - BytesPerWord;
	lastIn1 = in + (3 * BytesPerWord);
	out = (lastOut + BytesPerWord) - BytesPerWord;
	while ((((usqInt) in)) < (((usqInt) lastIn1))) {
		longAtput(out += BytesPerWord, longAt(in += BytesPerWord));
	}
	longAtput(lastOut + BytesPerWord, (((outPointerArray + (lastPointerOf(outPointerArray))) - lastOut) - extraSize) + hdrTypeBits);
	longAtput(outPointerArray - extraSize, ((lastOut - firstOut) + (BytesPerWord * 2)) + hdrTypeBits);
	beRootIfOld(outPointerArray);
	/* begin transfer:from:to: */
	flag("Dan");
	in1 = (segmentWordArray - extraSize) - BytesPerWord;
	lastIn2 = in1 + (3 * BytesPerWord);
	out1 = (lastSeg + BytesPerWord) - BytesPerWord;
	while ((((usqInt) in1)) < (((usqInt) lastIn2))) {
		longAtput(out1 += BytesPerWord, longAt(in1 += BytesPerWord));
	}
	longAtput(segmentWordArray - extraSize, ((lastSeg - segmentWordArray) + BaseHeaderSize) + hdrTypeBits);
	longAtput(lastSeg + BytesPerWord, ((endSeg - lastSeg) - extraSize) + hdrTypeBits);
	if (DoAssertionChecks) {
		verifyCleanHeaders();
	}
	/* begin pop: */
	stackPointer -= 3 * BytesPerWord;
}


/*	Atomic store into context stackPointer. 
	Also ensures that any newly accessible cells are initialized to nil  */

sqInt primitiveStoreStackp(void) {
    sqInt stackp;
    sqInt i;
    sqInt newStackp;
    sqInt ctxt;
    sqInt integerPointer;
    sqInt valuePointer;
    sqInt sp;

	ctxt = longAt(stackPointer - (1 * BytesPerWord));
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		newStackp = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		newStackp = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	/* begin success: */
	successFlag = ((((usqInt) newStackp)) >= (((usqInt) 0))) && successFlag;
	/* begin success: */
	successFlag = ((((usqInt) newStackp)) <= (((usqInt) ((((sqInt) (LargeContextSize - BaseHeaderSize) >> 2)) - CtxtTempFrameStart)))) && successFlag;
	if (!(successFlag)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin fetchStackPointerOf: */
	sp = longAt((ctxt + BaseHeaderSize) + (StackPointerIndex << ShiftForWord));
	if (!((sp & 1))) {
		stackp = 0;
		goto l2;
	}
	stackp = (sp >> 1);
l2:	/* end fetchStackPointerOf: */;
	if ((((usqInt) newStackp)) > (((usqInt) stackp))) {
		for (i = (stackp + 1); i <= newStackp; i += 1) {
			/* begin storePointer:ofObject:withValue: */
			valuePointer = nilObj;
			if ((((usqInt) ctxt)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(ctxt, valuePointer);
			}
			longAtput((ctxt + BaseHeaderSize) + (((i + CtxtTempFrameStart) - 1) << ShiftForWord), valuePointer);
		}
	}
	/* begin storeStackPointerValue:inContext: */
	longAtput((ctxt + BaseHeaderSize) + (StackPointerIndex << ShiftForWord), ((newStackp << 1) | 1));
	/* begin pop: */
	stackPointer -= 1 * BytesPerWord;
}

sqInt primitiveStringAt(void) {
	commonAt(1);
}

sqInt primitiveStringAtPut(void) {
	commonAtPut(1);
}


/*	 
	<array> primReplaceFrom: start to: stop with: replacement 
	startingAt: repStart  
	<primitive: 105>
	 */

sqInt primitiveStringReplace(void) {
    sqInt stop;
    sqInt start;
    sqInt totalLength;
    sqInt srcIndex;
    sqInt i;
    sqInt arrayInstSize;
    sqInt replInstSize;
    sqInt hdr;
    sqInt replFmt;
    sqInt array;
    sqInt replStart;
    sqInt repl;
    sqInt arrayFmt;
    sqInt valueWord;
    sqInt integerPointer;
    sqInt integerPointer1;
    sqInt integerPointer2;
    sqInt sz;
    sqInt classFormat;
    sqInt class;
    sqInt sz1;
    sqInt classFormat1;
    sqInt class1;
    sqInt ccIndex;
    sqInt ccIndex1;

	array = longAt(stackPointer - (4 * BytesPerWord));
	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (3 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		start = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		start = 0;
		goto l1;
	}
	start = null;
l1:	/* end stackIntegerValue: */;
	/* begin stackIntegerValue: */
	integerPointer1 = longAt(stackPointer - (2 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer1 & 1)) {
		stop = (integerPointer1 >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		stop = 0;
		goto l2;
	}
	stop = null;
l2:	/* end stackIntegerValue: */;
	repl = longAt(stackPointer - (1 * BytesPerWord));
	/* begin stackIntegerValue: */
	integerPointer2 = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer2 & 1)) {
		replStart = (integerPointer2 >> 1);
		goto l3;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		replStart = 0;
		goto l3;
	}
	replStart = null;
l3:	/* end stackIntegerValue: */;
	if (!(successFlag)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if ((repl & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	hdr = longAt(array);
	arrayFmt = (((usqInt) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(array - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz = hdr & SizeMask;
	}
	sz -= hdr & Size4Bit;
	if (arrayFmt <= 4) {
		totalLength = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
		goto l4;
	}
	if (arrayFmt < 8) {
		totalLength = ((usqInt) (sz - BaseHeaderSize)) >> 2;
		goto l4;
	} else {
		totalLength = (sz - BaseHeaderSize) - (arrayFmt & 3);
		goto l4;
	}
l4:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((arrayFmt > 4) || (arrayFmt == 2)) {
		arrayInstSize = 0;
		goto l5;
	}
	if (arrayFmt < 2) {
		arrayInstSize = totalLength;
		goto l5;
	}
	/* begin fetchClassOf: */
	if ((array & 1)) {
		class = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l8;
	}
	ccIndex = (((usqInt) (longAt(array))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(array - BaseHeaderSize)) & AllButTypeMask;
		goto l8;
	} else {
		class = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l8;
	}
l8:	/* end fetchClassOf: */;
	classFormat = (longAt((class + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1;
	arrayInstSize = (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
l5:	/* end fixedFieldsOf:format:length: */;
	if (!((start >= 1) && (((start - 1) <= stop) && ((stop + arrayInstSize) <= totalLength)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	hdr = longAt(repl);
	replFmt = (((usqInt) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(repl - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz1 = hdr & SizeMask;
	}
	sz1 -= hdr & Size4Bit;
	if (replFmt <= 4) {
		totalLength = ((usqInt) (sz1 - BaseHeaderSize)) >> ShiftForWord;
		goto l6;
	}
	if (replFmt < 8) {
		totalLength = ((usqInt) (sz1 - BaseHeaderSize)) >> 2;
		goto l6;
	} else {
		totalLength = (sz1 - BaseHeaderSize) - (replFmt & 3);
		goto l6;
	}
l6:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((replFmt > 4) || (replFmt == 2)) {
		replInstSize = 0;
		goto l7;
	}
	if (replFmt < 2) {
		replInstSize = totalLength;
		goto l7;
	}
	/* begin fetchClassOf: */
	if ((repl & 1)) {
		class1 = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l9;
	}
	ccIndex1 = (((usqInt) (longAt(repl))) >> 12) & 31;
	if (ccIndex1 == 0) {
		class1 = (longAt(repl - BaseHeaderSize)) & AllButTypeMask;
		goto l9;
	} else {
		class1 = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex1 - 1) << ShiftForWord));
		goto l9;
	}
l9:	/* end fetchClassOf: */;
	classFormat1 = (longAt((class1 + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1;
	replInstSize = (((((usqInt) classFormat1) >> 11) & 192) + ((((usqInt) classFormat1) >> 2) & 63)) - 1;
l7:	/* end fixedFieldsOf:format:length: */;
	if (!((replStart >= 1) && ((((stop - start) + replStart) + replInstSize) <= totalLength))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (arrayFmt < 8) {
		if (!(arrayFmt == replFmt)) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	} else {
		if (!((arrayFmt & 12) == (replFmt & 12))) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}

	/* - 1 for 0-based access */

	srcIndex = (replStart + replInstSize) - 1;
	if (arrayFmt <= 4) {
		for (i = ((start + arrayInstSize) - 1); i <= ((stop + arrayInstSize) - 1); i += 1) {
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) array)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(array, longAt((repl + BaseHeaderSize) + (srcIndex << ShiftForWord)));
			}
			longAtput((array + BaseHeaderSize) + (i << ShiftForWord), longAt((repl + BaseHeaderSize) + (srcIndex << ShiftForWord)));
			srcIndex += 1;
		}
	} else {
		if (arrayFmt < 8) {
			for (i = ((start + arrayInstSize) - 1); i <= ((stop + arrayInstSize) - 1); i += 1) {
				/* begin storeLong32:ofObject:withValue: */
				valueWord = long32At((repl + BaseHeaderSize) + (srcIndex << 2));
				long32Atput((array + BaseHeaderSize) + (i << 2), valueWord);
				srcIndex += 1;
			}
		} else {
			for (i = ((start + arrayInstSize) - 1); i <= ((stop + arrayInstSize) - 1); i += 1) {
				byteAtput((array + BaseHeaderSize) + i, byteAt((repl + BaseHeaderSize) + srcIndex));
				srcIndex += 1;
			}
		}
	}
	/* begin pop: */
	stackPointer -= argumentCount * BytesPerWord;
}

sqInt primitiveSubtract(void) {
    sqInt integerResult;
    sqInt sp;

	/* begin pop2AndPushIntegerIfOK: */
	integerResult = (stackIntegerValue(1)) - (stackIntegerValue(0));
	if (successFlag) {
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) integerResult)) ^ ((((int) integerResult)) << 1)) >= 0)
# else
			((integerResult >= -1073741824) && (integerResult <= 1073741823))
# endif  // SQ_HOST32
		) {
			/* begin pop:thenPush: */
			longAtput(sp = stackPointer - ((2 - 1) * BytesPerWord), ((integerResult << 1) | 1));
			stackPointer = sp;
		} else {
			successFlag = 0;
		}
	}
}

sqInt primitiveSuspend(void) {
    sqInt activeProc;
    sqInt sp;

	activeProc = longAt(((longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord))) + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
	/* begin success: */
	successFlag = ((longAt(stackPointer)) == activeProc) && successFlag;
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 1 * BytesPerWord;
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, nilObj);
		stackPointer = sp;
		transferTo(wakeHighestPriority());
	}
}


/*	Primitive. Terminate up the context stack from the receiver up to but not including the argument, if previousContext is on my Context stack. Make previousContext my sender. This prim has to shadow the code in ContextPart>terminateTo: to be correct */

sqInt primitiveTerminateTo(void) {
    sqInt nilOop;
    sqInt thisCntx;
    sqInt aContext;
    sqInt nextCntx;
    sqInt currentCntx;
    sqInt top;
    sqInt top1;
    sqInt sp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	aContext = top;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	thisCntx = top1;
	if (contexthasSender(thisCntx, aContext)) {
		nilOop = nilObj;
		currentCntx = longAt((thisCntx + BaseHeaderSize) + (SenderIndex << ShiftForWord));
		while (!(currentCntx == aContext)) {
			nextCntx = longAt((currentCntx + BaseHeaderSize) + (SenderIndex << ShiftForWord));
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) currentCntx)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(currentCntx, nilOop);
			}
			longAtput((currentCntx + BaseHeaderSize) + (SenderIndex << ShiftForWord), nilOop);
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) currentCntx)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(currentCntx, nilOop);
			}
			longAtput((currentCntx + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord), nilOop);
			currentCntx = nextCntx;
		}
	}
	/* begin storePointer:ofObject:withValue: */
	if ((((usqInt) thisCntx)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(thisCntx, aContext);
	}
	longAtput((thisCntx + BaseHeaderSize) + (SenderIndex << ShiftForWord), aContext);
	/* begin push: */
	longAtput(sp = stackPointer + BytesPerWord, thisCntx);
	stackPointer = sp;
	return null;
}


/*	Return true if the host OS does support the given display depth. */

sqInt primitiveTestDisplayDepth(void) {
    sqInt okay;
    sqInt bitsPerPixel;
    sqInt sp;
    sqInt sp1;
    sqInt integerPointer;

	/* begin stackIntegerValue: */
	integerPointer = longAt(stackPointer - (0 * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		bitsPerPixel = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		bitsPerPixel = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	if (successFlag) {
		okay = ioHasDisplayDepth(bitsPerPixel);
	}
	if (successFlag) {
		/* begin pop: */
		stackPointer -= 2 * BytesPerWord;
		/* begin pushBool: */
		if (okay) {
			/* begin push: */
			longAtput(sp = stackPointer + BytesPerWord, trueObj);
			stackPointer = sp;
		} else {
			/* begin push: */
			longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
			stackPointer = sp1;
		}
	}
}

sqInt primitiveTimesTwoPower(void) {
    sqInt arg;
    double  rcvr;
    sqInt integerPointer;
    sqInt top;

	/* begin popInteger */
	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	integerPointer = top;
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		arg = (integerPointer >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		arg = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	rcvr = popFloat();
	if (successFlag) {
		pushFloat(ldexp(rcvr, arg));
	} else {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
	}
}

sqInt primitiveTruncated(void) {
    double  trunc;
    double  frac;
    double  rcvr;
    sqInt successValue;
    sqInt sp;

	rcvr = popFloat();
	if (successFlag) {
		frac = modf(rcvr, &trunc);
		flag("Dan");
		success((-1073741824.0 <= trunc) && (trunc <= 1073741823.0));
	}
	if (successFlag) {
		pushInteger((sqInt) trunc);
	} else {
		/* begin unPop: */
		stackPointer += 1 * BytesPerWord;
	}
}


/*	Primitive. Unload the module with the given name. */
/*	Reloading of the module will happen *later* automatically, when a 
	function from it is called. This is ensured by invalidating current sessionID. */

sqInt primitiveUnloadModule(void) {
    sqInt moduleName;

	if (!(argumentCount == 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	moduleName = longAt(stackPointer);
	if ((moduleName & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(((moduleName & 1) == 0) && (((((usqInt) (longAt(moduleName))) >> 8) & 15) >= 8))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (!(ioUnloadModuleOfLength(oopForPointer(firstIndexableField(moduleName)), byteSizeOf(moduleName)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	flushExternalPrimitives();
	/* begin forceInterruptCheck */
	interruptCheckCounter = -1000;
	nextPollTick = 0;
	/* begin pop: */
	stackPointer -= 1 * BytesPerWord;
}


/*	Behaviour depends on argument count:
		0 args:	return an Array of VM parameter values;
		1 arg:	return the indicated VM parameter;
		2 args:	set the VM indicated parameter.
	VM parameters are numbered as follows:
		1	end of old-space (0-based, read-only)
		2	end of young-space (read-only)
		3	end of memory (read-only)
		4	allocationCount (read-only)
		5	allocations between GCs (read-write)
		6	survivor count tenuring threshold (read-write)
		7	full GCs since startup (read-only)
		8	total milliseconds in full GCs since startup (read-only)
		9	incremental GCs since startup (read-only)
		10	total milliseconds in incremental GCs since startup (read-only)
		11	tenures of surving objects since startup (read-only)
		12-20 specific to the translating VM
		21	root table size (read-only)
		22	root table overflows since startup (read-only)
		23	bytes of extra memory to reserve for VM buffers, plugins, etc.
		24	memory threshold above which shrinking object memory (rw)
		25	memory headroom when growing object memory (rw)
		26  interruptChecksEveryNms - force an ioProcessEvents every N milliseconds, in case the image  is not calling getNextEvent often (rw)
		27	number of times mark loop iterated for current IGC/FGC (read-only) includes ALL marking
		28	number of times sweep loop iterated  for current IGC/FGC (read-only)
		29	number of times make forward loop iterated for current IGC/FGC (read-only)
		30	number of times compact move loop iterated for current IGC/FGC (read-only)
		31	number of grow memory requests (read-only)
		32	number of shrink memory requests (read-only)
		33	number of root table entries used for current IGC/FGC (read-only)
		34	number of allocations done before current IGC/FGC (read-only)
		35	number of survivor objects after current IGC/FGC (read-only)
		36  millisecond clock when current IGC/FGC completed (read-only)
		37  number of marked objects for Roots of the world, not including Root Table entries for current IGC/FGC (read-only)
		38  milliseconds taken by current IGC  (read-only)
		39  Number of finalization signals for Weak Objects pending when current IGC/FGC completed (read-only)
		40 BytesPerWord for this image
		
	Note: Thanks to Ian Piumarta for this primitive. */

sqInt primitiveVMParameter(void) {
    sqInt mem;
    sqInt arg;
    sqInt result;
    sqInt i;
    sqInt paramsArraySize;
    sqInt index;
    sqInt valuePointer;
    sqInt valuePointer1;
    sqInt valuePointer2;
    sqInt valuePointer3;
    sqInt valuePointer4;
    sqInt valuePointer5;
    sqInt valuePointer6;
    sqInt valuePointer7;
    sqInt valuePointer8;
    sqInt valuePointer9;
    sqInt valuePointer10;
    sqInt valuePointer11;
    sqInt valuePointer12;
    sqInt valuePointer13;
    sqInt valuePointer14;
    sqInt valuePointer15;
    sqInt valuePointer16;
    sqInt valuePointer17;
    sqInt valuePointer18;
    sqInt valuePointer19;
    sqInt valuePointer20;
    sqInt valuePointer21;
    sqInt valuePointer22;
    sqInt valuePointer23;
    sqInt valuePointer24;
    sqInt valuePointer25;
    sqInt valuePointer26;
    sqInt valuePointer27;
    sqInt valuePointer28;
    sqInt valuePointer29;
    sqInt sp;
    sqInt sp1;
    sqInt sp2;

	mem = memory;
	paramsArraySize = 40;
	if (argumentCount == 0) {
		result = instantiateClassindexableSize(longAt((specialObjectsOop + BaseHeaderSize) + (ClassArray << ShiftForWord)), paramsArraySize);
		for (i = 0; i <= (paramsArraySize - 1); i += 1) {
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) result)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(result, ConstZero);
			}
			longAtput((result + BaseHeaderSize) + (i << ShiftForWord), ConstZero);
		}
		/* begin storePointer:ofObject:withValue: */
		valuePointer = (((youngStart - mem) << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer);
		}
		longAtput((result + BaseHeaderSize) + (0 << ShiftForWord), valuePointer);
		/* begin storePointer:ofObject:withValue: */
		valuePointer1 = (((freeBlock - mem) << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer1);
		}
		longAtput((result + BaseHeaderSize) + (1 << ShiftForWord), valuePointer1);
		/* begin storePointer:ofObject:withValue: */
		valuePointer2 = (((endOfMemory - mem) << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer2);
		}
		longAtput((result + BaseHeaderSize) + (2 << ShiftForWord), valuePointer2);
		/* begin storePointer:ofObject:withValue: */
		valuePointer3 = ((allocationCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer3);
		}
		longAtput((result + BaseHeaderSize) + (3 << ShiftForWord), valuePointer3);
		/* begin storePointer:ofObject:withValue: */
		valuePointer4 = ((allocationsBetweenGCs << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer4);
		}
		longAtput((result + BaseHeaderSize) + (4 << ShiftForWord), valuePointer4);
		/* begin storePointer:ofObject:withValue: */
		valuePointer5 = ((tenuringThreshold << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer5);
		}
		longAtput((result + BaseHeaderSize) + (5 << ShiftForWord), valuePointer5);
		/* begin storePointer:ofObject:withValue: */
		valuePointer6 = ((statFullGCs << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer6);
		}
		longAtput((result + BaseHeaderSize) + (6 << ShiftForWord), valuePointer6);
		/* begin storePointer:ofObject:withValue: */
		valuePointer7 = ((statFullGCMSecs << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer7);
		}
		longAtput((result + BaseHeaderSize) + (7 << ShiftForWord), valuePointer7);
		/* begin storePointer:ofObject:withValue: */
		valuePointer8 = ((statIncrGCs << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer8);
		}
		longAtput((result + BaseHeaderSize) + (8 << ShiftForWord), valuePointer8);
		/* begin storePointer:ofObject:withValue: */
		valuePointer9 = ((statIncrGCMSecs << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer9);
		}
		longAtput((result + BaseHeaderSize) + (9 << ShiftForWord), valuePointer9);
		/* begin storePointer:ofObject:withValue: */
		valuePointer10 = ((statTenures << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer10);
		}
		longAtput((result + BaseHeaderSize) + (10 << ShiftForWord), valuePointer10);
		/* begin storePointer:ofObject:withValue: */
		valuePointer11 = ((rootTableCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer11);
		}
		longAtput((result + BaseHeaderSize) + (20 << ShiftForWord), valuePointer11);
		/* begin storePointer:ofObject:withValue: */
		valuePointer12 = ((statRootTableOverflows << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer12);
		}
		longAtput((result + BaseHeaderSize) + (21 << ShiftForWord), valuePointer12);
		/* begin storePointer:ofObject:withValue: */
		valuePointer13 = ((extraVMMemory << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer13);
		}
		longAtput((result + BaseHeaderSize) + (22 << ShiftForWord), valuePointer13);
		/* begin storePointer:ofObject:withValue: */
		valuePointer14 = ((shrinkThreshold << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer14);
		}
		longAtput((result + BaseHeaderSize) + (23 << ShiftForWord), valuePointer14);
		/* begin storePointer:ofObject:withValue: */
		valuePointer15 = ((growHeadroom << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer15);
		}
		longAtput((result + BaseHeaderSize) + (24 << ShiftForWord), valuePointer15);
		/* begin storePointer:ofObject:withValue: */
		valuePointer16 = ((interruptChecksEveryNms << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer16);
		}
		longAtput((result + BaseHeaderSize) + (25 << ShiftForWord), valuePointer16);
		/* begin storePointer:ofObject:withValue: */
		valuePointer17 = ((statMarkCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer17);
		}
		longAtput((result + BaseHeaderSize) + (26 << ShiftForWord), valuePointer17);
		/* begin storePointer:ofObject:withValue: */
		valuePointer18 = ((statSweepCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer18);
		}
		longAtput((result + BaseHeaderSize) + (27 << ShiftForWord), valuePointer18);
		/* begin storePointer:ofObject:withValue: */
		valuePointer19 = ((statMkFwdCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer19);
		}
		longAtput((result + BaseHeaderSize) + (28 << ShiftForWord), valuePointer19);
		/* begin storePointer:ofObject:withValue: */
		valuePointer20 = ((statCompMoveCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer20);
		}
		longAtput((result + BaseHeaderSize) + (29 << ShiftForWord), valuePointer20);
		/* begin storePointer:ofObject:withValue: */
		valuePointer21 = ((statGrowMemory << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer21);
		}
		longAtput((result + BaseHeaderSize) + (30 << ShiftForWord), valuePointer21);
		/* begin storePointer:ofObject:withValue: */
		valuePointer22 = ((statShrinkMemory << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer22);
		}
		longAtput((result + BaseHeaderSize) + (31 << ShiftForWord), valuePointer22);
		/* begin storePointer:ofObject:withValue: */
		valuePointer23 = ((statRootTableCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer23);
		}
		longAtput((result + BaseHeaderSize) + (32 << ShiftForWord), valuePointer23);
		/* begin storePointer:ofObject:withValue: */
		valuePointer24 = ((statAllocationCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer24);
		}
		longAtput((result + BaseHeaderSize) + (33 << ShiftForWord), valuePointer24);
		/* begin storePointer:ofObject:withValue: */
		valuePointer25 = ((statSurvivorCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer25);
		}
		longAtput((result + BaseHeaderSize) + (34 << ShiftForWord), valuePointer25);
		/* begin storePointer:ofObject:withValue: */
		valuePointer26 = ((statGCTime << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer26);
		}
		longAtput((result + BaseHeaderSize) + (35 << ShiftForWord), valuePointer26);
		/* begin storePointer:ofObject:withValue: */
		valuePointer27 = ((statSpecialMarkCount << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer27);
		}
		longAtput((result + BaseHeaderSize) + (36 << ShiftForWord), valuePointer27);
		/* begin storePointer:ofObject:withValue: */
		valuePointer28 = ((statIGCDeltaTime << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer28);
		}
		longAtput((result + BaseHeaderSize) + (37 << ShiftForWord), valuePointer28);
		/* begin storePointer:ofObject:withValue: */
		valuePointer29 = ((statpendingFinalizationSignals << 1) | 1);
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, valuePointer29);
		}
		longAtput((result + BaseHeaderSize) + (38 << ShiftForWord), valuePointer29);
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) result)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(result, ((BytesPerWord << 1) | 1));
		}
		longAtput((result + BaseHeaderSize) + (39 << ShiftForWord), ((BytesPerWord << 1) | 1));
		/* begin pop:thenPush: */
		longAtput(sp = stackPointer - ((1 - 1) * BytesPerWord), result);
		stackPointer = sp;
		return null;
	}
	arg = longAt(stackPointer);
	if (!((arg & 1))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	arg = (arg >> 1);
	if (argumentCount == 1) {
		if ((arg < 1) || (arg > paramsArraySize)) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
		if (arg == 1) {
			result = youngStart - mem;
		}
		if (arg == 2) {
			result = freeBlock - mem;
		}
		if (arg == 3) {
			result = endOfMemory - mem;
		}
		if (arg == 4) {
			result = allocationCount;
		}
		if (arg == 5) {
			result = allocationsBetweenGCs;
		}
		if (arg == 6) {
			result = tenuringThreshold;
		}
		if (arg == 7) {
			result = statFullGCs;
		}
		if (arg == 8) {
			result = statFullGCMSecs;
		}
		if (arg == 9) {
			result = statIncrGCs;
		}
		if (arg == 10) {
			result = statIncrGCMSecs;
		}
		if (arg == 11) {
			result = statTenures;
		}
		if ((arg >= 12) && (arg <= 20)) {
			result = 0;
		}
		if (arg == 21) {
			result = rootTableCount;
		}
		if (arg == 22) {
			result = statRootTableOverflows;
		}
		if (arg == 23) {
			result = extraVMMemory;
		}
		if (arg == 24) {
			result = shrinkThreshold;
		}
		if (arg == 25) {
			result = growHeadroom;
		}
		if (arg == 26) {
			result = interruptChecksEveryNms;
		}
		if (arg == 27) {
			result = statMarkCount;
		}
		if (arg == 28) {
			result = statSweepCount;
		}
		if (arg == 29) {
			result = statMkFwdCount;
		}
		if (arg == 30) {
			result = statCompMoveCount;
		}
		if (arg == 31) {
			result = statGrowMemory;
		}
		if (arg == 32) {
			result = statShrinkMemory;
		}
		if (arg == 33) {
			result = statRootTableCount;
		}
		if (arg == 34) {
			result = statAllocationCount;
		}
		if (arg == 35) {
			result = statSurvivorCount;
		}
		if (arg == 36) {
			result = statGCTime;
		}
		if (arg == 37) {
			result = statSpecialMarkCount;
		}
		if (arg == 38) {
			result = statIGCDeltaTime;
		}
		if (arg == 39) {
			result = statpendingFinalizationSignals;
		}
		if (arg == 40) {
			result = BytesPerWord;
		}
		/* begin pop:thenPush: */
		longAtput(sp1 = stackPointer - ((2 - 1) * BytesPerWord), ((result << 1) | 1));
		stackPointer = sp1;
		return null;
	}
	if (!(argumentCount == 2)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	index = longAt(stackPointer - (1 * BytesPerWord));
	if (!((index & 1))) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	index = (index >> 1);
	if (index <= 0) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	successFlag = 0;
	if (index == 5) {
		result = allocationsBetweenGCs;
		allocationsBetweenGCs = arg;
		successFlag = 1;
	}
	if (index == 6) {
		result = tenuringThreshold;
		tenuringThreshold = arg;
		successFlag = 1;
	}
	if (index == 23) {
		result = extraVMMemory;
		extraVMMemory = arg;
		successFlag = 1;
	}
	if (index == 24) {
		result = shrinkThreshold;
		if (arg > 0) {
			shrinkThreshold = arg;
			successFlag = 1;
		}
	}
	if (index == 25) {
		result = growHeadroom;
		if (arg > 0) {
			growHeadroom = arg;
			successFlag = 1;
		}
	}
	if (index == 26) {
		if (arg > 1) {
			result = interruptChecksEveryNms;
			interruptChecksEveryNms = arg;
			successFlag = 1;
		}
	}
	if (successFlag) {
		/* begin pop:thenPush: */
		longAtput(sp2 = stackPointer - ((3 - 1) * BytesPerWord), ((result << 1) | 1));
		stackPointer = sp2;
		return null;
	}
	/* begin primitiveFail */
	successFlag = 0;
}


/*	Return a string containing the path name of VM's directory. */

sqInt primitiveVMPath(void) {
    sqInt sz;
    sqInt s;
    sqInt sp;

	sz = vmPathSize();
	s = instantiateClassindexableSize(longAt((specialObjectsOop + BaseHeaderSize) + (ClassString << ShiftForWord)), sz);
	vmPathGetLength(s + BaseHeaderSize, sz);
	/* begin pop:thenPush: */
	longAtput(sp = stackPointer - ((1 - 1) * BytesPerWord), s);
	stackPointer = sp;
}

sqInt primitiveValue(void) {
    sqInt blockContext;
    sqInt blockArgumentCount;
    sqInt initialIP;
    sqInt successValue;
    sqInt count;
    sqInt firstFrom;
    sqInt fromOop;
    sqInt fromIndex;
    sqInt lastFrom;
    sqInt toIndex;
    sqInt localArgCount;
    sqInt tmp;

	blockContext = longAt(stackPointer - (argumentCount * BytesPerWord));
	/* begin argumentCountOfBlock: */
	localArgCount = longAt((blockContext + BaseHeaderSize) + (BlockArgumentCountIndex << ShiftForWord));
	/* begin checkedIntegerValueOf: */
	if ((localArgCount & 1)) {
		blockArgumentCount = (localArgCount >> 1);
		goto l1;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		blockArgumentCount = 0;
		goto l1;
	}
l1:	/* end checkedIntegerValueOf: */;
	/* begin success: */
	successValue = (argumentCount == blockArgumentCount) && ((longAt((blockContext + BaseHeaderSize) + (CallerIndex << ShiftForWord))) == nilObj);
	successFlag = successValue && successFlag;
	if (successFlag) {
		/* begin transfer:fromIndex:ofObject:toIndex:ofObject: */
		count = argumentCount;
		firstFrom = ((((usqInt) ((stackPointer - activeContext) - BaseHeaderSize)) >> ShiftForWord) - argumentCount) + 1;
		fromOop = activeContext;
		flag("Dan");
		fromIndex = fromOop + (firstFrom * BytesPerWord);
		toIndex = blockContext + (TempFrameStart * BytesPerWord);
		lastFrom = fromIndex + (count * BytesPerWord);
		while ((((usqInt) fromIndex)) < (((usqInt) lastFrom))) {
			fromIndex += BytesPerWord;
			toIndex += BytesPerWord;
			longAtput(toIndex, longAt(fromIndex));
		}
		/* begin pop: */
		stackPointer -= (argumentCount + 1) * BytesPerWord;
		initialIP = longAt((blockContext + BaseHeaderSize) + (InitialIPIndex << ShiftForWord));
		longAtput((blockContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord), initialIP);
		/* begin storeStackPointerValue:inContext: */
		longAtput((blockContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord), ((argumentCount << 1) | 1));
		longAtput((blockContext + BaseHeaderSize) + (CallerIndex << ShiftForWord), activeContext);
		/* begin newActiveContext: */
		/* begin storeContextRegisters: */
		longAtput((activeContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord), ((((instructionPointer - method) - (BaseHeaderSize - 2)) << 1) | 1));
		longAtput((activeContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord), (((((((usqInt) ((stackPointer - activeContext) - BaseHeaderSize)) >> ShiftForWord) - TempFrameStart) + 1) << 1) | 1));
		if ((((usqInt) blockContext)) < (((usqInt) youngStart))) {
			beRootIfOld(blockContext);
		}
		activeContext = blockContext;
		/* begin fetchContextRegisters: */
		tmp = longAt((blockContext + BaseHeaderSize) + (MethodIndex << ShiftForWord));
		if ((tmp & 1)) {
			tmp = longAt((blockContext + BaseHeaderSize) + (HomeIndex << ShiftForWord));
			if ((((usqInt) tmp)) < (((usqInt) youngStart))) {
				beRootIfOld(tmp);
			}
		} else {
			tmp = blockContext;
		}
		theHomeContext = tmp;
		receiver = longAt((tmp + BaseHeaderSize) + (ReceiverIndex << ShiftForWord));
		method = longAt((tmp + BaseHeaderSize) + (MethodIndex << ShiftForWord));
		tmp = ((longAt((blockContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord))) >> 1);
		instructionPointer = ((method + tmp) + BaseHeaderSize) - 2;
		tmp = ((longAt((blockContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord))) >> 1);
		stackPointer = (blockContext + BaseHeaderSize) + (((TempFrameStart + tmp) - 1) * BytesPerWord);
	}
}


/*	The only purpose of this primitive is to indicate that the new EH mechanisms are supported. */

sqInt primitiveValueUninterruptably(void) {
	return primitiveValue();
}

sqInt primitiveValueWithArgs(void) {
    sqInt arrayArgumentCount;
    sqInt blockContext;
    sqInt blockArgumentCount;
    sqInt initialIP;
    sqInt argumentArray;
    sqInt sz;
    sqInt header;
    sqInt successValue;
    sqInt fromIndex;
    sqInt lastFrom;
    sqInt toIndex;
    sqInt top;
    sqInt top1;
    sqInt localArgCount;
    sqInt tmp;

	/* begin popStack */
	top = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	argumentArray = top;
	/* begin popStack */
	top1 = longAt(stackPointer);
	stackPointer -= BytesPerWord;
	blockContext = top1;
	/* begin argumentCountOfBlock: */
	localArgCount = longAt((blockContext + BaseHeaderSize) + (BlockArgumentCountIndex << ShiftForWord));
	/* begin checkedIntegerValueOf: */
	if ((localArgCount & 1)) {
		blockArgumentCount = (localArgCount >> 1);
		goto l2;
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		blockArgumentCount = 0;
		goto l2;
	}
l2:	/* end checkedIntegerValueOf: */;
	if (!(((argumentArray & 1) == 0) && (((((usqInt) (longAt(argumentArray))) >> 8) & 15) == 2))) {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	if (successFlag) {
		/* begin fetchWordLengthOf: */
		/* begin sizeBitsOf: */
		header = longAt(argumentArray);
		if ((header & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(argumentArray - (BytesPerWord * 2))) & LongSizeMask;
			goto l1;
		} else {
			sz = header & SizeMask;
			goto l1;
		}
	l1:	/* end sizeBitsOf: */;
		arrayArgumentCount = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
		/* begin success: */
		successValue = (arrayArgumentCount == blockArgumentCount) && ((longAt((blockContext + BaseHeaderSize) + (CallerIndex << ShiftForWord))) == nilObj);
		successFlag = successValue && successFlag;
	}
	if (successFlag) {
		/* begin transfer:fromIndex:ofObject:toIndex:ofObject: */
		flag("Dan");
		fromIndex = argumentArray + (0 * BytesPerWord);
		toIndex = blockContext + (TempFrameStart * BytesPerWord);
		lastFrom = fromIndex + (arrayArgumentCount * BytesPerWord);
		while ((((usqInt) fromIndex)) < (((usqInt) lastFrom))) {
			fromIndex += BytesPerWord;
			toIndex += BytesPerWord;
			longAtput(toIndex, longAt(fromIndex));
		}
		initialIP = longAt((blockContext + BaseHeaderSize) + (InitialIPIndex << ShiftForWord));
		longAtput((blockContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord), initialIP);
		/* begin storeStackPointerValue:inContext: */
		longAtput((blockContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord), ((arrayArgumentCount << 1) | 1));
		longAtput((blockContext + BaseHeaderSize) + (CallerIndex << ShiftForWord), activeContext);
		/* begin newActiveContext: */
		/* begin storeContextRegisters: */
		longAtput((activeContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord), ((((instructionPointer - method) - (BaseHeaderSize - 2)) << 1) | 1));
		longAtput((activeContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord), (((((((usqInt) ((stackPointer - activeContext) - BaseHeaderSize)) >> ShiftForWord) - TempFrameStart) + 1) << 1) | 1));
		if ((((usqInt) blockContext)) < (((usqInt) youngStart))) {
			beRootIfOld(blockContext);
		}
		activeContext = blockContext;
		/* begin fetchContextRegisters: */
		tmp = longAt((blockContext + BaseHeaderSize) + (MethodIndex << ShiftForWord));
		if ((tmp & 1)) {
			tmp = longAt((blockContext + BaseHeaderSize) + (HomeIndex << ShiftForWord));
			if ((((usqInt) tmp)) < (((usqInt) youngStart))) {
				beRootIfOld(tmp);
			}
		} else {
			tmp = blockContext;
		}
		theHomeContext = tmp;
		receiver = longAt((tmp + BaseHeaderSize) + (ReceiverIndex << ShiftForWord));
		method = longAt((tmp + BaseHeaderSize) + (MethodIndex << ShiftForWord));
		tmp = ((longAt((blockContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord))) >> 1);
		instructionPointer = ((method + tmp) + BaseHeaderSize) - 2;
		tmp = ((longAt((blockContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord))) >> 1);
		stackPointer = (blockContext + BaseHeaderSize) + (((TempFrameStart + tmp) - 1) * BytesPerWord);
	} else {
		/* begin unPop: */
		stackPointer += 2 * BytesPerWord;
	}
}

sqInt primitiveWait(void) {
    sqInt activeProc;
    sqInt excessSignals;
    sqInt sema;
    sqInt lastLink;
    sqInt cl;
    sqInt ccIndex;


	/* rcvr */

	sema = longAt(stackPointer);
	/* begin assertClassOf:is: */
	if ((sema & 1)) {
		successFlag = 0;
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(sema))) >> 12) & 31;
	if (ccIndex == 0) {
		cl = (longAt(sema - BaseHeaderSize)) & AllButTypeMask;
	} else {
		cl = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
	}
	/* begin success: */
	successFlag = (cl == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassSemaphore << ShiftForWord)))) && successFlag;
l1:	/* end assertClassOf:is: */;
	if (successFlag) {
		excessSignals = fetchIntegerofObject(ExcessSignalsIndex, sema);
		if (excessSignals > 0) {
			/* begin storeInteger:ofObject:withValue: */
			if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
				(((((int) (excessSignals - 1))) ^ ((((int) (excessSignals - 1))) << 1)) >= 0)
# else
				(((excessSignals - 1) >= -1073741824) && ((excessSignals - 1) <= 1073741823))
# endif  // SQ_HOST32
			) {
				longAtput((sema + BaseHeaderSize) + (ExcessSignalsIndex << ShiftForWord), (((excessSignals - 1) << 1) | 1));
			} else {
				/* begin primitiveFail */
				successFlag = 0;
			}
		} else {
			activeProc = longAt(((longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord))) + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
			/* begin addLastLink:toList: */
			if ((longAt((sema + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord))) == nilObj) {
				/* begin storePointer:ofObject:withValue: */
				if ((((usqInt) sema)) < (((usqInt) youngStart))) {
					possibleRootStoreIntovalue(sema, activeProc);
				}
				longAtput((sema + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord), activeProc);
			} else {
				lastLink = longAt((sema + BaseHeaderSize) + (LastLinkIndex << ShiftForWord));
				/* begin storePointer:ofObject:withValue: */
				if ((((usqInt) lastLink)) < (((usqInt) youngStart))) {
					possibleRootStoreIntovalue(lastLink, activeProc);
				}
				longAtput((lastLink + BaseHeaderSize) + (NextLinkIndex << ShiftForWord), activeProc);
			}
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) sema)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(sema, activeProc);
			}
			longAtput((sema + BaseHeaderSize) + (LastLinkIndex << ShiftForWord), activeProc);
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) activeProc)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(activeProc, sema);
			}
			longAtput((activeProc + BaseHeaderSize) + (MyListIndex << ShiftForWord), sema);
			transferTo(wakeHighestPriority());
		}
	}
}


/*	primitively do the equivalent of Process>yield */

sqInt primitiveYield(void) {
    sqInt processLists;
    sqInt activeProc;
    sqInt priority;
    sqInt processList;
    sqInt lastLink;

	activeProc = longAt(((longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord))) + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
	priority = ((longAt((activeProc + BaseHeaderSize) + (PriorityIndex << ShiftForWord))) >> 1);
	processLists = longAt(((longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord))) + BaseHeaderSize) + (ProcessListsIndex << ShiftForWord));
	processList = longAt((processLists + BaseHeaderSize) + ((priority - 1) << ShiftForWord));
	if (!((longAt((processList + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord))) == nilObj)) {
		/* begin addLastLink:toList: */
		if ((longAt((processList + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord))) == nilObj) {
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) processList)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(processList, activeProc);
			}
			longAtput((processList + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord), activeProc);
		} else {
			lastLink = longAt((processList + BaseHeaderSize) + (LastLinkIndex << ShiftForWord));
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) lastLink)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(lastLink, activeProc);
			}
			longAtput((lastLink + BaseHeaderSize) + (NextLinkIndex << ShiftForWord), activeProc);
		}
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) processList)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(processList, activeProc);
		}
		longAtput((processList + BaseHeaderSize) + (LastLinkIndex << ShiftForWord), activeProc);
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) activeProc)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(activeProc, processList);
		}
		longAtput((activeProc + BaseHeaderSize) + (MyListIndex << ShiftForWord), processList);
		transferTo(wakeHighestPriority());
	}
}


/*	For testing in Smalltalk, this method should be overridden in a subclass. */

sqInt print(char * s) {
	printf("%s", s);
}


/*	Print all the stacks of all running processes, including those that are currently suspended. */

sqInt printAllStacks(void) {
    sqInt oop;
    sqInt proc;
    sqInt ctx;
    sqInt sz;
    sqInt header;

	proc = longAt(((longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord))) + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
	printNameOfClasscount(fetchClassOf(proc), 5);
	/* begin cr */
	printf("\n");
	printCallStackOf(activeContext);
	oop = memory + (headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) endOfMemory))) {
		if ((fetchClassOf(oop)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassSemaphore << ShiftForWord)))) {
			/* begin cr */
			printf("\n");
			proc = longAt((oop + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord));
			while (!(proc == nilObj)) {
				printNameOfClasscount(fetchClassOf(proc), 5);
				/* begin cr */
				printf("\n");
				ctx = longAt((proc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord));
				if (!(ctx == nilObj)) {
					printCallStackOf(ctx);
				}
				proc = longAt((proc + BaseHeaderSize) + (NextLinkIndex << ShiftForWord));
			}
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) oop)) >= (((usqInt) endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(oop)) & AllButTypeMask;
		} else {
			/* begin sizeBitsOf: */
			header = longAt(oop);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
				goto l1;
			} else {
				sz = header & SizeMask;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		oop = (oop + sz) + (headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	}
}

sqInt printCallStack(void) {
	return printCallStackOf(activeContext);
}

sqInt printCallStackOf(sqInt aContext) {
    sqInt methClass;
    sqInt methodSel;
    sqInt home;
    sqInt message;
    sqInt ctxt;
    sqInt done;
    sqInt classDict;
    sqInt classDictSize;
    sqInt i;
    sqInt currClass;
    sqInt methodArray;
    sqInt sz;
    sqInt header;
    sqInt ccIndex;
    sqInt done1;
    sqInt classDict1;
    sqInt classDictSize1;
    sqInt i1;
    sqInt currClass1;
    sqInt methodArray1;
    sqInt sz1;
    sqInt header1;
    sqInt ccIndex2;
    sqInt ccIndex1;

	ctxt = aContext;
	while (!(ctxt == nilObj)) {
		if ((fetchClassOf(ctxt)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassBlockContext << ShiftForWord)))) {
			home = longAt((ctxt + BaseHeaderSize) + (HomeIndex << ShiftForWord));
		} else {
			home = ctxt;
		}
		/* begin findClassOfMethod:forReceiver: */
		/* begin fetchClassOf: */
		if (((longAt((home + BaseHeaderSize) + (ReceiverIndex << ShiftForWord))) & 1)) {
			currClass1 = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
			goto l5;
		}
		ccIndex2 = (((usqInt) (longAt(longAt((home + BaseHeaderSize) + (ReceiverIndex << ShiftForWord))))) >> 12) & 31;
		if (ccIndex2 == 0) {
			currClass1 = (longAt((longAt((home + BaseHeaderSize) + (ReceiverIndex << ShiftForWord))) - BaseHeaderSize)) & AllButTypeMask;
			goto l5;
		} else {
			currClass1 = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex2 - 1) << ShiftForWord));
			goto l5;
		}
	l5:	/* end fetchClassOf: */;
		done1 = 0;
		while (!(done1)) {
			classDict1 = longAt((currClass1 + BaseHeaderSize) + (MessageDictionaryIndex << ShiftForWord));
			/* begin fetchWordLengthOf: */
			/* begin sizeBitsOf: */
			header1 = longAt(classDict1);
			if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
				sz1 = (longAt(classDict1 - (BytesPerWord * 2))) & LongSizeMask;
				goto l4;
			} else {
				sz1 = header1 & SizeMask;
				goto l4;
			}
		l4:	/* end sizeBitsOf: */;
			classDictSize1 = ((usqInt) (sz1 - BaseHeaderSize)) >> ShiftForWord;
			methodArray1 = longAt((classDict1 + BaseHeaderSize) + (MethodArrayIndex << ShiftForWord));
			i1 = 0;
			while (i1 < (classDictSize1 - SelectorStart)) {
				if ((longAt((home + BaseHeaderSize) + (MethodIndex << ShiftForWord))) == (longAt((methodArray1 + BaseHeaderSize) + (i1 << ShiftForWord)))) {
					methClass = currClass1;
					goto l6;
				}
				i1 += 1;
			}
			currClass1 = longAt((currClass1 + BaseHeaderSize) + (SuperclassIndex << ShiftForWord));
			done1 = currClass1 == nilObj;
		}
		/* begin fetchClassOf: */
		if (((longAt((home + BaseHeaderSize) + (ReceiverIndex << ShiftForWord))) & 1)) {
			methClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
			goto l6;
		}
		ccIndex1 = (((usqInt) (longAt(longAt((home + BaseHeaderSize) + (ReceiverIndex << ShiftForWord))))) >> 12) & 31;
		if (ccIndex1 == 0) {
			methClass = (longAt((longAt((home + BaseHeaderSize) + (ReceiverIndex << ShiftForWord))) - BaseHeaderSize)) & AllButTypeMask;
			goto l6;
		} else {
			methClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex1 - 1) << ShiftForWord));
			goto l6;
		}
		methClass = null;
	l6:	/* end findClassOfMethod:forReceiver: */;
		/* begin findSelectorOfMethod:forReceiver: */
		/* begin fetchClassOf: */
		if (((longAt((home + BaseHeaderSize) + (ReceiverIndex << ShiftForWord))) & 1)) {
			currClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
			goto l2;
		}
		ccIndex = (((usqInt) (longAt(longAt((home + BaseHeaderSize) + (ReceiverIndex << ShiftForWord))))) >> 12) & 31;
		if (ccIndex == 0) {
			currClass = (longAt((longAt((home + BaseHeaderSize) + (ReceiverIndex << ShiftForWord))) - BaseHeaderSize)) & AllButTypeMask;
			goto l2;
		} else {
			currClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
			goto l2;
		}
	l2:	/* end fetchClassOf: */;
		done = 0;
		while (!(done)) {
			classDict = longAt((currClass + BaseHeaderSize) + (MessageDictionaryIndex << ShiftForWord));
			/* begin fetchWordLengthOf: */
			/* begin sizeBitsOf: */
			header = longAt(classDict);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(classDict - (BytesPerWord * 2))) & LongSizeMask;
				goto l1;
			} else {
				sz = header & SizeMask;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
			classDictSize = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
			methodArray = longAt((classDict + BaseHeaderSize) + (MethodArrayIndex << ShiftForWord));
			i = 0;
			while (i <= (classDictSize - SelectorStart)) {
				if ((longAt((home + BaseHeaderSize) + (MethodIndex << ShiftForWord))) == (longAt((methodArray + BaseHeaderSize) + (i << ShiftForWord)))) {
					methodSel = longAt((classDict + BaseHeaderSize) + ((i + SelectorStart) << ShiftForWord));
					goto l3;
				}
				i += 1;
			}
			currClass = longAt((currClass + BaseHeaderSize) + (SuperclassIndex << ShiftForWord));
			done = currClass == nilObj;
		}
		methodSel = nilObj;
	l3:	/* end findSelectorOfMethod:forReceiver: */;
		printNum(ctxt);
		print(" ");
		if (!(ctxt == home)) {
			print("[] in ");
		}
		printNameOfClasscount(methClass, 5);
		print(">");
		if (methodSel == nilObj) {
			print("?");
		} else {
			printStringOf(methodSel);
		}
		if (methodSel == (longAt((specialObjectsOop + BaseHeaderSize) + (SelectorDoesNotUnderstand << ShiftForWord)))) {

			/* print arg message selector */

			message = longAt((home + BaseHeaderSize) + ((0 + TempFrameStart) << ShiftForWord));
			methodSel = longAt((message + BaseHeaderSize) + (MessageSelectorIndex << ShiftForWord));
			print(" ");
			printStringOf(methodSel);
		}
		/* begin cr */
		printf("\n");
		ctxt = longAt((ctxt + BaseHeaderSize) + (SenderIndex << ShiftForWord));
	}
}


/*	Details: The count argument is used to avoid a possible infinite recursion if classOop is a corrupted object. */

sqInt printNameOfClasscount(sqInt classOop, sqInt cnt) {
	if (cnt <= 0) {
		return print("bad class");
	}
	if ((sizeBitsOf(classOop)) == (7 * BytesPerWord)) {
		printNameOfClasscount(longAt((classOop + BaseHeaderSize) + (5 << ShiftForWord)), cnt - 1);
		print(" class");
	} else {
		printStringOf(longAt((classOop + BaseHeaderSize) + (6 << ShiftForWord)));
	}
}


/*	For testing in Smalltalk, this method should be overridden in a subclass. */

sqInt printNum(sqInt n) {
	printf("%ld", (long) n);
}

sqInt printStringOf(sqInt oop) {
    sqInt cnt;
    sqInt fmt;
    sqInt i;

	if ((oop & 1)) {
		return null;
	}
	fmt = (((usqInt) (longAt(oop))) >> 8) & 15;
	if (fmt < 8) {
		return null;
	}
	cnt = ((100 < (lengthOf(oop))) ? 100 : (lengthOf(oop)));
	i = 0;
	while (i < cnt) {
		/* begin printChar: */
		putchar(byteAt((oop + BaseHeaderSize) + i));
		i += 1;
	}
}

sqInt printUnbalancedStack(sqInt primIdx) {
	print("Stack unbalanced after ");
	if (successFlag) {
		print("successful primitive ");
	} else {
		print("failed primitive ");
	}
	printNum(primIdx);
	/* begin cr */
	printf("\n");
}

sqInt push(sqInt object) {
    sqInt sp;

	longAtput(sp = stackPointer + BytesPerWord, object);
	stackPointer = sp;
}

sqInt pushBool(sqInt trueOrFalse) {
    sqInt sp;
    sqInt sp1;

	if (trueOrFalse) {
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, trueObj);
		stackPointer = sp;
	} else {
		/* begin push: */
		longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
		stackPointer = sp1;
	}
}

sqInt pushFloat(double  f) {
    sqInt object;
    sqInt sp;

	/* begin push: */
	object = floatObjectOf(f);
	longAtput(sp = stackPointer + BytesPerWord, object);
	stackPointer = sp;
}

sqInt pushInteger(sqInt integerValue) {
    sqInt sp;

	/* begin push: */
	longAtput(sp = stackPointer + BytesPerWord, ((integerValue << 1) | 1));
	stackPointer = sp;
}


/*	Record the given object in a the remap buffer. Objects in this buffer are remapped when a compaction occurs. This facility is used by the interpreter to ensure that objects in temporary variables are properly remapped. */

sqInt pushRemappableOop(sqInt oop) {
	remapBuffer[remapBufferCount += 1] = oop;
}


/*	Append aWord to aFile in this platforms 'natural' byte order.  (Bytes will be swapped, if
	necessary, when the image is read on a different platform.) Set successFlag to false if
	the write fails. */

sqInt putLongtoFile(sqInt aWord, sqImageFile  aFile) {
    sqInt objectsWritten;

	objectsWritten = sqImageFileWrite(&aWord, sizeof(aWord), 1, aFile);
	/* begin success: */
	successFlag = (objectsWritten == 1) && successFlag;
}


/*	Read an image from the given file stream, allocating the given amount of memory to its object heap. Fail if the image has an unknown format or requires more than the given amount of memory. */
/*	Details: This method detects when the image was stored on a machine with the opposite byte ordering from this machine and swaps the bytes automatically. Furthermore, it allows the header information to start 512 bytes into the file, since some file transfer programs for the Macintosh apparently prepend a Mac-specific header of this size. Note that this same 512 bytes of prefix area could also be used to store an exec command on Unix systems, allowing one to launch Smalltalk by invoking the image name as a command. */
/*	This code is based on C code by Ian Piumarta and Smalltalk code by Tim Rowledge. Many thanks to both of you!! */

sqInt readImageFromFileHeapSizeStartingAt(sqImageFile  f, sqInt desiredHeapSize, squeakFileOffsetType  imageOffset) {
    sqInt memStart;
    size_t bytesRead;
    sqInt headerSize;
    squeakFileOffsetType  headerStart;
    sqInt swapBytes;
    size_t  dataSize;
    sqInt heapSize;
    sqInt bytesToShift;
    sqInt oldBaseAddr;
    sqInt minimumMemory;
    char * memoryAddress;
    sqInt startAddr;
    sqInt stopAddr;
    sqInt addr;

	swapBytes = checkImageVersionFromstartingAt(f, imageOffset);

	/* record header start position */

	headerStart = (sqImageFilePosition(f)) - BytesPerWord;
	headerSize = getLongFromFileswap(f, swapBytes);
	dataSize = getLongFromFileswap(f, swapBytes);
	oldBaseAddr = getLongFromFileswap(f, swapBytes);
	specialObjectsOop = getLongFromFileswap(f, swapBytes);
	lastHash = getLongFromFileswap(f, swapBytes);
	savedWindowSize = getLongFromFileswap(f, swapBytes);
	fullScreenFlag = getLongFromFileswap(f, swapBytes);
	extraVMMemory = getLongFromFileswap(f, swapBytes);
	if (lastHash == 0) {

		/* lastHash wasn't stored (e.g. by the cloner); use 999 as the seed */

		lastHash = 999;
	}
	heapSize = reserveExtraCHeapBytes(desiredHeapSize, extraVMMemory);

	/* need at least 100K of breathing room */

	minimumMemory = dataSize + 100000;
	if (heapSize < minimumMemory) {
		insufficientMemorySpecifiedError();
	}
	memory = allocateMemoryMinimumImageFileHeaderSize(heapSize, minimumMemory, f, headerSize);
	if (memory == null) {
		insufficientMemoryAvailableError();
	}
	memStart = memory;

	/* decrease memoryLimit a tad for safety */

	memoryLimit = (memStart + heapSize) - 24;

	/* position file after the header */

	endOfMemory = memStart + dataSize;
	sqImageFileSeek(f, headerStart + headerSize);
	/* begin sqImage:read:size:length: */
	memoryAddress = pointerForOop(memory);
	bytesRead = sqImageFileReadEntireImage(memoryAddress, sizeof(unsigned char), dataSize, f);
	if (bytesRead != dataSize) {
		unableToReadImageError();
	}
	headerTypeBytes[0] = (BytesPerWord * 2);
	headerTypeBytes[1] = BytesPerWord;
	headerTypeBytes[2] = 0;
	headerTypeBytes[3] = 0;
	if (swapBytes) {
		/* begin reverseBytesInImage */
		/* begin reverseBytesFrom:to: */
		startAddr = memory;
		stopAddr = endOfMemory;
		flag("Dan");
		addr = startAddr;
		while ((((usqInt) addr)) < (((usqInt) stopAddr))) {
			longAtput(addr, byteSwapped(longAt(addr)));
			addr += BytesPerWord;
		}
		/* begin byteSwapByteObjects */
		byteSwapByteObjectsFromto(memory + (headerTypeBytes[(longAt(memory)) & TypeMask]), endOfMemory);
	}
	bytesToShift = memStart - oldBaseAddr;
	initializeInterpreter(bytesToShift);
	isBigEnder();
	return dataSize;
}


/*	Anwer true if images of the given format are readable by this interpreter. Allows a virtual machine to accept selected older image formats.  In our case we can select a newer (closure) image format as well as the existing format. */

sqInt readableFormat(sqInt imageVersion) {
	return (imageVersion == imageFormatVersionNumber) || (imageVersion == (imageFormatForwardCompatibilityVersion()));
}


/*	Map the given oop to its new value during a compaction or 
	become: operation. If it has no forwarding table entry, 
	return the oop itself. */

sqInt remap(sqInt oop) {
    sqInt fwdBlock;

	if (((oop & 1) == 0) && (((longAt(oop)) & MarkBit) != 0)) {

		/* get the new value for oop from its forwarding block */

		fwdBlock = ((longAt(oop)) & AllButMarkBitAndTypeMask) << 1;
		if (DoAssertionChecks) {
			/* begin fwdBlockValidate: */
			if (!(((((usqInt) fwdBlock)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock)) <= (((usqInt) fwdTableNext))) && ((fwdBlock & 3) == 0)))) {
				error("invalid fwd table entry");
			}
		}
		return longAt(fwdBlock);
	}
	return oop;
}


/*	Remove the first process from the given linked list. */

sqInt removeFirstLinkOfList(sqInt aList) {
    sqInt next;
    sqInt first;
    sqInt last;
    sqInt valuePointer;
    sqInt valuePointer1;
    sqInt valuePointer2;
    sqInt valuePointer3;

	first = longAt((aList + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord));
	last = longAt((aList + BaseHeaderSize) + (LastLinkIndex << ShiftForWord));
	if (first == last) {
		/* begin storePointer:ofObject:withValue: */
		valuePointer = nilObj;
		if ((((usqInt) aList)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(aList, valuePointer);
		}
		longAtput((aList + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord), valuePointer);
		/* begin storePointer:ofObject:withValue: */
		valuePointer1 = nilObj;
		if ((((usqInt) aList)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(aList, valuePointer1);
		}
		longAtput((aList + BaseHeaderSize) + (LastLinkIndex << ShiftForWord), valuePointer1);
	} else {
		next = longAt((first + BaseHeaderSize) + (NextLinkIndex << ShiftForWord));
		/* begin storePointer:ofObject:withValue: */
		if ((((usqInt) aList)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(aList, next);
		}
		longAtput((aList + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord), next);
	}
	/* begin storePointer:ofObject:withValue: */
	valuePointer2 = nilObj;
	if ((((usqInt) first)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(first, valuePointer2);
	}
	longAtput((first + BaseHeaderSize) + (NextLinkIndex << ShiftForWord), valuePointer2);
	/* begin storePointer:ofObject:withValue: */
	valuePointer3 = nilObj;
	if ((((usqInt) first)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(first, valuePointer3);
	}
	longAtput((first + BaseHeaderSize) + (MyListIndex << ShiftForWord), valuePointer3);
	return first;
}


/*	Remove the given variable location to the extra roots table */

EXPORT(sqInt) removeGCRoot(sqInt *varLoc) {
    sqInt *root;
    sqInt i;

	for (i = 1; i <= extraRootCount; i += 1) {
		root = extraRoots[i];
		if (root == varLoc) {
			extraRoots[i] = (extraRoots[extraRootCount]);
			extraRootCount -= 1;
			return 1;
		}
	}
	return 0;
}


/*	Restore headers smashed by forwarding links */

sqInt restoreHeadersFromtofromandtofrom(sqInt firstIn, sqInt lastIn, sqInt hdrBaseIn, sqInt firstOut, sqInt lastOut, sqInt hdrBaseOut) {
    sqInt oop;
    sqInt header;
    sqInt tablePtr;
    sqInt sz;
    sqInt header1;

	tablePtr = firstIn;
	while ((((usqInt) tablePtr)) <= (((usqInt) lastIn))) {
		oop = longAt(tablePtr);
		header = longAt(hdrBaseIn + (tablePtr - firstIn));
		longAtput(oop, header);
		tablePtr += BytesPerWord;
	}
	tablePtr = firstOut;
	while ((((usqInt) tablePtr)) <= (((usqInt) lastOut))) {
		oop = longAt(tablePtr);
		header = longAt(hdrBaseOut + (tablePtr - firstOut));
		longAtput(oop, header);
		tablePtr += BytesPerWord;
	}
	oop = memory + (headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) endOfMemory))) {
		if (!(((longAt(oop)) & TypeMask) == HeaderTypeFree)) {
			longAtput(oop, (longAt(oop)) & AllButMarkBit);
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) oop)) >= (((usqInt) endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(oop)) & AllButTypeMask;
		} else {
			/* begin sizeBitsOf: */
			header1 = longAt(oop);
			if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
				goto l1;
			} else {
				sz = header1 & SizeMask;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		oop = (oop + sz) + (headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	}
}

sqInt resume(sqInt aProcess) {
    sqInt activeProc;
    sqInt activePriority;
    sqInt newPriority;
    sqInt processLists;
    sqInt priority;
    sqInt processList;
    sqInt myList;
    sqInt lastLink;
    sqInt processLists1;
    sqInt priority1;
    sqInt processList1;
    sqInt myList1;
    sqInt lastLink1;

	activeProc = longAt(((longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord))) + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
	activePriority = ((longAt((activeProc + BaseHeaderSize) + (PriorityIndex << ShiftForWord))) >> 1);
	newPriority = ((longAt((aProcess + BaseHeaderSize) + (PriorityIndex << ShiftForWord))) >> 1);
	if (newPriority > activePriority) {
		/* begin putToSleep: */
		myList = longAt((activeProc + BaseHeaderSize) + (MyListIndex << ShiftForWord));
		if (myList == nilObj) {
			priority = ((longAt((activeProc + BaseHeaderSize) + (PriorityIndex << ShiftForWord))) >> 1);
			processLists = longAt(((longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord))) + BaseHeaderSize) + (ProcessListsIndex << ShiftForWord));
			processList = longAt((processLists + BaseHeaderSize) + ((priority - 1) << ShiftForWord));
			/* begin addLastLink:toList: */
			if ((longAt((processList + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord))) == nilObj) {
				/* begin storePointer:ofObject:withValue: */
				if ((((usqInt) processList)) < (((usqInt) youngStart))) {
					possibleRootStoreIntovalue(processList, activeProc);
				}
				longAtput((processList + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord), activeProc);
			} else {
				lastLink = longAt((processList + BaseHeaderSize) + (LastLinkIndex << ShiftForWord));
				/* begin storePointer:ofObject:withValue: */
				if ((((usqInt) lastLink)) < (((usqInt) youngStart))) {
					possibleRootStoreIntovalue(lastLink, activeProc);
				}
				longAtput((lastLink + BaseHeaderSize) + (NextLinkIndex << ShiftForWord), activeProc);
			}
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) processList)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(processList, activeProc);
			}
			longAtput((processList + BaseHeaderSize) + (LastLinkIndex << ShiftForWord), activeProc);
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) activeProc)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(activeProc, processList);
			}
			longAtput((activeProc + BaseHeaderSize) + (MyListIndex << ShiftForWord), processList);
		}
		transferTo(aProcess);
	} else {
		/* begin putToSleep: */
		myList1 = longAt((aProcess + BaseHeaderSize) + (MyListIndex << ShiftForWord));
		if (myList1 == nilObj) {
			priority1 = ((longAt((aProcess + BaseHeaderSize) + (PriorityIndex << ShiftForWord))) >> 1);
			processLists1 = longAt(((longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord))) + BaseHeaderSize) + (ProcessListsIndex << ShiftForWord));
			processList1 = longAt((processLists1 + BaseHeaderSize) + ((priority1 - 1) << ShiftForWord));
			/* begin addLastLink:toList: */
			if ((longAt((processList1 + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord))) == nilObj) {
				/* begin storePointer:ofObject:withValue: */
				if ((((usqInt) processList1)) < (((usqInt) youngStart))) {
					possibleRootStoreIntovalue(processList1, aProcess);
				}
				longAtput((processList1 + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord), aProcess);
			} else {
				lastLink1 = longAt((processList1 + BaseHeaderSize) + (LastLinkIndex << ShiftForWord));
				/* begin storePointer:ofObject:withValue: */
				if ((((usqInt) lastLink1)) < (((usqInt) youngStart))) {
					possibleRootStoreIntovalue(lastLink1, aProcess);
				}
				longAtput((lastLink1 + BaseHeaderSize) + (NextLinkIndex << ShiftForWord), aProcess);
			}
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) processList1)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(processList1, aProcess);
			}
			longAtput((processList1 + BaseHeaderSize) + (LastLinkIndex << ShiftForWord), aProcess);
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) aProcess)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(aProcess, processList1);
			}
			longAtput((aProcess + BaseHeaderSize) + (MyListIndex << ShiftForWord), processList1);
		}
	}
}


/*	Reverse the given range of Display words (at different bit 
	depths, this will reverse different numbers of pixels). Used to 
	give feedback during VM activities such as garbage 
	collection when debugging. It is assumed that the given 
	word range falls entirely within the first line of the Display. */

sqInt reverseDisplayFromto(sqInt startIndex, sqInt endIndex) {
    sqInt displayObj;
    sqInt ptr;
    sqInt reversed;
    sqInt dispBitsPtr;
    sqInt w;

	displayObj = longAt((specialObjectsOop + BaseHeaderSize) + (TheDisplay << ShiftForWord));
	if (!((((displayObj & 1) == 0) && (((((usqInt) (longAt(displayObj))) >> 8) & 15) <= 4)) && ((lengthOf(displayObj)) >= 4))) {
		return null;
	}
	w = fetchIntegerofObject(1, displayObj);
	dispBitsPtr = longAt((displayObj + BaseHeaderSize) + (0 << ShiftForWord));
	if ((dispBitsPtr & 1)) {
		return null;
	}
	dispBitsPtr += BaseHeaderSize;
	for (ptr = (dispBitsPtr + (startIndex * 4)); ptr <= (dispBitsPtr + (endIndex * 4)); ptr += 4) {
		reversed = (long32At(ptr)) ^ 4294967295U;
		longAtput(ptr, reversed);
	}
	successFlag = 1;
	displayBitsOfLeftTopRightBottom(displayObj, 0, 0, w, 1);
	ioForceDisplayUpdate();
}


/*	Rewrite the cache entry with the given primitive index and matching function pointer */

sqInt rewriteMethodCacheSelclassprimIndex(sqInt selector, sqInt class, sqInt localPrimIndex) {
    void * primPtr;

	if (localPrimIndex == 0) {
		primPtr = 0;
	} else {
		primPtr = primitiveTable[localPrimIndex];
	}
	rewriteMethodCacheSelclassprimIndexprimFunction(selector, class, localPrimIndex, primPtr);
}


/*	Rewrite an existing entry in the method cache with a new primitive 
	index & function address. Used by primExternalCall to make direct jumps to found external prims */

sqInt rewriteMethodCacheSelclassprimIndexprimFunction(sqInt selector, sqInt class, sqInt localPrimIndex, void * localPrimAddress) {
    sqInt hash;
    sqInt p;
    sqInt probe;

	hash = selector ^ class;
	for (p = 0; p <= (CacheProbeMax - 1); p += 1) {
		probe = (((usqInt) hash) >> p) & MethodCacheMask;
		if (((methodCache[probe + MethodCacheSelector]) == selector) && ((methodCache[probe + MethodCacheClass]) == class)) {
			methodCache[probe + MethodCachePrim] = localPrimIndex;
			methodCache[probe + MethodCachePrimFunction] = (((long) localPrimAddress));
			return null;
		}
	}
}

sqInt setCompilerInitialized(sqInt newFlag) {
    sqInt oldFlag;

	oldFlag = compilerInitialized;
	compilerInitialized = newFlag;
	return oldFlag;
}

sqInt setFullScreenFlag(sqInt value) {
	fullScreenFlag = value;
}

sqInt setInterruptCheckCounter(sqInt value) {
	interruptCheckCounter = value;
}

sqInt setInterruptKeycode(sqInt value) {
	interruptKeycode = value;
}

sqInt setInterruptPending(sqInt value) {
	interruptPending = value;
}

sqInt setNextWakeupTick(sqInt value) {
	nextWakeupTick = value;
}

sqInt setSavedWindowSize(sqInt value) {
	savedWindowSize = value;
}


/*	Repaint the portion of the Smalltalk screen bounded by the affected rectangle. Used to synchronize the screen after a Bitblt to the Smalltalk Display object. */

sqInt showDisplayBitsLeftTopRightBottom(sqInt aForm, sqInt l, sqInt t, sqInt r, sqInt b) {
	if (deferDisplayUpdates) {
		return null;
	}
	displayBitsOfLeftTopRightBottom(aForm, l, t, r, b);
}


/*	Record the given semaphore index in the double buffer semaphores array to be signaled at the next convenient moment. Force a real interrupt check as soon as possible. */

sqInt signalSemaphoreWithIndex(sqInt index) {
	if (index <= 0) {
		return null;
	}
	if (semaphoresUseBufferA) {
		if (semaphoresToSignalCountA < SemaphoresToSignalSize) {
			semaphoresToSignalCountA += 1;
			semaphoresToSignalA[semaphoresToSignalCountA] = index;
		}
	} else {
		if (semaphoresToSignalCountB < SemaphoresToSignalSize) {
			semaphoresToSignalCountB += 1;
			semaphoresToSignalB[semaphoresToSignalCountB] = index;
		}
	}
	/* begin forceInterruptCheck */
	interruptCheckCounter = -1000;
	nextPollTick = 0;
}


/*	Return a full 32 bit integer object for the given integer value */

sqInt signed32BitIntegerFor(int integerValue) {
    sqInt value;
    sqInt newLargeInteger;
    sqInt largeClass;

	if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) integerValue)) ^ ((((int) integerValue)) << 1)) >= 0)
# else
		((integerValue >= -1073741824) && (integerValue <= 1073741823))
# endif  // SQ_HOST32
	) {
		return ((integerValue << 1) | 1);
	}
	if (integerValue < 0) {
		largeClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassLargeNegativeInteger << ShiftForWord));
		value = 0 - integerValue;
	} else {
		largeClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassLargePositiveInteger << ShiftForWord));
		value = integerValue;
	}
	newLargeInteger = instantiateClassindexableSize(largeClass, 4);
	byteAtput((newLargeInteger + BaseHeaderSize) + 3, (((usqInt) value) >> 24) & 255);
	byteAtput((newLargeInteger + BaseHeaderSize) + 2, (((usqInt) value) >> 16) & 255);
	byteAtput((newLargeInteger + BaseHeaderSize) + 1, (((usqInt) value) >> 8) & 255);
	byteAtput((newLargeInteger + BaseHeaderSize) + 0, value & 255);
	return newLargeInteger;
}


/*	Convert the given object into an integer value.
	The object may be either a positive ST integer or a four-byte LargeInteger. */

int signed32BitValueOf(sqInt oop) {
    sqInt sz;
    int value;
    sqInt negative;
    sqInt largeClass;
    sqInt ccIndex;
    sqInt header;
    sqInt sz1;

	if ((oop & 1)) {
		return (oop >> 1);
	}
	if ((lengthOf(oop)) > 4) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		largeClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		largeClass = (longAt(oop - BaseHeaderSize)) & AllButTypeMask;
		goto l1;
	} else {
		largeClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	if (largeClass == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassLargePositiveInteger << ShiftForWord)))) {
		negative = 0;
	} else {
		if (largeClass == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassLargeNegativeInteger << ShiftForWord)))) {
			negative = 1;
		} else {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz1 = header & SizeMask;
	}
	sz1 -= header & Size4Bit;
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		sz = ((usqInt) (sz1 - BaseHeaderSize)) >> ShiftForWord;
		goto l2;
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		sz = ((usqInt) (sz1 - BaseHeaderSize)) >> 2;
		goto l2;
	} else {
		sz = (sz1 - BaseHeaderSize) - (((((usqInt) header) >> 8) & 15) & 3);
		goto l2;
	}
	sz = null;
l2:	/* end lengthOf: */;
	if (!(sz == 4)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}

	/* Fail if value exceeds range of a 32-bit two's-complement signed integer. */

	value = (((byteAt((oop + BaseHeaderSize) + 0)) + ((byteAt((oop + BaseHeaderSize) + 1)) << 8)) + ((byteAt((oop + BaseHeaderSize) + 2)) << 16)) + ((byteAt((oop + BaseHeaderSize) + 3)) << 24);
	if (negative) {
		value = 0 - value;
		if (value >= 0) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	} else {
		if (value < 0) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	return value;
}


/*	Return a Large Integer object for the given integer value */

sqInt signed64BitIntegerFor(sqLong integerValue) {
    unsigned sqLong magnitude;
    sqInt sz;
    usqInt highWord;
    sqInt i;
    sqInt newLargeInteger;
    sqInt intValue;
    sqInt largeClass;

	if (integerValue < 0) {
		largeClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassLargeNegativeInteger << ShiftForWord));
		magnitude = 0 - integerValue;
	} else {
		largeClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassLargePositiveInteger << ShiftForWord));
		magnitude = integerValue;
	}
	if (magnitude <= 2147483647U) {
		return signed32BitIntegerFor(integerValue);
	}

	/* shift is coerced to usqInt otherwise */

	highWord = magnitude >> 32;
	if (highWord == 0) {
		sz = 4;
	} else {
		sz = 5;
		if (!((highWord = ((usqInt) highWord) >> 8) == 0)) {
			sz += 1;
		}
		if (!((highWord = ((usqInt) highWord) >> 8) == 0)) {
			sz += 1;
		}
		if (!((highWord = ((usqInt) highWord) >> 8) == 0)) {
			sz += 1;
		}
	}
	newLargeInteger = instantiateClassindexableSize(largeClass, sz);
	for (i = 0; i <= (sz - 1); i += 1) {
		intValue = (magnitude >> (i * 8)) & 255;
		byteAtput((newLargeInteger + BaseHeaderSize) + i, intValue);
	}
	return newLargeInteger;
}


/*	Convert the given object into an integer value.
	The object may be either a positive ST integer or a eight-byte LargeInteger. */

sqLong signed64BitValueOf(sqInt oop) {
    sqInt sz;
    sqInt i;
    sqLong value;
    sqInt szsqLong;
    sqInt negative;
    sqInt largeClass;
    sqInt ccIndex;
    sqInt header;
    sqInt sz1;

	if ((oop & 1)) {
		return ((sqLong) ((oop >> 1)));
	}
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz1 = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz1 = header & SizeMask;
	}
	sz1 -= header & Size4Bit;
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		sz = ((usqInt) (sz1 - BaseHeaderSize)) >> ShiftForWord;
		goto l2;
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		sz = ((usqInt) (sz1 - BaseHeaderSize)) >> 2;
		goto l2;
	} else {
		sz = (sz1 - BaseHeaderSize) - (((((usqInt) header) >> 8) & 15) & 3);
		goto l2;
	}
	sz = null;
l2:	/* end lengthOf: */;
	if (sz > 8) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		largeClass = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l1;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		largeClass = (longAt(oop - BaseHeaderSize)) & AllButTypeMask;
		goto l1;
	} else {
		largeClass = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l1;
	}
l1:	/* end fetchClassOf: */;
	if (largeClass == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassLargePositiveInteger << ShiftForWord)))) {
		negative = 0;
	} else {
		if (largeClass == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassLargeNegativeInteger << ShiftForWord)))) {
			negative = 1;
		} else {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	szsqLong = sizeof(sqLong);
	if (sz > szsqLong) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	value = 0;
	for (i = 0; i <= (sz - 1); i += 1) {
		value += (((sqLong) (byteAt((oop + BaseHeaderSize) + i)))) << (i * 8);
	}
	if (negative) {
		value = 0 - value;
		if (value >= 0) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	} else {
		if (value < 0) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	return value;
}


/*	Answer the number of bytes in the given object, including its base header, rounded up to an integral number of words. */
/*	Note: byte indexable objects need to have low bits subtracted from this size. */

sqInt sizeBitsOf(sqInt oop) {
    sqInt header;

	header = longAt(oop);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		return (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		return header & SizeMask;
	}
}


/*	Return the number of indexable fields of the given object. This method is to be called from an automatically generated C primitive. The argument is assumed to be a pointer to the first indexable field of a words or bytes object; the object header starts 4 bytes before that. */
/*	Note: Only called by translated primitive code. */

sqInt sizeOfSTArrayFromCPrimitive(void * cPtr) {
    sqInt oop;
    sqInt header;
    sqInt sz;

	oop = (oopForPointer(((char *) cPtr))) - BaseHeaderSize;
	if (!(((oop & 1) == 0) && (isWordsOrBytesNonInt(oop)))) {
		/* begin primitiveFail */
		successFlag = 0;
		return 0;
	}
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz = header & SizeMask;
	}
	sz -= header & Size4Bit;
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		return ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		return ((usqInt) (sz - BaseHeaderSize)) >> 2;
	} else {
		return (sz - BaseHeaderSize) - (((((usqInt) header) >> 8) & 15) & 3);
	}
	return null;
}


/*	Returns the number of slots in the receiver.
	If the receiver is a byte object, return the number of bytes.
	Otherwise return the number of words. */

sqInt slotSizeOf(sqInt oop) {
    sqInt header;
    sqInt sz;

	if ((oop & 1)) {
		return 0;
	}
	/* begin lengthOf: */
	header = longAt(oop);
	/* begin lengthOf:baseHeader:format: */
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz = header & SizeMask;
	}
	sz -= header & Size4Bit;
	if (((((usqInt) header) >> 8) & 15) <= 4) {
		return ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
	}
	if (((((usqInt) header) >> 8) & 15) < 8) {
		return ((usqInt) (sz - BaseHeaderSize)) >> 2;
	} else {
		return (sz - BaseHeaderSize) - (((((usqInt) header) >> 8) & 15) & 3);
	}
	return null;
}


/*	update state of active context */

sqInt snapshot(sqInt embedded) {
    sqInt activeProc;
    void * setMacType;
    sqInt dataSize;
    sqInt rcvr;
    sqInt top;
    sqInt sp;
    sqInt sp1;
    sqInt sp2;
    sqInt valuePointer;
    sqInt oop;
    sqInt sz;
    sqInt header;
    sqInt fmt;
    sqInt i;
    sqInt header1;
    sqInt oop1;
    sqInt i1;
    sqInt sz1;
    sqInt header2;

	if (compilerInitialized) {
		compilerPreSnapshot();
	} else {
		/* begin storeContextRegisters: */
		longAtput((activeContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord), ((((instructionPointer - method) - (BaseHeaderSize - 2)) << 1) | 1));
		longAtput((activeContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord), (((((((usqInt) ((stackPointer - activeContext) - BaseHeaderSize)) >> ShiftForWord) - TempFrameStart) + 1) << 1) | 1));
	}
	activeProc = longAt(((longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord))) + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
	/* begin storePointer:ofObject:withValue: */
	valuePointer = activeContext;
	if ((((usqInt) activeProc)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(activeProc, valuePointer);
	}
	longAtput((activeProc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord), valuePointer);
	incrementalGC();
	fullGC();
	/* begin snapshotCleanUp */
	oop = memory + (headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) endOfMemory))) {
		if (!(((longAt(oop)) & TypeMask) == HeaderTypeFree)) {
			header = longAt(oop);
			fmt = (((usqInt) header) >> 8) & 15;
			if ((fmt == 3) && ((((((usqInt) header) >> 12) & 31) == 13) || ((((((usqInt) header) >> 12) & 31) == 14) || (((((usqInt) header) >> 12) & 31) == 4)))) {
				/* begin sizeBitsOf: */
				header1 = longAt(oop);
				if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
					sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
					goto l1;
				} else {
					sz = header1 & SizeMask;
					goto l1;
				}
			l1:	/* end sizeBitsOf: */;
				for (i = ((lastPointerOf(oop)) + BytesPerWord); i <= (sz - BaseHeaderSize); i += BytesPerWord) {
					longAtput(oop + i, nilObj);
				}
			}
			if (fmt >= 12) {
				if ((primitiveIndexOf(oop)) == PrimitiveExternalCallIndex) {
					flushExternalPrimitiveOf(oop);
				}
			}
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) oop)) >= (((usqInt) endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			sz1 = (longAt(oop)) & AllButTypeMask;
		} else {
			/* begin sizeBitsOf: */
			header2 = longAt(oop);
			if ((header2 & TypeMask) == HeaderTypeSizeAndClass) {
				sz1 = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
				goto l2;
			} else {
				sz1 = header2 & SizeMask;
				goto l2;
			}
		l2:	/* end sizeBitsOf: */;
		}
		oop = (oop + sz1) + (headerTypeBytes[(longAt(oop + sz1)) & TypeMask]);
	}
	/* begin clearRootsTable */
	for (i1 = 1; i1 <= rootTableCount; i1 += 1) {
		oop1 = rootTable[i1];
		longAtput(oop1, (longAt(oop1)) & AllButRootBit);
		rootTable[i1] = 0;
	}
	rootTableCount = 0;

	/* Assume all objects are below the start of the free block */

	dataSize = freeBlock - memory;
	if (successFlag) {
		/* begin popStack */
		top = longAt(stackPointer);
		stackPointer -= BytesPerWord;
		rcvr = top;
		/* begin push: */
		longAtput(sp = stackPointer + BytesPerWord, trueObj);
		stackPointer = sp;
		writeImageFile(dataSize);
		if (!(embedded)) {

			/* set Mac file type and creator; this is a noop on other platforms */

			setMacType = ioLoadFunctionFrom("setMacFileTypeAndCreator", "FilePlugin");
			if (!(setMacType == 0)) {
				((sqInt (*)(char *, char *, char *))setMacType)(imageName, "STim", "FAST");
			}
		}
		/* begin pop: */
		stackPointer -= 1 * BytesPerWord;
	}
	beRootIfOld(activeContext);
	if (successFlag) {
		/* begin push: */
		longAtput(sp1 = stackPointer + BytesPerWord, falseObj);
		stackPointer = sp1;
	} else {
		/* begin push: */
		longAtput(sp2 = stackPointer + BytesPerWord, rcvr);
		stackPointer = sp2;
	}
	if (compilerInitialized) {
		compilerPostSnapshot();
	}
}


/*	Return one of the objects in the SpecialObjectsArray */

sqInt splObj(sqInt index) {
	return longAt((specialObjectsOop + BaseHeaderSize) + (index << ShiftForWord));
}


/*	Return what ST would return for <obj> at: index. */

sqInt stObjectat(sqInt array, sqInt index) {
    sqInt totalLength;
    sqInt fmt;
    sqInt fixedFields;
    sqInt hdr;
    sqInt stSize;
    sqInt sp;
    sqInt sz;
    sqInt classFormat;
    sqInt class;
    sqInt ccIndex;

	hdr = longAt(array);
	fmt = (((usqInt) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(array - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz = hdr & SizeMask;
	}
	sz -= hdr & Size4Bit;
	if (fmt <= 4) {
		totalLength = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
		goto l2;
	}
	if (fmt < 8) {
		totalLength = ((usqInt) (sz - BaseHeaderSize)) >> 2;
		goto l2;
	} else {
		totalLength = (sz - BaseHeaderSize) - (fmt & 3);
		goto l2;
	}
l2:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l3;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l3;
	}
	/* begin fetchClassOf: */
	if ((array & 1)) {
		class = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l4;
	}
	ccIndex = (((usqInt) (longAt(array))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(array - BaseHeaderSize)) & AllButTypeMask;
		goto l4;
	} else {
		class = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l4;
	}
l4:	/* end fetchClassOf: */;
	classFormat = (longAt((class + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1;
	fixedFields = (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
l3:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && ((((((usqInt) hdr) >> 12) & 31) == 13) || ((((((usqInt) hdr) >> 12) & 31) == 14) || (((((usqInt) hdr) >> 12) & 31) == 4)))) {
		/* begin fetchStackPointerOf: */
		sp = longAt((array + BaseHeaderSize) + (StackPointerIndex << ShiftForWord));
		if (!((sp & 1))) {
			stSize = 0;
			goto l1;
		}
		stSize = (sp >> 1);
	l1:	/* end fetchStackPointerOf: */;
	} else {
		stSize = totalLength - fixedFields;
	}
	if (((((usqInt) index)) >= (((usqInt) 1))) && ((((usqInt) index)) <= (((usqInt) stSize)))) {
		/* begin subscript:with:format: */
		if (fmt <= 4) {
			return longAt((array + BaseHeaderSize) + (((index + fixedFields) - 1) << ShiftForWord));
		}
		if (fmt < 8) {
			return positive32BitIntegerFor(long32At((array + BaseHeaderSize) + (((index + fixedFields) - 1) << 2)));
		} else {
			return (((byteAt((array + BaseHeaderSize) + ((index + fixedFields) - 1))) << 1) | 1);
		}
		return null;
	} else {
		successFlag = 0;
		return 0;
	}
}


/*	Do what ST would return for <obj> at: index put: value. */

sqInt stObjectatput(sqInt array, sqInt index, sqInt value) {
    sqInt totalLength;
    sqInt fmt;
    sqInt fixedFields;
    sqInt hdr;
    sqInt stSize;
    sqInt sz;
    sqInt sp;
    sqInt valueToStore;
    sqInt classFormat;
    sqInt class;
    sqInt ccIndex;

	hdr = longAt(array);
	fmt = (((usqInt) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(array - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz = hdr & SizeMask;
	}
	sz -= hdr & Size4Bit;
	if (fmt <= 4) {
		totalLength = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
		goto l1;
	}
	if (fmt < 8) {
		totalLength = ((usqInt) (sz - BaseHeaderSize)) >> 2;
		goto l1;
	} else {
		totalLength = (sz - BaseHeaderSize) - (fmt & 3);
		goto l1;
	}
l1:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l3;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l3;
	}
	/* begin fetchClassOf: */
	if ((array & 1)) {
		class = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l4;
	}
	ccIndex = (((usqInt) (longAt(array))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(array - BaseHeaderSize)) & AllButTypeMask;
		goto l4;
	} else {
		class = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l4;
	}
l4:	/* end fetchClassOf: */;
	classFormat = (longAt((class + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1;
	fixedFields = (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
l3:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && ((((((usqInt) hdr) >> 12) & 31) == 13) || ((((((usqInt) hdr) >> 12) & 31) == 14) || (((((usqInt) hdr) >> 12) & 31) == 4)))) {
		/* begin fetchStackPointerOf: */
		sp = longAt((array + BaseHeaderSize) + (StackPointerIndex << ShiftForWord));
		if (!((sp & 1))) {
			stSize = 0;
			goto l2;
		}
		stSize = (sp >> 1);
	l2:	/* end fetchStackPointerOf: */;
	} else {
		stSize = totalLength - fixedFields;
	}
	if (((((usqInt) index)) >= (((usqInt) 1))) && ((((usqInt) index)) <= (((usqInt) stSize)))) {
		/* begin subscript:with:storing:format: */
		if (fmt <= 4) {
			/* begin storePointer:ofObject:withValue: */
			if ((((usqInt) array)) < (((usqInt) youngStart))) {
				possibleRootStoreIntovalue(array, value);
			}
			longAtput((array + BaseHeaderSize) + (((index + fixedFields) - 1) << ShiftForWord), value);
		} else {
			if (fmt < 8) {
				valueToStore = positive32BitValueOf(value);
				if (successFlag) {
					long32Atput((array + BaseHeaderSize) + (((index + fixedFields) - 1) << 2), valueToStore);
				}
			} else {
				if (!((value & 1))) {
					successFlag = 0;
				}
				valueToStore = (value >> 1);
				if (!((valueToStore >= 0) && (valueToStore <= 255))) {
					successFlag = 0;
				}
				if (successFlag) {
					byteAtput((array + BaseHeaderSize) + ((index + fixedFields) - 1), valueToStore);
				}
			}
		}
	} else {
		successFlag = 0;
	}
}


/*	Return the number of indexable fields in the given object. (i.e., what Smalltalk would return for <obj> size). */
/*	Note: Assume oop is not a SmallInteger! */

sqInt stSizeOf(sqInt oop) {
    sqInt totalLength;
    sqInt fmt;
    sqInt fixedFields;
    sqInt hdr;
    sqInt sz;
    sqInt sp;
    sqInt classFormat;
    sqInt class;
    sqInt ccIndex;

	hdr = longAt(oop);
	fmt = (((usqInt) hdr) >> 8) & 15;
	/* begin lengthOf:baseHeader:format: */
	if ((hdr & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
	} else {
		sz = hdr & SizeMask;
	}
	sz -= hdr & Size4Bit;
	if (fmt <= 4) {
		totalLength = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;
		goto l1;
	}
	if (fmt < 8) {
		totalLength = ((usqInt) (sz - BaseHeaderSize)) >> 2;
		goto l1;
	} else {
		totalLength = (sz - BaseHeaderSize) - (fmt & 3);
		goto l1;
	}
l1:	/* end lengthOf:baseHeader:format: */;
	/* begin fixedFieldsOf:format:length: */
	if ((fmt > 4) || (fmt == 2)) {
		fixedFields = 0;
		goto l2;
	}
	if (fmt < 2) {
		fixedFields = totalLength;
		goto l2;
	}
	/* begin fetchClassOf: */
	if ((oop & 1)) {
		class = longAt((specialObjectsOop + BaseHeaderSize) + (ClassInteger << ShiftForWord));
		goto l3;
	}
	ccIndex = (((usqInt) (longAt(oop))) >> 12) & 31;
	if (ccIndex == 0) {
		class = (longAt(oop - BaseHeaderSize)) & AllButTypeMask;
		goto l3;
	} else {
		class = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (CompactClasses << ShiftForWord))) + BaseHeaderSize) + ((ccIndex - 1) << ShiftForWord));
		goto l3;
	}
l3:	/* end fetchClassOf: */;
	classFormat = (longAt((class + BaseHeaderSize) + (InstanceSpecificationIndex << ShiftForWord))) - 1;
	fixedFields = (((((usqInt) classFormat) >> 11) & 192) + ((((usqInt) classFormat) >> 2) & 63)) - 1;
l2:	/* end fixedFieldsOf:format:length: */;
	if ((fmt == 3) && ((((((usqInt) hdr) >> 12) & 31) == 13) || ((((((usqInt) hdr) >> 12) & 31) == 14) || (((((usqInt) hdr) >> 12) & 31) == 4)))) {
		/* begin fetchStackPointerOf: */
		sp = longAt((oop + BaseHeaderSize) + (StackPointerIndex << ShiftForWord));
		if (!((sp & 1))) {
			return 0;
		}
		return (sp >> 1);
	} else {
		return totalLength - fixedFields;
	}
}


/*	Note: May be called by translated primitive code. */

double stackFloatValue(sqInt offset) {
    double  result;
    sqInt floatPointer;

	floatPointer = longAt(stackPointer - (offset * BytesPerWord));
	if (!((fetchClassOf(floatPointer)) == (longAt((specialObjectsOop + BaseHeaderSize) + (ClassFloat << ShiftForWord))))) {
		/* begin primitiveFail */
		successFlag = 0;
		return 0.0;
	}
	;
	fetchFloatAtinto(floatPointer + BaseHeaderSize, result);
	return result;
}

sqInt stackIntegerValue(sqInt offset) {
    sqInt integerPointer;

	integerPointer = longAt(stackPointer - (offset * BytesPerWord));
	/* begin checkedIntegerValueOf: */
	if ((integerPointer & 1)) {
		return (integerPointer >> 1);
	} else {
		/* begin primitiveFail */
		successFlag = 0;
		return 0;
	}
	return null;
}


/*	Ensures that the given object is a real object, not a SmallInteger. */

sqInt stackObjectValue(sqInt offset) {
    sqInt oop;

	oop = longAt(stackPointer - (offset * BytesPerWord));
	if ((oop & 1)) {
		/* begin primitiveFail */
		successFlag = 0;
		return null;
	}
	return oop;
}

sqInt stackValue(sqInt offset) {
	return longAt(stackPointer - (offset * BytesPerWord));
}


/*	Note: May be called by translated primitive code. */

sqInt storeIntegerofObjectwithValue(sqInt fieldIndex, sqInt objectPointer, sqInt integerValue) {
	if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
		(((((int) integerValue)) ^ ((((int) integerValue)) << 1)) >= 0)
# else
		((integerValue >= -1073741824) && (integerValue <= 1073741823))
# endif  // SQ_HOST32
	) {
		longAtput((objectPointer + BaseHeaderSize) + (fieldIndex << ShiftForWord), ((integerValue << 1) | 1));
	} else {
		/* begin primitiveFail */
		successFlag = 0;
	}
}


/*	Note must check here for stores of young objects into old ones. */

sqInt storePointerofObjectwithValue(sqInt fieldIndex, sqInt oop, sqInt valuePointer) {
	if ((((usqInt) oop)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(oop, valuePointer);
	}
	return longAtput((oop + BaseHeaderSize) + (fieldIndex << ShiftForWord), valuePointer);
}

sqInt success(sqInt successValue) {
	successFlag = successValue && successFlag;
}


/*	Return true if there is enough free space after doing a garbage collection. If not, signal that space is low. */

sqInt sufficientSpaceAfterGC(usqInt minFree) {
    usqInt minFreePlus;
    usqInt growSize;

	incrementalGC();
	if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) < (((usqInt) minFree))) {
		if (signalLowSpace) {
			return 0;
		}
		fullGC();
		minFreePlus = minFree + 15000;
		if (minFreePlus < minFree) {
			return 0;
		}
		if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) >= (((usqInt) minFreePlus))) {
			return 1;
		}
		growSize = (minFree - ((longAt(freeBlock)) & AllButTypeMask)) + growHeadroom;
		growObjectMemory(growSize);
		if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) >= (((usqInt) minFreePlus))) {
			return 1;
		}
		return 0;
	}
	return 1;
}


/*	Return true if there is enough space to allocate the given number of bytes,
	perhaps after doing a garbage collection. Sender is responsible for ensuring
	that requested size does result in arithmetic overflow, see note below. */

sqInt sufficientSpaceToAllocate(usqInt bytes) {
    usqInt minFree;


	/* check for low-space */

	minFree = (lowSpaceThreshold + bytes) + BaseHeaderSize;
	if ((((usqInt) ((longAt(freeBlock)) & AllButTypeMask))) >= (((usqInt) minFree))) {
		return 1;
	} else {
		return sufficientSpaceAfterGC(minFree);
	}
}

sqInt superclassOf(sqInt classPointer) {
	return longAt((classPointer + BaseHeaderSize) + (SuperclassIndex << ShiftForWord));
}


/*	Sweep memory from youngStart through the end of memory. Free all 
	inaccessible objects and coalesce adjacent free chunks. Clear the mark 
	bits of accessible objects. Compute the starting point for the first pass of 
	incremental compaction (compStart). Return the number of surviving 
	objects.  */
/*	Details: Each time a non-free object is encountered, decrement the 
	number of available forward table entries. If all entries are spoken for 
	(i.e., entriesAvailable reaches zero), set compStart to the last free 
	chunk before that object or, if there is no free chunk before the given 
	object, the first free chunk after it. Thus, at the end of the sweep 
	phase, compStart through compEnd spans the highest collection of 
	non-free objects that can be accomodated by the forwarding table. This 
	information is used by the first pass of incremental compaction to 
	ensure that space is initially freed at the end of memory. Note that 
	there should always be at least one free chunk--the one at the end of 
	the heap. */

sqInt sweepPhase(void) {
    sqInt oopSize;
    usqInt oop;
    sqInt entriesAvailable;
    sqInt freeChunkSize;
    sqInt hdrBytes;
    sqInt oopHeaderType;
    sqInt firstFree;
    usqInt endOfMemoryLocal;
    sqInt freeChunk;
    sqInt oopHeader;
    sqInt survivors;

	entriesAvailable = fwdTableInit(BytesPerWord * 2);
	survivors = 0;
	freeChunk = null;

	/* will be updated later */

	firstFree = null;
	endOfMemoryLocal = endOfMemory;
	oop = youngStart + (headerTypeBytes[(longAt(youngStart)) & TypeMask]);
	while (oop < endOfMemoryLocal) {

		/* get oop's header, header type, size, and header size */

		statSweepCount += 1;
		oopHeader = longAt(oop);
		oopHeaderType = oopHeader & TypeMask;
		hdrBytes = headerTypeBytes[oopHeaderType];
		if ((oopHeaderType & 1) == 1) {
			oopSize = oopHeader & SizeMask;
		} else {
			if (oopHeaderType == HeaderTypeSizeAndClass) {
				oopSize = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
			} else {

				/* free chunk */

				oopSize = oopHeader & LongSizeMask;
			}
		}
		if ((oopHeader & MarkBit) == 0) {
			longAtput(oop - hdrBytes, HeaderTypeFree);
			if (freeChunk != null) {

				/* enlarge current free chunk to include this oop */

				freeChunkSize = (freeChunkSize + oopSize) + hdrBytes;
			} else {

				/* start a new free chunk */
				/* chunk may start 4 or 8 bytes before oop */

				freeChunk = oop - hdrBytes;

				/* adjust size for possible extra header bytes */

				freeChunkSize = oopSize + (oop - freeChunk);
				if (firstFree == null) {
					firstFree = freeChunk;
				}
			}
		} else {
			longAtput(oop, oopHeader & AllButMarkBit);
			if (((((usqInt) (longAt(oop))) >> 8) & 15) == 4) {
				finalizeReference(oop);
			}
			if (entriesAvailable > 0) {
				entriesAvailable -= 1;
			} else {

				/* start compaction at the last free chunk before this object */

				firstFree = freeChunk;
			}
			if (freeChunk != null) {
				longAtput(freeChunk, (freeChunkSize & LongSizeMask) | HeaderTypeFree);
				freeChunk = null;
			}
			survivors += 1;
		}
		oop = (oop + oopSize) + (headerTypeBytes[(longAt(oop + oopSize)) & TypeMask]);
	}
	if (freeChunk != null) {
		longAtput(freeChunk, (freeChunkSize & LongSizeMask) | HeaderTypeFree);
	}
	if (!(oop == endOfMemory)) {
		error("sweep failed to find exact end of memory");
	}
	if (firstFree == null) {
		error("expected to find at least one free object");
	} else {
		compStart = firstFree;
	}
	return survivors;
}


/*	Signal the given semaphore from within the interpreter. */

sqInt synchronousSignal(sqInt aSemaphore) {
    sqInt excessSignals;

	if ((longAt((aSemaphore + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord))) == nilObj) {

		/* no process is waiting on this semaphore */

		excessSignals = fetchIntegerofObject(ExcessSignalsIndex, aSemaphore);
		/* begin storeInteger:ofObject:withValue: */
		if (
# ifdef SQ_HOST32  // cast to int for 64 bit image on 32 bit host
			(((((int) (excessSignals + 1))) ^ ((((int) (excessSignals + 1))) << 1)) >= 0)
# else
			(((excessSignals + 1) >= -1073741824) && ((excessSignals + 1) <= 1073741823))
# endif  // SQ_HOST32
		) {
			longAtput((aSemaphore + BaseHeaderSize) + (ExcessSignalsIndex << ShiftForWord), (((excessSignals + 1) << 1) | 1));
		} else {
			/* begin primitiveFail */
			successFlag = 0;
		}
	} else {
		resume(removeFirstLinkOfList(aSemaphore));
	}
}


/*	Record a process to be awoken on the next interpreter cycle. 
	ikp 11/24/1999 06:07 -- added hook for external runtime 
	compiler  */

sqInt transferTo(sqInt aProc) {
    sqInt sched;
    sqInt oldProc;
    sqInt newProc;
    sqInt valuePointer;
    sqInt tmp;
    sqInt valuePointer1;

	if (aProc == null) {
		longjmp(jmpBufExit, 1);
	}
	newProc = aProc;
	sched = longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord));
	oldProc = longAt((sched + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord));
	/* begin storePointer:ofObject:withValue: */
	if ((((usqInt) sched)) < (((usqInt) youngStart))) {
		possibleRootStoreIntovalue(sched, newProc);
	}
	longAtput((sched + BaseHeaderSize) + (ActiveProcessIndex << ShiftForWord), newProc);
	if (compilerInitialized) {
		compilerProcessChangeto(oldProc, newProc);
	} else {
		/* begin storePointer:ofObject:withValue: */
		valuePointer = activeContext;
		if ((((usqInt) oldProc)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(oldProc, valuePointer);
		}
		longAtput((oldProc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord), valuePointer);
		/* begin newActiveContext: */
		/* begin storeContextRegisters: */
		longAtput((activeContext + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord), ((((instructionPointer - method) - (BaseHeaderSize - 2)) << 1) | 1));
		longAtput((activeContext + BaseHeaderSize) + (StackPointerIndex << ShiftForWord), (((((((usqInt) ((stackPointer - activeContext) - BaseHeaderSize)) >> ShiftForWord) - TempFrameStart) + 1) << 1) | 1));
		if ((((usqInt) (longAt((newProc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord))))) < (((usqInt) youngStart))) {
			beRootIfOld(longAt((newProc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord)));
		}
		activeContext = longAt((newProc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord));
		/* begin fetchContextRegisters: */
		tmp = longAt(((longAt((newProc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord))) + BaseHeaderSize) + (MethodIndex << ShiftForWord));
		if ((tmp & 1)) {
			tmp = longAt(((longAt((newProc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord))) + BaseHeaderSize) + (HomeIndex << ShiftForWord));
			if ((((usqInt) tmp)) < (((usqInt) youngStart))) {
				beRootIfOld(tmp);
			}
		} else {
			tmp = longAt((newProc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord));
		}
		theHomeContext = tmp;
		receiver = longAt((tmp + BaseHeaderSize) + (ReceiverIndex << ShiftForWord));
		method = longAt((tmp + BaseHeaderSize) + (MethodIndex << ShiftForWord));
		tmp = ((longAt(((longAt((newProc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord))) + BaseHeaderSize) + (InstructionPointerIndex << ShiftForWord))) >> 1);
		instructionPointer = ((method + tmp) + BaseHeaderSize) - 2;
		tmp = ((longAt(((longAt((newProc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord))) + BaseHeaderSize) + (StackPointerIndex << ShiftForWord))) >> 1);
		stackPointer = ((longAt((newProc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord))) + BaseHeaderSize) + (((TempFrameStart + tmp) - 1) * BytesPerWord);
		/* begin storePointer:ofObject:withValue: */
		valuePointer1 = nilObj;
		if ((((usqInt) newProc)) < (((usqInt) youngStart))) {
			possibleRootStoreIntovalue(newProc, valuePointer1);
		}
		longAtput((newProc + BaseHeaderSize) + (SuspendedContextIndex << ShiftForWord), valuePointer1);
	}
	reclaimableContextCount = 0;
}

sqInt trueObject(void) {
	return trueObj;
}


/*	update pointers in the given memory range */

sqInt updatePointersInRangeFromto(sqInt memStart, sqInt memEnd) {
    sqInt oop;
    sqInt newOop;
    sqInt fieldOffset;
    sqInt fwdBlock;
    sqInt fieldOop;
    sqInt classHeader;
    sqInt newClassHeader;
    sqInt fwdBlock1;
    sqInt newClassOop;
    sqInt classOop;
    sqInt header;
    sqInt fwdBlock2;
    sqInt header1;
    sqInt header2;
    sqInt header3;
    sqInt fwdBlock3;
    sqInt header11;
    sqInt header21;
    sqInt size;
    sqInt header4;
    sqInt fwdBlock4;
    sqInt contextSize;
    sqInt fmt;
    sqInt methodHeader;
    sqInt sp;
    sqInt sz;
    sqInt header5;
    sqInt fwdBlock5;
    sqInt realHeader;
    sqInt sz1;
    sqInt header12;

	oop = memStart + (headerTypeBytes[(longAt(memStart)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) memEnd))) {
		if (!(((longAt(oop)) & TypeMask) == HeaderTypeFree)) {
			/* begin remapFieldsAndClassOf: */
			/* begin lastPointerWhileForwarding: */
			header4 = longAt(oop);
			if ((header4 & MarkBit) != 0) {
				fwdBlock4 = (header4 & AllButMarkBitAndTypeMask) << 1;
				if (DoAssertionChecks) {
					/* begin fwdBlockValidate: */
					if (!(((((usqInt) fwdBlock4)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock4)) <= (((usqInt) fwdTableNext))) && ((fwdBlock4 & 3) == 0)))) {
						error("invalid fwd table entry");
					}
				}
				header4 = longAt(fwdBlock4 + BytesPerWord);
			}
			fmt = (((usqInt) header4) >> 8) & 15;
			if (fmt <= 4) {
				if ((fmt == 3) && ((((((usqInt) header4) >> 12) & 31) == 13) || ((((((usqInt) header4) >> 12) & 31) == 14) || (((((usqInt) header4) >> 12) & 31) == 4)))) {
					/* begin fetchStackPointerOf: */
					sp = longAt((oop + BaseHeaderSize) + (StackPointerIndex << ShiftForWord));
					if (!((sp & 1))) {
						contextSize = 0;
						goto l2;
					}
					contextSize = (sp >> 1);
				l2:	/* end fetchStackPointerOf: */;
					fieldOffset = (CtxtTempFrameStart + contextSize) * BytesPerWord;
					goto l3;
				}
				if ((header4 & TypeMask) == HeaderTypeSizeAndClass) {
					size = (longAt(oop - (BytesPerWord * 2))) & AllButTypeMask;
				} else {
					size = header4 & SizeMask;
				}
				fieldOffset = size - BaseHeaderSize;
				goto l3;
			}
			if (fmt < 12) {
				fieldOffset = 0;
				goto l3;
			}
			methodHeader = longAt(oop + BaseHeaderSize);
			fieldOffset = (((((usqInt) methodHeader) >> 10) & 255) * BytesPerWord) + BaseHeaderSize;
		l3:	/* end lastPointerWhileForwarding: */;
			while (fieldOffset >= BaseHeaderSize) {
				fieldOop = longAt(oop + fieldOffset);
				if (((fieldOop & 1) == 0) && (((longAt(fieldOop)) & MarkBit) != 0)) {
					fwdBlock = ((longAt(fieldOop)) & AllButMarkBitAndTypeMask) << 1;
					if (DoAssertionChecks) {
						/* begin fwdBlockValidate: */
						if (!(((((usqInt) fwdBlock)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock)) <= (((usqInt) fwdTableNext))) && ((fwdBlock & 3) == 0)))) {
							error("invalid fwd table entry");
						}
					}
					newOop = longAt(fwdBlock);
					longAtput(oop + fieldOffset, newOop);
					if (((((usqInt) oop)) < (((usqInt) youngStart))) && ((((usqInt) newOop)) >= (((usqInt) youngStart)))) {
						/* begin beRootWhileForwarding: */
						header = longAt(oop);
						if ((header & MarkBit) != 0) {
							fwdBlock2 = (header & AllButMarkBitAndTypeMask) << 1;
							if (DoAssertionChecks) {
								/* begin fwdBlockValidate: */
								if (!(((((usqInt) fwdBlock2)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock2)) <= (((usqInt) fwdTableNext))) && ((fwdBlock2 & 3) == 0)))) {
									error("invalid fwd table entry");
								}
							}
							/* begin noteAsRoot:headerLoc: */
							header1 = longAt(fwdBlock2 + BytesPerWord);
							if ((header1 & RootBit) == 0) {
								if (rootTableCount < RootTableRedZone) {
									rootTableCount += 1;
									rootTable[rootTableCount] = oop;
									longAtput(fwdBlock2 + BytesPerWord, header1 | RootBit);
								} else {
									if (rootTableCount < RootTableSize) {
										rootTableCount += 1;
										rootTable[rootTableCount] = oop;
										longAtput(fwdBlock2 + BytesPerWord, header1 | RootBit);
										allocationCount = allocationsBetweenGCs + 1;
									}
								}
							}
						} else {
							/* begin noteAsRoot:headerLoc: */
							header2 = longAt(oop);
							if ((header2 & RootBit) == 0) {
								if (rootTableCount < RootTableRedZone) {
									rootTableCount += 1;
									rootTable[rootTableCount] = oop;
									longAtput(oop, header2 | RootBit);
								} else {
									if (rootTableCount < RootTableSize) {
										rootTableCount += 1;
										rootTable[rootTableCount] = oop;
										longAtput(oop, header2 | RootBit);
										allocationCount = allocationsBetweenGCs + 1;
									}
								}
							}
						}
					}
				}
				fieldOffset -= BytesPerWord;
			}
			/* begin remapClassOf: */
			if (((longAt(oop)) & TypeMask) == HeaderTypeShort) {
				goto l1;
			}
			classHeader = longAt(oop - BytesPerWord);
			classOop = classHeader & AllButTypeMask;
			if (((classOop & 1) == 0) && (((longAt(classOop)) & MarkBit) != 0)) {
				fwdBlock1 = ((longAt(classOop)) & AllButMarkBitAndTypeMask) << 1;
				if (DoAssertionChecks) {
					/* begin fwdBlockValidate: */
					if (!(((((usqInt) fwdBlock1)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock1)) <= (((usqInt) fwdTableNext))) && ((fwdBlock1 & 3) == 0)))) {
						error("invalid fwd table entry");
					}
				}
				newClassOop = longAt(fwdBlock1);
				newClassHeader = newClassOop | (classHeader & TypeMask);
				longAtput(oop - BytesPerWord, newClassHeader);
				if (((((usqInt) oop)) < (((usqInt) youngStart))) && ((((usqInt) newClassOop)) >= (((usqInt) youngStart)))) {
					/* begin beRootWhileForwarding: */
					header3 = longAt(oop);
					if ((header3 & MarkBit) != 0) {
						fwdBlock3 = (header3 & AllButMarkBitAndTypeMask) << 1;
						if (DoAssertionChecks) {
							/* begin fwdBlockValidate: */
							if (!(((((usqInt) fwdBlock3)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock3)) <= (((usqInt) fwdTableNext))) && ((fwdBlock3 & 3) == 0)))) {
								error("invalid fwd table entry");
							}
						}
						/* begin noteAsRoot:headerLoc: */
						header11 = longAt(fwdBlock3 + BytesPerWord);
						if ((header11 & RootBit) == 0) {
							if (rootTableCount < RootTableRedZone) {
								rootTableCount += 1;
								rootTable[rootTableCount] = oop;
								longAtput(fwdBlock3 + BytesPerWord, header11 | RootBit);
							} else {
								if (rootTableCount < RootTableSize) {
									rootTableCount += 1;
									rootTable[rootTableCount] = oop;
									longAtput(fwdBlock3 + BytesPerWord, header11 | RootBit);
									allocationCount = allocationsBetweenGCs + 1;
								}
							}
						}
					} else {
						/* begin noteAsRoot:headerLoc: */
						header21 = longAt(oop);
						if ((header21 & RootBit) == 0) {
							if (rootTableCount < RootTableRedZone) {
								rootTableCount += 1;
								rootTable[rootTableCount] = oop;
								longAtput(oop, header21 | RootBit);
							} else {
								if (rootTableCount < RootTableSize) {
									rootTableCount += 1;
									rootTable[rootTableCount] = oop;
									longAtput(oop, header21 | RootBit);
									allocationCount = allocationsBetweenGCs + 1;
								}
							}
						}
					}
				}
			}
		l1:	/* end remapClassOf: */;
		}
		/* begin objectAfterWhileForwarding: */
		header5 = longAt(oop);
		if ((header5 & MarkBit) == 0) {
			/* begin objectAfter: */
			if (DoAssertionChecks) {
				if ((((usqInt) oop)) >= (((usqInt) endOfMemory))) {
					error("no objects after the end of memory");
				}
			}
			if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
				sz1 = (longAt(oop)) & AllButTypeMask;
			} else {
				/* begin sizeBitsOf: */
				header12 = longAt(oop);
				if ((header12 & TypeMask) == HeaderTypeSizeAndClass) {
					sz1 = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
					goto l4;
				} else {
					sz1 = header12 & SizeMask;
					goto l4;
				}
			l4:	/* end sizeBitsOf: */;
			}
			oop = (oop + sz1) + (headerTypeBytes[(longAt(oop + sz1)) & TypeMask]);
			goto l5;
		}
		fwdBlock5 = (header5 & AllButMarkBitAndTypeMask) << 1;
		if (DoAssertionChecks) {
			/* begin fwdBlockValidate: */
			if (!(((((usqInt) fwdBlock5)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock5)) <= (((usqInt) fwdTableNext))) && ((fwdBlock5 & 3) == 0)))) {
				error("invalid fwd table entry");
			}
		}
		realHeader = longAt(fwdBlock5 + BytesPerWord);
		if ((realHeader & TypeMask) == HeaderTypeSizeAndClass) {
			sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
		} else {
			sz = realHeader & SizeMask;
		}
		oop = (oop + sz) + (headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	l5:	/* end objectAfterWhileForwarding: */;
	}
}


/*	update pointers in root objects */

sqInt updatePointersInRootObjectsFromto(sqInt memStart, sqInt memEnd) {
    sqInt oop;
    sqInt i;
    sqInt newOop;
    sqInt fieldOffset;
    sqInt fwdBlock;
    sqInt fieldOop;
    sqInt header;
    sqInt fwdBlock1;
    sqInt header1;
    sqInt header2;
    sqInt classHeader;
    sqInt newClassHeader;
    sqInt fwdBlock2;
    sqInt newClassOop;
    sqInt classOop;
    sqInt header3;
    sqInt fwdBlock3;
    sqInt header11;
    sqInt header21;
    sqInt size;
    sqInt header4;
    sqInt fwdBlock4;
    sqInt contextSize;
    sqInt fmt;
    sqInt methodHeader;
    sqInt sp;

	for (i = 1; i <= rootTableCount; i += 1) {
		oop = rootTable[i];
		if (((((usqInt) oop)) < (((usqInt) memStart))) || ((((usqInt) oop)) >= (((usqInt) memEnd)))) {
			/* begin remapFieldsAndClassOf: */
			/* begin lastPointerWhileForwarding: */
			header4 = longAt(oop);
			if ((header4 & MarkBit) != 0) {
				fwdBlock4 = (header4 & AllButMarkBitAndTypeMask) << 1;
				if (DoAssertionChecks) {
					/* begin fwdBlockValidate: */
					if (!(((((usqInt) fwdBlock4)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock4)) <= (((usqInt) fwdTableNext))) && ((fwdBlock4 & 3) == 0)))) {
						error("invalid fwd table entry");
					}
				}
				header4 = longAt(fwdBlock4 + BytesPerWord);
			}
			fmt = (((usqInt) header4) >> 8) & 15;
			if (fmt <= 4) {
				if ((fmt == 3) && ((((((usqInt) header4) >> 12) & 31) == 13) || ((((((usqInt) header4) >> 12) & 31) == 14) || (((((usqInt) header4) >> 12) & 31) == 4)))) {
					/* begin fetchStackPointerOf: */
					sp = longAt((oop + BaseHeaderSize) + (StackPointerIndex << ShiftForWord));
					if (!((sp & 1))) {
						contextSize = 0;
						goto l2;
					}
					contextSize = (sp >> 1);
				l2:	/* end fetchStackPointerOf: */;
					fieldOffset = (CtxtTempFrameStart + contextSize) * BytesPerWord;
					goto l3;
				}
				if ((header4 & TypeMask) == HeaderTypeSizeAndClass) {
					size = (longAt(oop - (BytesPerWord * 2))) & AllButTypeMask;
				} else {
					size = header4 & SizeMask;
				}
				fieldOffset = size - BaseHeaderSize;
				goto l3;
			}
			if (fmt < 12) {
				fieldOffset = 0;
				goto l3;
			}
			methodHeader = longAt(oop + BaseHeaderSize);
			fieldOffset = (((((usqInt) methodHeader) >> 10) & 255) * BytesPerWord) + BaseHeaderSize;
		l3:	/* end lastPointerWhileForwarding: */;
			while (fieldOffset >= BaseHeaderSize) {
				fieldOop = longAt(oop + fieldOffset);
				if (((fieldOop & 1) == 0) && (((longAt(fieldOop)) & MarkBit) != 0)) {
					fwdBlock = ((longAt(fieldOop)) & AllButMarkBitAndTypeMask) << 1;
					if (DoAssertionChecks) {
						/* begin fwdBlockValidate: */
						if (!(((((usqInt) fwdBlock)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock)) <= (((usqInt) fwdTableNext))) && ((fwdBlock & 3) == 0)))) {
							error("invalid fwd table entry");
						}
					}
					newOop = longAt(fwdBlock);
					longAtput(oop + fieldOffset, newOop);
					if (((((usqInt) oop)) < (((usqInt) youngStart))) && ((((usqInt) newOop)) >= (((usqInt) youngStart)))) {
						/* begin beRootWhileForwarding: */
						header = longAt(oop);
						if ((header & MarkBit) != 0) {
							fwdBlock1 = (header & AllButMarkBitAndTypeMask) << 1;
							if (DoAssertionChecks) {
								/* begin fwdBlockValidate: */
								if (!(((((usqInt) fwdBlock1)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock1)) <= (((usqInt) fwdTableNext))) && ((fwdBlock1 & 3) == 0)))) {
									error("invalid fwd table entry");
								}
							}
							/* begin noteAsRoot:headerLoc: */
							header1 = longAt(fwdBlock1 + BytesPerWord);
							if ((header1 & RootBit) == 0) {
								if (rootTableCount < RootTableRedZone) {
									rootTableCount += 1;
									rootTable[rootTableCount] = oop;
									longAtput(fwdBlock1 + BytesPerWord, header1 | RootBit);
								} else {
									if (rootTableCount < RootTableSize) {
										rootTableCount += 1;
										rootTable[rootTableCount] = oop;
										longAtput(fwdBlock1 + BytesPerWord, header1 | RootBit);
										allocationCount = allocationsBetweenGCs + 1;
									}
								}
							}
						} else {
							/* begin noteAsRoot:headerLoc: */
							header2 = longAt(oop);
							if ((header2 & RootBit) == 0) {
								if (rootTableCount < RootTableRedZone) {
									rootTableCount += 1;
									rootTable[rootTableCount] = oop;
									longAtput(oop, header2 | RootBit);
								} else {
									if (rootTableCount < RootTableSize) {
										rootTableCount += 1;
										rootTable[rootTableCount] = oop;
										longAtput(oop, header2 | RootBit);
										allocationCount = allocationsBetweenGCs + 1;
									}
								}
							}
						}
					}
				}
				fieldOffset -= BytesPerWord;
			}
			/* begin remapClassOf: */
			if (((longAt(oop)) & TypeMask) == HeaderTypeShort) {
				goto l1;
			}
			classHeader = longAt(oop - BytesPerWord);
			classOop = classHeader & AllButTypeMask;
			if (((classOop & 1) == 0) && (((longAt(classOop)) & MarkBit) != 0)) {
				fwdBlock2 = ((longAt(classOop)) & AllButMarkBitAndTypeMask) << 1;
				if (DoAssertionChecks) {
					/* begin fwdBlockValidate: */
					if (!(((((usqInt) fwdBlock2)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock2)) <= (((usqInt) fwdTableNext))) && ((fwdBlock2 & 3) == 0)))) {
						error("invalid fwd table entry");
					}
				}
				newClassOop = longAt(fwdBlock2);
				newClassHeader = newClassOop | (classHeader & TypeMask);
				longAtput(oop - BytesPerWord, newClassHeader);
				if (((((usqInt) oop)) < (((usqInt) youngStart))) && ((((usqInt) newClassOop)) >= (((usqInt) youngStart)))) {
					/* begin beRootWhileForwarding: */
					header3 = longAt(oop);
					if ((header3 & MarkBit) != 0) {
						fwdBlock3 = (header3 & AllButMarkBitAndTypeMask) << 1;
						if (DoAssertionChecks) {
							/* begin fwdBlockValidate: */
							if (!(((((usqInt) fwdBlock3)) > (((usqInt) endOfMemory))) && (((((usqInt) fwdBlock3)) <= (((usqInt) fwdTableNext))) && ((fwdBlock3 & 3) == 0)))) {
								error("invalid fwd table entry");
							}
						}
						/* begin noteAsRoot:headerLoc: */
						header11 = longAt(fwdBlock3 + BytesPerWord);
						if ((header11 & RootBit) == 0) {
							if (rootTableCount < RootTableRedZone) {
								rootTableCount += 1;
								rootTable[rootTableCount] = oop;
								longAtput(fwdBlock3 + BytesPerWord, header11 | RootBit);
							} else {
								if (rootTableCount < RootTableSize) {
									rootTableCount += 1;
									rootTable[rootTableCount] = oop;
									longAtput(fwdBlock3 + BytesPerWord, header11 | RootBit);
									allocationCount = allocationsBetweenGCs + 1;
								}
							}
						}
					} else {
						/* begin noteAsRoot:headerLoc: */
						header21 = longAt(oop);
						if ((header21 & RootBit) == 0) {
							if (rootTableCount < RootTableRedZone) {
								rootTableCount += 1;
								rootTable[rootTableCount] = oop;
								longAtput(oop, header21 | RootBit);
							} else {
								if (rootTableCount < RootTableSize) {
									rootTableCount += 1;
									rootTable[rootTableCount] = oop;
									longAtput(oop, header21 | RootBit);
									allocationCount = allocationsBetweenGCs + 1;
								}
							}
						}
					}
				}
			}
		l1:	/* end remapClassOf: */;
		}
	}
}


/*	Verify that every old object that points to a new object 
		has its root bit set, and
		appears in the rootTable.
	This method should not be called if the rootTable is full, because roots
	are no longer recorded, and incremental collections are not attempted.
	If DoAssertionChecks is true, this routine will halt on an unmarked root.
	Otherwise, this routine will merely return true in that case. */

sqInt validateRoots(void) {
    usqInt fieldAddr;
    usqInt oop;
    sqInt header;
    usqInt fieldOop;
    sqInt badRoot;
    sqInt sz;
    sqInt header1;

	badRoot = 0;
	oop = memory + (headerTypeBytes[(longAt(memory)) & TypeMask]);
	while (oop < youngStart) {
		if (!(((longAt(oop)) & TypeMask) == HeaderTypeFree)) {
			fieldAddr = oop + (lastPointerOf(oop));
			while (fieldAddr > oop) {
				fieldOop = longAt(fieldAddr);
				if ((fieldOop >= youngStart) && (!((fieldOop & 1)))) {

					/* fieldOop is a pointer to a young object */

					header = longAt(oop);
					if ((header & RootBit) == 0) {
						if (DoAssertionChecks) {
							error("root bit not set");
						}
						badRoot = 1;
					} else {
						null;
					}
				}
				fieldAddr -= BytesPerWord;
			}
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) oop)) >= (((usqInt) endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(oop)) & AllButTypeMask;
		} else {
			/* begin sizeBitsOf: */
			header1 = longAt(oop);
			if ((header1 & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
				goto l1;
			} else {
				sz = header1 & SizeMask;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		oop = (oop + sz) + (headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	}
	return badRoot;
}

sqInt verifyCleanHeaders(void) {
    sqInt oop;
    sqInt sz;
    sqInt header;

	oop = memory + (headerTypeBytes[(longAt(memory)) & TypeMask]);
	while ((((usqInt) oop)) < (((usqInt) endOfMemory))) {
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			if (!((objectAfter(oop)) == endOfMemory)) {
				error("Invalid obj with HeaderTypeBits = Free.");
			}
		} else {
			if (!(((longAt(oop)) & MarkBit) == 0)) {
				error("Invalid obj with MarkBit set.");
			}
		}
		/* begin objectAfter: */
		if (DoAssertionChecks) {
			if ((((usqInt) oop)) >= (((usqInt) endOfMemory))) {
				error("no objects after the end of memory");
			}
		}
		if (((longAt(oop)) & TypeMask) == HeaderTypeFree) {
			sz = (longAt(oop)) & AllButTypeMask;
		} else {
			/* begin sizeBitsOf: */
			header = longAt(oop);
			if ((header & TypeMask) == HeaderTypeSizeAndClass) {
				sz = (longAt(oop - (BytesPerWord * 2))) & LongSizeMask;
				goto l1;
			} else {
				sz = header & SizeMask;
				goto l1;
			}
		l1:	/* end sizeBitsOf: */;
		}
		oop = (oop + sz) + (headerTypeBytes[(longAt(oop + sz)) & TypeMask]);
	}
}


/*	return 0 for little endian, 1 for big endian */

sqInt vmEndianness(void) {
	if (isBigEnder()) {
		return 1;
	} else {
		return 0;
	}
}


/*	Return the highest priority process that is ready to run. */
/*	Note: It is a fatal VM error if there is no runnable process. */

sqInt wakeHighestPriority(void) {
    sqInt p;
    sqInt schedLists;
    sqInt processList;
    sqInt sz;
    sqInt header;

	schedLists = longAt(((longAt(((longAt((specialObjectsOop + BaseHeaderSize) + (SchedulerAssociation << ShiftForWord))) + BaseHeaderSize) + (ValueIndex << ShiftForWord))) + BaseHeaderSize) + (ProcessListsIndex << ShiftForWord));
	/* begin fetchWordLengthOf: */
	/* begin sizeBitsOf: */
	header = longAt(schedLists);
	if ((header & TypeMask) == HeaderTypeSizeAndClass) {
		sz = (longAt(schedLists - (BytesPerWord * 2))) & LongSizeMask;
		goto l1;
	} else {
		sz = header & SizeMask;
		goto l1;
	}
l1:	/* end sizeBitsOf: */;
	p = ((usqInt) (sz - BaseHeaderSize)) >> ShiftForWord;

	/* index of last indexable field */

	p -= 1;
	processList = longAt((schedLists + BaseHeaderSize) + (p << ShiftForWord));
	while ((longAt((processList + BaseHeaderSize) + (FirstLinkIndex << ShiftForWord))) == nilObj) {
		p -= 1;
		if (p < 0) {
			return null;
		}
		processList = longAt((schedLists + BaseHeaderSize) + (p << ShiftForWord));
	}
	return removeFirstLinkOfList(processList);
}


/*	Return the given 64-bit integer with its halves in the reverse order. */

sqInt wordSwapped(sqInt w) {
	if (!(BytesPerWord == 8)) {
		error("This cannot happen.");
	}
	return ((((usqInt) w << 0)) & Bytes3to0Mask) + ((((usqInt) w << 0)) & Bytes7to4Mask);
}

sqInt writeImageFile(sqInt imageBytes) {
    void * fn;

	writeImageFileIO(imageBytes);
	fn = ioLoadFunctionFrom("setMacFileTypeAndCreator", "FilePlugin");
	if (!(fn == 0)) {
		((sqInt (*)(char*, char*, char*))fn)(imageName, "STim", "FAST");
	}
}

sqInt writeImageFileIO(sqInt imageBytes) {
    sqInt headerSize;
    sqInt i;
    void * sCWIfn;
    squeakFileOffsetType  headerStart;
    size_t bytesWritten;
    sqInt okToWrite;
    sqImageFile f;
    char * memoryAddress;

	sCWIfn = ioLoadFunctionFrom("secCanWriteImage", "SecurityPlugin");
	if (sCWIfn != 0) {
		okToWrite = ((sqInt (*)(void))sCWIfn)();
		if (!(okToWrite)) {
			/* begin primitiveFail */
			successFlag = 0;
			return null;
		}
	}
	headerStart = 0;

	/* header size in bytes; do not change! */

	headerSize = 64;
	f = sqImageFileOpen(imageName, "wb");
	if (f == null) {
		/* begin success: */
		successFlag = 0 && successFlag;
		return null;
	}
	headerStart = sqImageFileStartLocation(f,imageName,headerSize+imageBytes);
	/* Note: on Unix systems one could put an exec command here, padded to 512 bytes */;
	sqImageFileSeek(f, headerStart);
	putLongtoFile(imageFormatVersionNumber, f);
	putLongtoFile(headerSize, f);
	putLongtoFile(imageBytes, f);
	putLongtoFile(memory, f);
	putLongtoFile(specialObjectsOop, f);
	putLongtoFile(lastHash, f);
	putLongtoFile(ioScreenSize(), f);
	putLongtoFile(fullScreenFlag, f);
	putLongtoFile(extraVMMemory, f);
	for (i = 1; i <= 7; i += 1) {
		putLongtoFile(0, f);
	}
	if (!(successFlag)) {
		sqImageFileClose(f);
		return null;
	}
	sqImageFileSeek(f, headerStart + headerSize);
	/* begin sqImage:write:size:length: */
	memoryAddress = pointerForOop(memory);
	bytesWritten = sqImageFileWrite(memoryAddress, sizeof(unsigned char), imageBytes, f);
	/* begin success: */
	successFlag = (bytesWritten == imageBytes) && successFlag;
	sqImageFileClose(f);
}


void* vm_exports[][3] = {
	{"", "primitiveSetGCBiasToGrowGCLimit", (void*)primitiveSetGCBiasToGrowGCLimit},
	{"", "primitiveForceTenure", (void*)primitiveForceTenure},
	{"", "primitiveScreenDepth", (void*)primitiveScreenDepth},
	{"", "dumpImage", (void*)dumpImage},
	{"", "addGCRoot", (void*)addGCRoot},
	{"", "primitiveIsYoung", (void*)primitiveIsYoung},
	{"", "callInterpreter", (void*)callInterpreter},
	{"", "primitiveSetGCBiasToGrow", (void*)primitiveSetGCBiasToGrow},
	{"", "callbackEnter", (void*)callbackEnter},
	{"", "primitiveChangeClassWithClass", (void*)primitiveChangeClassWithClass},
	{"", "primitiveIsEventVM", (void*)primitiveIsEventVM},
	{"", "primitiveRootTable", (void*)primitiveRootTable},
	{"", "prepareActiveProcess", (void*)prepareActiveProcess},
	{"", "callbackLeave", (void*)callbackLeave},
	{"", "removeGCRoot", (void*)removeGCRoot},
	{"", "primitiveIsRoot", (void*)primitiveIsRoot},
	{"", "primitiveSetGCSemaphore", (void*)primitiveSetGCSemaphore},
	{"", "primitiveDoDialog", (void*)primitiveDoDialog},
	{"", "primitiveDisablePowerManager", (void*)primitiveDisablePowerManager},
	{"", "moduleUnloaded", (void*)moduleUnloaded},
	{"", "primitiveRootTableAt", (void*)primitiveRootTableAt},
	{NULL, NULL, NULL}
};
