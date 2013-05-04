//
//  MCOIMAPIdleOperation.h
//  mailcore2
//
//  Created by DINH Viêt Hoà on 3/25/13.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#ifndef __MAILCORE_MCOIMAPIDLEOPERATION_H_

#define __MAILCORE_MCOIMAPIDLEOPERATION_H_

#import <MailCore/MCOIMAPBaseOperation.h>

@interface MCOIMAPIdleOperation : MCOIMAPBaseOperation

- (void) interruptIdle;

- (void)start:(void (^)(NSError *error))completionBlock;

@end

#endif
