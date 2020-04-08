//
//  Configs.h
//  MobileCommon
//
//  Created by Eduardo Burnay on 18/06/14.
//  Copyright (c) 2014 ebankIT. All rights reserved.
//

#import <Foundation/Foundation.h>

//Constants
static NSString * const kMZN = @"EUR";

static CGFloat const kDefaultTableRowHeight = 70.0f;
static CGFloat const kDetailsTableRowHeight = 50.0f;
static CGFloat const kAccountListTableRowHeight = 75.0f;
static CGFloat const kTransitionAnimationDuration = 0.3f;
static CGFloat const kImageCornerRadius = 5.0f;
static CGFloat const kDefaultTabletListRowHeight = 105.0f;
static NSString * const kEmailWithAttachmentDocumentName = @"GenericProof";
static BOOL const encryptCache = YES;

enum {
    TS_IDLE,
    TS_INITIAL,
    TS_RECORDING,
    TS_PROCESSING,
} transactionState;


@interface Configs : NSObject

typedef enum {
    BeaconInformation = 1,
    BeaconAction = 2,
    BeaconWEB = 3
    
    
} BeaconType;

typedef enum {
    
    Cheque_Status_Paid,
    Cheque_Status_Active,
    Cheque_Status_Canceled,
    Cheque_Status_Presented,
    
} ChequeStatus;

typedef enum {
    
    Binding_Enum_None,
    Binding_Enum_Cancel_Cheque_Motive,
    Binding_Enum_Cancel_Debit_Card_Motive,
    Binding_Enum_Returned_Cheque_Motive,
    Binding_Enum_Banks,
    Binding_Enum_Cheque_Status
    
} BindingEnum;

typedef enum TransferTypes
{
    OwnAccountsTransferType = 0,
    SameBankTransferType = 1,
    OtherBankTransferType = 2,
    InternationalTransferType = 3,
}TransferTypes;

typedef enum TransferPeriodicityTypes
{
    EventualTransferType = 0,
    PermanentTransferType = 1,
}TransferPeriodicityTypes;

//progress status
typedef enum ProgressStatus
{
    SF = 0,
    Workflow = 1,
    TimeOut = 2,
    UnknownError = 3,
    BusinessError = 4,
    Sucess = 5,
    Offline = 6,
    SessionTimeOut = 7,
    SFSended = 8
}ProgressStatus;

//textFields Types
typedef enum: NSUInteger {
    AmountTextFieldType,
    StringTextFieldType,
    AccountTextFieldType,
    NIBTextFieldType,
    IBANTextFieldType,
    NumberTextFieldType,
    EmailTextFieldType,
    PhoneTextFieldType,
    SWIFTTextFieldType,
    PasswordFieldType
} TextFieldsTypes;

typedef enum: NSUInteger
{
    TopSelectorFormDisabled = 1,
    TopSelectorFormViewCurrentAccounts = 2,
    TopSelectorFormViewSavingAccounts = 3,
    TopSelectorFormViewCreditCards = 4,
    TopSelectorFormViewDebitCards = 5
}TopSelectorFormViewType;


typedef enum TransactionsFormAutoFillOperations
{
    BeneficiariesSelection = 0,
    FavoritesSelection = 1,
    LatestTransactionsSelection = 2,
    NavigateToSelection = 3,
    RespondesToDelegate = 4,
    ShareSelection = 5
}TransactionsFormAutoFillOperations;

typedef enum NavigateToOptions
{
    SameBankTransferNavigateOption = 0,
    InternationalTransferNavigateOption = 1,
    PaymentServicesNavigateOption = 2,
    RechargesNavigateOption = 3,
    TopUpNavigateOption = 4,
    DashboardNavigateOption = 5,
    CurrentAccountList = 6,
    CardAccountPaymentNavigateOption = 7,
    CardAccountChangePaymentOptionNavigateOption = 8,
    CardAccountStatementsNavigateOption = 9,
    ExchangeRequestNavigationOption = 10,
    MultipleTransferNavigateOption = 11,
    GovernmentPaymentsNavigateOption = 12,
    CustomPaymentNavigateOption = 13,
    SavingAccountNewNavigateOption = 14,
    SavingAccountEndNavigateOption = 15,
    CreditsMovementsNavigateOption = 16,
    LoanScheduledPlanNavigateOption = 17,
    SavingAccountListNavigateOption = 18,
    OtherBankTransferNavigateOption = 19,
    OwnAccountTransferNavigateOption = 20,
    ChequeRequestNavigateOption = 21,
    CreditsDetailsNavigateOption = 22,
    CurrentAccountStatments = 23,
}NavigateToOptions;

typedef enum: NSUInteger
{
    FormDetailsBeneficiaryView = 1,
    FormDetailsFavoriteView = 2,
    FormDetailsLatestTransactionView = 3,
    FormViewCurrentAccountsScrollView = 4,
    FormViewSavingAccountsScrollView = 5,
    FormViewCreditCardsScrollView = 6,
    FormViewDebitCardsScrollView = 7,
}FormDetailsViewType;

typedef enum TransactionID
{
    CancelTransferTrxID = 21,
    ExchangesTrxID = 24,
    ReservationRequestForeignCurrencyTrxID = 25,
    ProductSubscriptionTrxID = 163,
    AccountStatementTrxID = 38,
    CurrentAccountBalanceTrxID = 39,
    ChequeRequestTrxID = 40,
    CardAccountOptionTrxID = 76,
    DebitCardStatementTrxID = 77,
    CardPaymentTrxID = 84,
    CardAccountLimitTrxID = 85,
    SavingReinforcementTrxID = 86,
    SavingMobilizationTrxID = 87,
    ChequeConsultTrxID = 88,
    ChequeCancelTrxID = 89,
    CreditCardRequestTrxID = 90,
    CardDebitRequestTrxID = 92,
    ChangePasswordTransactionTrxID = 157,
    ChangeAccessCodeTransactionTrxID = 118,
    ProductsTransactionTrxID = 119,
    CardCancelTransactionTrxID = 123,
    InsertDebitAuthorizationTransactionTrxID = 126,
    FinancingRequestTransactionTrxID = 129,
    EntityPaymentTransactionTrxID = 164,
    RechargeTransactionTrxID = 165,
    PhoneBillTransactionTrxID = 166,
    SpecialTransactionTrxID = 167,
    InterbankStandardTransferTransactionTrxID = 138,
    InterbankUrgentTransferTransactionTrxID = 139,
    FinancingCreditSimulationTransactionTrxID = 140,
    RentalCreditSimulationTransactionTrxID = 141,
    InternalTransferRequestTrxID = 93,
    InternalTransferRequestMyAccountsTrxID = 146,
    AuthorizePendingOperationsTrxID = 159,
    QrCodeGenerator = 256,
    
    /*93	AccountInternalBankTransferTransaction
     157	ChangePasswordTransaction
     159	CustomerChangeContactInfoTransactionV2
     160	ChequeBookRequestTransaction
     161	ChequeBookCancelTransaction
     162	ChequeBookChequesTransaction
     163	NewTermDepositTransaction
     164	UtilityPaymentsTransaction
     165	RechargeTransaction
     166	PhoneBillTransaction
     167	UtilityPaymentCustomTransaction
     169	EndTermDepositTransaction
     170	LoanSimulationTransaction
     174	LoanSimulationTransaction
     177	CardCancelTransaction
     178	CardChangeLimiteTransaction
     179	CardChangePaymentOptionTransaction
     180	CardCashAdvancedTransaction
     181	CardPaymentTransaction*/
    
}TransactionID;

typedef enum OperationCode
{
    UnknownOpCode = 0,
    InternalTransferOpCode=6,
    SameBankTransferOpCode=5,
    OwnAccountsOpCode=4,
    RequestExchangeOpCode = 426,
    ChangeCardOptionOpCode = 29,
    ChangeCardAcountLimitOpCode = 21,
    CardAcountPaymentOpCode = 354,
    SavingCreateOpCode = 248,
    CancelTransferOpCode = 49,
    CancelCheckOpCode = 39,
    CheckRequestOpCode = 279,
    ChangeAccessCodeOpCode = 951,
    ChangePasswordOpCode = 186,
    UtilityPaymentOpCode = 3,
    RechargesOpCode = 168,
    PaymentPhoneBillOpCode = 974,
    SpecialPaymentOpCode = 163,
    UtilityCustomPaymentOpCode = 163,
    EndTermDepositOpCode = 144,
    DLIPaymentOpCode = 137,
    InternationalTransferOpCode = 56,
    MultipleTransferOpCode = 1108,
    ChangeContactOpCode = 32,
    PS2TransferOpCode = 1621,
    LoginOpCode = 639,
    CreditSimultatorOpCode = 50
    
}OperationCode;

typedef enum OperationDetailField
{
    DestinAccount = 2,
    Amount = 5,
    AccountField = 23,
    Description = 25,
    Date = 4,
    ExpirationDate = 27,
    OperType = 8,
    Email = 1002,
    Periodicity = 28,
    Currency = 6,
    CardAccountNumber = 1,
    PaymentAmount = 2,
    InternalTransferOriginAccountNumber = 23,
    ServicePaymentEntity = 1,
    ServicePaymentEntityDescription = 16,
    ServicePaymentReference = 2,
    ServicePaymentAmount = 3,
    ServicePaymentOriginAccountNib = 5,
    ServicePaymentCurrency = 6,
    BeneficiaryName = 3,
    PhoneTopUpOpOriginAccount = 18,
    CustomPaymentOriginAccount = 16,

    
}OperationDetailField;

typedef enum CardTypes
{
    CreditCardType = 1,
    DebitCardType = 0
}CardTypes;

typedef enum AccountTypes
{
    CurrentAccountType = 0,
    SavingAccountType = 1,
    CreditAccountType = 2,
    CardAccountType = 3,
    UnknownAccountType = 4,
}AccountTypes;

typedef enum ProductTypes
{
    CurrentAccountProductType = 0,
    CreditCardProductType = 1,
    TermDepositProductType = 2,
    LoanProductType = 3,
    DebitCardProductType = 4,
}ProductTypes;

typedef enum EntityTypes
{
    UtilityPaymentType = 1,
    RechargesType = 2,
    CustomPaymentType = 4,
    PhoneTopUpType = 8,
}EntityTypes;

typedef enum SelectedSeparator
{
    ReceivedMessagesSep = 0,
    SentMessagesSep = 1,
    DeletedMessagesSep = 2,
    SendMessageSep = 3,
}SelectedSeparator;

typedef enum PDFtype
{
    CardPDFType = 0,
    CurrentAccountPDFType = 1,
    SavingAccountPDFType = 2,
    CreditAccountPDFType = 3,
    CardAccountPDFType = 4,
    ChequePDFType = 5,
    FinancialPlanPDFType = 6,
}PDFtype;

typedef enum {
    IPUnkwownAccountType = 0,
    IPCurrentAccountType = 1,
    IPEscrowAccountType = 2,
    IPSavingAccountType = 3,
    IPReceivedGuaranteesAccountType = 4,
    IPGuaranteesAccountType = 5,
    IPFinancingCreditAccountType = 6,
    IPIrregularCreditAccountType = 7,
    IPTotalAssetsAccountType = 8,
    IPTotalLiabilitiesAccountType = 9,
    IPDocumentaryCreditsAccountType = 10,
    IPIncomeCreditAccountType = 11,
    IPCreditCardsAccountType = 12,
    IPDebitCardsAccountType = 13,
    IPPendingCreditProposalAccountType = 14,
    IPApprovedCreditProposalAccountType = 15,
    IPDebitPendingOperationsAccountType = 16,
    IPBankaRemoteContractAccountType = 17,
    IPTotalCreditCaptiveAccountType = 18,
    IPPaymentDomiciliationAccountType = 19,
    IPOtherProductsAndServicesAccountType = 20,
    IPOtherAssets = 21,
    IPOtherLiabilities = 22,
} IPAccountTypes;

typedef enum LoginCredentialType{
    CredentialTypePassword = 0,
    CredentialTypePositions = 1,
    CredentialDeviceAndToken = 10,
} LoginCredentialType;

typedef enum PDFStatementsType{
    PDFStatementsTypeCard = 0,
    PDFStatementsTypeCheckingAccount = 1,
    PDFStatementsTypeSavingAccount = 2,
    PDFStatementsTypeCreditAccount = 3,
    PDFStatementsTypeCardAccount = 4,
    PDFStatementsTypeCheque = 5,
    PDFStatementsTypeFinancingPlan = 6,
} PDFStatementsType;

@end
