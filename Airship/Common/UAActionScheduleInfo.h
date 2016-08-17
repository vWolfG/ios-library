/*
 Copyright 2009-2016 Urban Airship Inc. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE URBAN AIRSHIP INC ``AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL URBAN AIRSHIP INC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import "UAScheduleTrigger.h"

NS_ASSUME_NONNULL_BEGIN

@class UAScheduleTrigger;

/**
 * Max number of triggers a schedule can support.
 */
extern NSUInteger const UAMaxTriggers;

/**
 * Builder class for a UAActionScheduleInfo.
 */
@interface UAActionScheduleInfoBuilder : NSObject

/**
 * Actions payload to run when the schedule is triggered.
 */
@property(nonatomic, strong, nullable) NSDictionary *actions;

/**
 * Number of times the actions will be triggered until the schedule is
 * canceled.
 */
@property(nonatomic, assign) NSUInteger limit;

/**
 * Array of triggers. Triggers define conditions on when to run
 * the actions.
 */
@property(nonatomic, strong, nullable) NSArray<UAScheduleTrigger *> *triggers;

/**
 * The schedule's group.
 */
@property(nonatomic, copy, nullable) NSString *group;

/**
 * The schedule's start time.
 */
@property(nonatomic, strong, nullable) NSDate *start;

/**
 * The schedule's end time. After the end time the schedule will be canceled.
 */
@property(nonatomic, strong, nullable) NSDate *end;

@end

/**
 * Defines the scheduled action.
 */
@interface UAActionScheduleInfo : NSObject

/**
 * Actions payload to run when the schedule is triggered.
 */
@property(nonatomic, readonly) NSDictionary *actions;

/**
 * Array of triggers. Triggers define conditions on when to run
 * the actions.
 */
@property(nonatomic, readonly) NSArray<UAScheduleTrigger *> *triggers;

/**
 * Number of times the actions will be triggered until the schedule is
 * canceled.
 */
@property(nonatomic, readonly) NSUInteger limit;

/**
 * The schedule's group.
 */
@property(nonatomic, readonly, nullable) NSString *group;

/**
 * The schedule's start time.
 */
@property(nonatomic, readonly) NSDate *start;

/**
 * The schedule's end time. After the end time the schedule will be canceled.
 */
@property(nonatomic, readonly) NSDate *end;

/**
 * Checks if the schedule info is valid. A valid schedule
 * must contain at least 1 action, contains between 1 to 10 triggers,
 * and the end time must be after the start time. Invalid schedules
 * will not be scheduled.
 */
@property(nonatomic, readonly) BOOL isValid;

/**
 * Creates an action schedule info with a builder block.
 *
 * @return The action schedule info.
 */
+ (instancetype)actionScheduleInfoWithBuilderBlock:(void(^)(UAActionScheduleInfoBuilder *builder))builderBlock;


/**
 * Checks if the schedule info is equal to another schedule info
 *
 * @param scheduleInfo The other schedule info to compare against.
 * @return `YES` if the schedule infos are equal, otherwise `NO`.
 */
- (BOOL)isEqualToScheduleInfo:(nullable UAActionScheduleInfo *)scheduleInfo;


@end

NS_ASSUME_NONNULL_END

