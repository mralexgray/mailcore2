//
//  Mailbox.h
//  macExample
//
//  Created by Alex Gray on 4/6/13.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#import <AtoZ/AtoZ.h>
#include <MailCore/MailCore.h>

@class  Message;
@interface Mailbox : BaseModel
+ (instancetype) instanceWithObject:(id)object;

- (id)	 objectInMailboxAtIndex:		   (NSUI) index;
- (void) removeObjectFromItemsAtIndex: (NSUI) index;
- (void) insertObject:				   (Message*)  todo     inItemsAtIndex:(NSUInteger)index;
- (NSUInteger)	countOfItems;

@end

@interface Message : BaseModel

@property (STRNG)	MCOIMAPMessage *message;
@property (STRNG) NSIMG 	*favicon;
@property (STRNG) NSC 		*color;
@property (NATOM) BOOL		faviconOK, unread;

@property (RONLY) NSS		*sender, *subject;
@property (RONLY) NSDate 	*timestamp;

+ (instancetype) instanceWithMessage:(MCOIMAPMessage*)message;

@end

