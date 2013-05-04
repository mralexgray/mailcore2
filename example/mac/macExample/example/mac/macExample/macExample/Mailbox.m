//
//  Mailbox.m
//  macExample
//
//  Created by Alex Gray on 4/6/13.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#import "Mailbox.h"


@interface Mailbox ()
@property (STRNG) NSMA* messages;
@end

@implementation Mailbox
+ (instancetype) instanceWithObject:(id)object {

	Mailbox *m = self.instance;
	m.messages = [(NSA*)object cw_mapArray:^id(MCOIMAPMessage *msg){
			return [Message instanceWithMessage:msg];
	}].mutableCopy;
	return m;
}

@end
@implementation  Message

+ (instancetype) instanceWithMessage:(MCOIMAPMessage *)message {

		Message *m = self.new;
		m.message = message;
		return  m;
}

- (BOOL) unread {   	MCOMessageFlag flag = self.message.flags;  return  flag != MCOMessageFlagSeen;	}

- (NSS*) sender { 	MCOAddress	*sender = self.message.header.sender; return sender.displayName;  	} 

- (NSDate *)timestamp { return  self.message.header.date;  }

@end
