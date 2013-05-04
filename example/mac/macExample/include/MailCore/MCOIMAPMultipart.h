//
//  MCOIMAPMultipart.h
//  mailcore2
//
//  Created by DINH Viêt Hoà on 3/23/13.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#ifndef __MAILCORE_MCOIMAPMULTIPART_H_

#define __MAILCORE_MCOIMAPMULTIPART_H_

#import <MailCore/MCOAbstractMultipart.h>

@interface MCOIMAPMultipart : MCOAbstractMultipart <NSCopying>

@property (nonatomic, copy) NSString * partID;

@end

#endif
