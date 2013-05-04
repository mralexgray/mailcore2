//
//  MCOMessageParser.h
//  mailcore2
//
//  Created by DINH Viêt Hoà on 3/22/13.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#ifndef __MAILCORE_MCOMESSAGEPARSER_H_

#define __MAILCORE_MCOMESSAGEPARSER_H_

#import <MailCore/MCOAbstractMessage.h>

@protocol MCOHTMLRendererDelegate;

@interface MCOMessageParser : MCOAbstractMessage <NSCopying>

// returns a parsed message from the given RFC 822 data.
+ (MCOMessageParser *) messageParserWithData:(NSData *)data;

// data is the RFC 822 formatted message.
- (id) initWithData:(NSData *)data;
- (void) dealloc;

// It's the main part of the message. It can be MCOMessagePart, MCOMultipart or MCOAttachment.
- (MCOAbstractPart *) mainPart;

// data of the RFC 822 formatted message. It's the input of the parser.
- (NSData *) data;

// HTML rendering of the message to be displayed in a web view.
// delegate can be nil.
- (NSString *) htmlRenderingWithDelegate:(id <MCOHTMLRendererDelegate>)delegate;

@end

#endif
