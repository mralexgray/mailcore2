#include "MCSMTPAsyncSession.h"

#include "MCSMTPSession.h"
//#include "MCSMTPSendWithRecipientOperation.h"
#include "MCSMTPSendWithDataOperation.h"
//#include "MCSMTPSendWithBuilderOperation.h"
#include "MCSMTPCheckAccountOperation.h"
#include "MCSMTPOperation.h"

using namespace mailcore;

SMTPAsyncSession::SMTPAsyncSession()
{
    mSession = new SMTPSession();
    mQueue = new OperationQueue();
}

SMTPAsyncSession::~SMTPAsyncSession()
{
    MC_SAFE_RELEASE(mQueue);
    MC_SAFE_RELEASE(mSession);
}

void SMTPAsyncSession::setHostname(String * hostname)
{
    mSession->setHostname(hostname);
}

String * SMTPAsyncSession::hostname()
{
    return mSession->hostname();
}

void SMTPAsyncSession::setPort(unsigned int port)
{
    mSession->setPort(port);
}

unsigned int SMTPAsyncSession::port()
{
    return mSession->port();
}

void SMTPAsyncSession::setUsername(String * username)
{
    return mSession->setUsername(username);
}

String * SMTPAsyncSession::username()
{
    return mSession->username();
}

void SMTPAsyncSession::setPassword(String * password)
{
    mSession->setPassword(password);
}

String * SMTPAsyncSession::password()
{
    return mSession->password();
}

void SMTPAsyncSession::setAuthType(AuthType authType)
{
    mSession->setAuthType(authType);
}

AuthType SMTPAsyncSession::authType()
{
    return mSession->authType();
}

void SMTPAsyncSession::setConnectionType(ConnectionType connectionType)
{
    mSession->setConnectionType(connectionType);
}

ConnectionType SMTPAsyncSession::connectionType()
{
    return mSession->connectionType();
}

void SMTPAsyncSession::setTimeout(time_t timeout)
{
    return mSession->setTimeout(timeout);
}

time_t SMTPAsyncSession::timeout()
{
    return mSession->timeout();
}

void SMTPAsyncSession::setCheckCertificateEnabled(bool enabled)
{
    return mSession->setCheckCertificateEnabled(enabled);
}

bool SMTPAsyncSession::isCheckCertificateEnabled()
{
    return mSession->isCheckCertificateEnabled();
}

void SMTPAsyncSession::setUseHeloIPEnabled(bool enabled)
{
    mSession->setUseHeloIPEnabled(enabled);
}

bool SMTPAsyncSession::useHeloIPEnabled()
{
    return mSession->useHeloIPEnabled();
}

void SMTPAsyncSession::runOperation(SMTPOperation * operation)
{
#warning disconnect after delay
    mQueue->addOperation(operation);
}

SMTPSession * SMTPAsyncSession::session()
{
    return mSession;
}

#if 0
SMTPOperation * SMTPAsyncSession::sendMessageOperationWithFromAndRecipient(Address * from, Array * recipients, Data * messageData)
{
    SMTPSendWithRecipientOperation * op = new SMTPSendWithRecipientOperation();
    op->setSession(this);
    op->setFrom(from);
    op->setRecipients(recipients);
    op->setMessageData(messageData);
    return (SMTPOperation *) op->autorelease();
}
#endif

SMTPOperation * SMTPAsyncSession::sendMessageOperation(Data * messageData)
{
    SMTPSendWithDataOperation * op = new SMTPSendWithDataOperation();
    op->setSession(this);
    op->setMessageData(messageData);
    return (SMTPOperation *) op->autorelease();
}

#if 0
SMTPOperation * SMTPAsyncSession::sendMessageOperation(MessageBuilder * msg)
{
    SMTPSendWithBuilderOperation * op = new SMTPSendWithBuilderOperation();
    op->setSession(this);
    op->setBuilder(msg);
    return (SMTPOperation *) op->autorelease();
}
#endif

SMTPOperation * SMTPAsyncSession::checkAccountOperation(Address * from)
{
    SMTPCheckAccountOperation * op = new SMTPCheckAccountOperation();
    op->setFrom(from);
    op->setSession(this);
    return (SMTPOperation *) op->autorelease();
}

