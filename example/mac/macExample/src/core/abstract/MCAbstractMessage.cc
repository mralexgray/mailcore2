#include "MCAbstractMessage.h"

#include "MCMessageHeader.h"

using namespace mailcore;

AbstractMessage::AbstractMessage()
{
    init();
}

AbstractMessage::AbstractMessage(AbstractMessage * other)
{
    init();
    mHeader = (MessageHeader *) MC_SAFE_COPY(other->mHeader);
}

void AbstractMessage::init()
{
    mHeader = NULL;
}

AbstractMessage::~AbstractMessage()
{
    MC_SAFE_RELEASE(mHeader);
}

String * AbstractMessage::description()
{
    if (mHeader != NULL) {
        String * result = String::string();
        result->appendUTF8Format("<%s:%p\n", className()->UTF8Characters(), this);
        result->appendString(mHeader->description());
        result->appendUTF8Characters(">");
        return result;
    }
    else {
        return Object::description();
    }
}

Object * AbstractMessage::copy()
{
    return new AbstractMessage(this);
}

MessageHeader * AbstractMessage::header()
{
    if (mHeader == NULL) {
        mHeader = new MessageHeader();
    }
    return mHeader;
}

void AbstractMessage::setHeader(MessageHeader * header)
{
    MC_SAFE_REPLACE_RETAIN(MessageHeader, mHeader, header);
}

AbstractPart * AbstractMessage::partForContentID(String * contentID)
{
    MCAssert(0);
    return NULL;
}

AbstractPart * AbstractMessage::partForUniqueID(String * uniqueID)
{
    MCAssert(0);
    return NULL;
}
