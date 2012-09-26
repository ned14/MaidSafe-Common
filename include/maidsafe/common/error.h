/*******************************************************************************
 *  Copyright 2012 maidsafe.net limited                                        *
 *                                                                             *
 *  The following source code is property of maidsafe.net limited and is not   *
 *  meant for external use.  The use of this code is governed by the licence   *
 *  file licence.txt found in the root of this directory and also on           *
 *  www.maidsafe.net.                                                          *
 *                                                                             *
 *  You are not free to copy, amend or otherwise use this source code without  *
 *  the explicit written permission of the board of directors of maidsafe.net. *
 ******************************************************************************/

#ifndef MAIDSAFE_COMMON_ERROR_H_
#define MAIDSAFE_COMMON_ERROR_H_

#ifdef MAIDSAFE_WIN32
#  define MAIDSAFE_NOEXCEPT
#else
#  define MAIDSAFE_NOEXCEPT noexcept(true)
#endif

#include <system_error>
#include <string>

namespace maidsafe {

enum class error_code {
  kOK = 0,
  kBadStringLength,  // 0 would be no error
  kInvalidNodeId,
  kNullPointer,
  kIncorrectKeySize,
  kUndefined,
  kPendingResult,
  kPending,
  //Authentication
  kAuthenticationError,
  kPasswordFailure,
  kUserDoesntExist,
  kUserExists,
  kPublicUsernameExists,
  kPublicUsernameAlreadySet,
  kFailedToDeleteOldPacket,
  kBadPacket,
  //BufferPacketHandler
  kBPError,
  kBPSerialiseError,
  kBPInfoSerialiseError,
  kBPParseError,
  kBPInfoParseError,
  kStoreNewBPError,
  kModifyBPError,
  kBPAddUserError,
  kBPStoreAddedUserError,
  kBPDeleteUserError,
  kBPStoreDeletedUserError,
  kBPRetrievalError,
  kBPMessagesRetrievalError,
  kGetBPInfoError,
  kBPAddMessageError,
  kBPAwaitingCallback,
  kBPGetPresenceError,
  kBPAddPresenceError,
  //Chunkstore
  kInvalidChunkType,
  kChunkstoreError,
  kChunkFileDoesntExist,
  kErrorReadingChunkFile,
  kChunkstoreUninitialised,
  kChunkstoreFailedStore,
  kChunkstoreFailedDelete,
  kChunkstoreException,
  kHashCheckFailure,
  kChunkExistsInChunkstore,
  //ClientController
  kClientControllerError,
  kClientControllerNotInitialised,
  //DataAtlasHandler
  kDataAtlasError,
  kDBDoesntExist,
  kDBOpenException,
  kDBCreateException,
  kDBReadWriteException,
  kDBCloseException,
  kDBCantFindFile,
  kDBCantFindDirKey,
  kParseDataMapError,
  kAddElementError,
  kModifyElementError,
  kRemoveElementError,
  kRenameElementError,
  kCopyElementError,
  kDataAtlasException,
  //StoreManagers
  kStoreManagerError,
  kStoreManagerInitError,
  kNotConnected,
  kLoadChunkFindNodesFailure,
  kStoreChunkFindNodesFailure,
  kStoreChunkError,
  kChunkNotInChunkstore,
  kGetRequestSigError,
  kGetStorePeerError,
  kSendPrepResponseUninitialised,
  kSendPrepPeerError,
  kSendPrepSignedSizeAltered,
  kSendPrepFailure,
  kSendPrepInvalidId,
  kSendPrepInvalidResponseSignature,
  kSendPrepInvalidContractSignature,
  kSendContentFailure,
  kSendChunkFailure,
  kTaskCancelledOffline,
  kFindNodesError,
  kFindNodesFailure,
  kFindNodesParseError,
  kFindValueError,
  kFindValueFailure,
  kFindValueParseError,
  kLoadChunkFailure,
  kDeleteChunkFindNodesFailure,
  kDeleteChunkError,
  kDeleteSizeError,
  kDeleteChunkFailure,
  kLoadedChunkEmpty,
  kGetChunkFailure,
  kSendPacketError,
  kSendPacketFailure,
  kSendPacketFindValueFailure,
  kSendPacketCached,
  kSendPacketAlreadyExists,
  kSendPacketUnknownExistsType,
  kSendPacketParseError,
  kDeletePacketFindValueFailure,
  kDeletePacketError,
  kDeletePacketParseError,
  kDeletePacketFailure,
  kLoadPacketCached,
  kLoadPacketFailure,
  kPacketUnknownType,
  kDirUnknownType,
  kStoreManagerException,
  kFindAccountHoldersError,
  kRequestPendingConsensus,
  kRequestFailedConsensus,
  kRequestInsufficientResponses,
  kNoPublicKeyToCheck,
  kInvalidPublicKey,
  kKeyUnique,
  kKeyNotUnique,
  kUpdatePacketFailure,
  kUpdatePacketError,
  kUpdatePacketParseError,
  kChunkStorePending,
  kAmendAccountFailure,
  kModifyChunkFailure,
  //KadOps
  kKadConfigException,
  kKadOpsInitFailure,
  kKadIdError,
  //MessageHandler
  kConnectionNotExists,
  kFailedToConnect,
  kFailedToSend,
  kFailedToStartHandler,
  kHandlerAlreadyStarted,
  kHandlerNotStarted,
  kConnectionAlreadyExists,
  kConnectionDown,
  //Session&FileSystem
  kEmptyConversationId,
  kNonExistentConversation,
  kExistingConversation,
  kLoadKeysFailure,
  kGetKeyFailure,
  kContactListFailure,
  kSessionNameEmpty,
  kFileSystemMountError,
  kFileSystemUnmountError,
  kFuseMountPointError,
  kFileSystemException,
  kAddLiveContactFailure,
  kLiveContactNotFound,
  kLiveContactNoEp,
  //SelfEncryptionHandler(-12000)
  kGeneralEncryptionError,
  kEncryptFileFailure,
  kEncryptStringFailure,
  kEncryptDbFailure,
  kDecryptFileFailure,
  kDecryptStringFailure,
  kDecryptDbFailure,
  kEncryptionLocked,
  kEncryptionLink,
  kEncryptionChunk,
  kEncryptionNotForProcessing,
  kEncryptionUnknownType,
  kEncryptionMDMFailure,
  kEncryptionDAHFailure,
  kEncryptionDMFailure,
  kEncryptionSMFailure,
  kEncryptionSmallInput,
  kEncryptionKeyGenFailure,
  kEncryptionGetDirKeyFailure,
  kEncryptionDbMissing,
  kEncryptionDbException,
  kEncryptionDmNotInMap,
  //StoreManagerTaskHandler
  kStoreManagerTaskHandlerError,
  kStoreManagerTaskIncorrectParameter,
  kStoreManagerTaskIncorrectOperation,
  kStoreManagerTaskParentNotActive,
  kStoreManagerTaskNotFound,
  kStoreManagerTaskCancelledOrDone,
  kStoreManagerTaskConflict,
  //Validator
  kValidatorNoParameters,
  kValidatorNoPrivateKey,
  kInvalidPointer,
  kTimedOut,
  //DataStore
  kEmptyKey,
  kZeroTTL,
  kFailedToModifyKeyValue,
  //RoutingTable
  kOwnIdNotIncludable,
  kFailedToInsertNewContact,
  kFailedToFindContact,
  kFailedToSetPublicKey,
  kFailedToUpdateRankInfo,
  kFailedToSetPreferredEndpoint,
  kFailedToIncrementFailedRpcCount,
  //Node
  kNoOnlineBootstrapContacts,
  kInvalidBootstrapContacts,
  kNotListening,
  kNotJoined,
  kResponseTimeout,
  kResponseCancelled,
  kAnonymousSessionEnded,
  kInvalidDestinationId,
  kEmptyData,
  kTypeNotAllowed,
  kFailedtoSendFindNode,
  kDataSizeNotAllowed,
  kFailedtoGetEndpoint,
  kPartialJoinSessionEnded,
  //DirectoryListing
  kFailedToAddChild,
  kFailedToRemoveChild,
  //DirectoryListingHandler
  kFailedToInitialise,
  kFailedToGetDirectoryData,
  kFailedToAddDirectoryListing,
  kFailedToDeleteDirectoryListing,
  kFailedToRenameDirectoryListing,
  kFailedToCreateDirectory,
  kFailedToSaveParentDirectoryListing,
  kFailedToSaveChanges,
  kFailedToDeleteDirectoryListingNotEmpty,
  kFailedToStoreEncryptedDataMap,
  kFailedToModifyEncryptedDataMap,
  kFailedToDeleteEncryptedDataMap,
  kFailedToDecryptDataMap,
  kFailedToParseShares,
  kNotAuthorised,
  kNestedShareDisallowed,
  kHiddenNotAllowed,
  kFailedToRetrieveData,
  kInvalidDataMap,
  kFailedToGetLock,
  //DriveInUserSpace
  kChildAlreadyExists,
  kFailedToGetChild,
  kFailedChunkStoreInit,
  kCBFSError,
  kCreateStorageError,
  kMountError,
  kFuseFailedToParseCommandLine,
  kFuseFailedToMount,
  kFuseNewFailed,
  kFuseFailedToDaemonise,
  kFuseFailedToSetSignalHandlers,
  kUnmountError,
  kInvalidSelfEncryptor,
  kReadError,
  kWriteError,
  kInvalidSeek,
  kInvalidPath,
  kFailedToGetMetaData,
  kNoDataMap,
  kFailedToSerialiseDataMap,
  kFailedToParseDataMap,
  kNoDirectoryId,
  kInvalidIds,
  kInvalidKey,
  kParentShared,
  kFailedToUpdateShareKeys,
  kFailedToGetShareKeys,
  kNoMsHidden,
  kMsHiddenAlreadyExists,
  kShareAlreadyExistsInHierarchy,
  kDirectoryRecursionException,
  //meta_data_ops
  kSerialisingError,
  kParsingError,
  //Shares
  kFailedToParseShareUsers,
  kFailedToSerialiseShareUsers,
  kShareUserAlreadyExists,
  kFailedToFindShareUser,
  kShareByIdNotFound,
  kNotBootstrapped,
  kFull,
  kInvalidTransport,
  kInvalidConnection,
  kNotConnectable,
  kInvalidEndpoint,
  kTransportStartFailure,
  kEmptyValidationData,
  kConnectError,
  kMessageTooLarge,
  kPingFailed,
  kWontPingAlreadyConnected,
  kWontPingOurself,
  kConnectAttemptAlreadyRunning,
  kOwnId,
  kNoPendingConnectAttempt,
  kBootstrapUpgradeFailure,
  kInvalidParameter,
  kNoBootstrapEndpoints,
  kFailedToGetLocalAddress,

  //Upperlimitofvaluesforthisenum.
  kReturnCodeLimit,
  kGeneralError,
  kUnknownFailure,
  kParseFailure,
  kPreOperationCheckFailure,
  kDuplicateNameFailure,
  kVerifyDataFailure,
  kGetFailure,
  kStoreFailure,
  kDeleteFailure,
  kModifyFailure,
  kInvalidSignedData,
  kSignatureVerificationFailure,
  kNotHashable,
  kNotOwner,
  kFailedToFindChunk,
  kAppendDisallowed,
  kHashFailure,
  kDifferentVersion,
  kChunkNotModified,
  kDataNotPublicKey,
  //DownloadManager
  kManifestFailure,
  kDownloadFailure,
  kNoVersionChange,
  kLocalFailure,
  //Transport
  kListenError,
  kMessageSizeTooLarge,
  kReceiveFailure,
  kReceiveTimeout,
  kSendTimeout,
  kConnectFailure,
  kReadOnlyRestrictedSuccess,
  kRemoteChunkStoreFailure,
  kPublicIdNotFoundFailure,
  kGetPublicIdError,
  //LifeStuffImplandAPI
  kWrongState,
  kWrongLoggedInState,
  kWrongAccessLevel,
  kInitialiseUpdateFunctionFailure,
  kInitialiseBootstrapsFailure,
  kInitialiseChunkStoreFailure,
  kSetSlotsFailure,
  kConnectSignalsFailure,
  kLogoutCredentialsFailure,
  kLogoutCompleteChunkFailure,
  kCreateDirectoryError,
  kMountDriveOnCreationError,
  kCreateMyStuffError,
  kCreateSharedStuffError,
  kMountDriveTryManualUnMount,
  kMountDriveMountPointCreationFailure,
  kMountDriveError,
  kUnMountDriveError,
  kStartMessagesAndContactsNoPublicIds,
  kChangePictureWrongSize,
  kChangePictureWriteHiddenFileFailure,
  kChangePictureEmptyDataMap,
  kChangePictureReconstructionError,
  kSendMessageSizeFailure,
  kAcceptFilePathError,
  kAcceptFileSerialisedIdentifierEmpty,
  kAcceptFileGetFileNameDataFailure,
  kAcceptFileCorruptDatamap,
  kAcceptFileVerifyCreatePathFailure,
  kAcceptFileNameFailure,
  kReadHiddenFileContentFailure,
  kCheckPasswordFailure,
  kVaultCreationCredentialsFailure,
  kVaultCreationStartFailure,
  kNoShareTarget,
  kCouldNotAcquirePmidKeys,
  //AccountLocking
  kLidParseToSignedDataFailure,
  kLidDecryptDataFailure,
  kLidParseToLockingPacketFailure,
  kLidAddItemIdentifierInUse,
  kLidAddItemFullAccessUnavailable,
  kLidRemoveItemIdentifierNotFound,
  kLidRemoveItemsIdentifierNotFound,
  kLidUpdateTimestampIdentifierNotFound,
  kLidCheckOthersIdentifierNotFound,
  kAccountAlreadyLoggedIn,
  kLidNotFound,
  kLidIdentifierFound,
  //Contacts
  kContactInsertionFailure,
  kContactErasureFailure,
  kContactNotPresentFailure,
  kContactReplacementFailure,
  //MessageHander
  kStartMessagesNoPublicIds,
  kPublicIdTimeout,
  kMessageHandlerException,
  kCannotConvertInboxItemToProtobuf,
  kContactInfoContentsFailure,
  //PublicID
  kStartContactsNoPublicIds,
  kGetPublicKeyFailure,
  kContactNotFoundFailure,
  kSigningError,
  kEncryptingError,
  kPublicIdException,
  kSendContactInfoFailure,
  kStorePublicIdFailure,
  kModifyAppendabilityFailure,
  kGenerateNewMMIDFailure,
  kRemoveContactFailure,
  kDeletePublicIdFailure,
  kCannotAddOwnPublicId,
  kCanOnlyRejectPendingResponseContact,
  kConfirmContactGetInfoFailure,
  kConfirmContactInformFailure,
  kConfirmContactStatusFailure,
  kPRWERGetInfoFailure,
  kPRWERPublicKeyFailure,
  kPRWERInformFailure,
  kPRWERStatusFailure,
  //Session
  kTryAgainLater,
  kPublicIdInsertionFailure,
  kParseDataAtlasTmidEmpty,
  kParseDataAtlasTmidDoesNotParse,
  kParseDataAtlasKeyringDoesNotParse,
  kSerialiseDataAtlasKeyringFailure,
  kSerialiseDataAtlasToStringFailure,
  //UserCredentials
  kChangePasswordFailure,
  kLoginUserNonExistence,
  kLoginAccountCorrupted,
  kLoginSessionNotYetSaved,
  kLoginUsingNextToLastSession,
  kMustDieFailure,
  kCorruptedPacket,
  kIdPacketNotFound,
  kTemporaryIdPacketNotFound,
  kSetIdentityPacketsFailure,
  kStoreIdentityPacketsFailure,
  kDeleteIdentityPacketsFailure,
  kCreateSignaturePacketInfoFailure,
  kCreateSignaturePacketsFailure,
  kDeleteSignaturePacketsFailure,
  kSessionFailure,
  kSessionSerialisationFailure,
  kSaveSessionFailure,
  kUsingNextToLastSession,
  //UserStorage
  kOwnerTryingToLeave,
  //Utils
  kWordSizeInvalid,
  kWordPatternInvalid,
  kKeywordSizeInvalid,
  kKeywordPatternInvalid,
  kPinSizeInvalid,
  kPinPatternInvalid,
  kPasswordSizeInvalid,
  kPasswordPatternInvalid,
  kPublicIdEmpty,
  kPublicIdLengthInvalid,
  kPublicIdEndSpaceInvalid,
  kPublicIdDoubleSpaceInvalid,
  kAtLeastOneFailure,
  //CodesremaininginDISABLEDtests.Expectthesecodestoberedundantsoon.
  kReadOnlyFailure,
  kFailedSymmDecrypt,
  //RSAerrorcodes
  kKeyGenerationError,
  kDataEmpty,
  kInvalidPrivateKey,
  kRSAEncryptError,
  kRSADecryptError,
  kRSASigningError,
  kRSAEmptyFileError,
  kRSAInvalidSignature,
  kRSASignatureEmpty,
  kRSASerialisationError,
  kRSAParseError,
};

enum class error_condition {
  kCommon,
  kRudp,
  kRouting,
  kDrive,
  kUnknownError
};

std::error_code make_error_code(error_code code);
std::error_condition make_error_condition(error_condition condition);

class ErrorCategoryImpl : public std::error_category {
 public:
  virtual std::string message(int error_value) const;
  virtual const char* name() const MAIDSAFE_NOEXCEPT;
  virtual std::error_condition default_error_condition(int error_value) const MAIDSAFE_NOEXCEPT;
  virtual bool equivalent(const std::error_code& code, int condition) const MAIDSAFE_NOEXCEPT;
};

const std::error_category& error_category();

}  // namespace maidsafe


namespace std {

#ifdef __GNUC__
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Weffc++"
#endif
template <>
struct is_error_code_enum<maidsafe::error_code> : public true_type {};  //NOLINT (dirvine)

template <>
struct is_error_condition_enum<maidsafe::error_condition> : public true_type {};  //NOLINT (dirvine)
#ifdef __GNUC__
#  pragma GCC diagnostic pop
#endif

}  // namespace std

#endif  // MAIDSAFE_COMMON_ERROR_H_
