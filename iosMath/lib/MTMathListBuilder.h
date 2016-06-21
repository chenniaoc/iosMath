//
//  MTMathListBuilder.h
//  iosMath
//
//  Created by Kostub Deshmukh on 8/28/13.
//  Copyright (C) 2013 MathChat
//   
//  This software may be modified and distributed under the terms of the
//  MIT license. See the LICENSE file for details.
//

#import <Foundation/Foundation.h>

#import "MTMathList.h"

FOUNDATION_EXPORT NSString *const MTParseError;

/** `MTMathListBuilder` is a class for parsing LaTeX into an `MTMathList` that
 can be rendered and processed mathematically.
 */
@interface MTMathListBuilder : NSObject

/** Contains any error that occurred during parsing. */
@property (nonatomic, readonly) NSError* error;

- (instancetype) initWithString:(NSString*) str NS_DESIGNATED_INITIALIZER;
- (instancetype) init NS_UNAVAILABLE;

/// Builds a mathlist from the given string. Returns nil if there is an error.
- (MTMathList*) build;

/// List of commands that are supported.
+ (NSDictionary*) supportedCommands;

/** Construct a math list from a given string. If there is parse error, returns
 nil. To retrieve the error use the function `[MTMathListBuilder buildFromString:error:]`.
 */
+ (MTMathList*) buildFromString:(NSString*) str;

/** Construct a math list from a given string. If there is an error while
 constructing the string, this returns nil. The error is returned in the 
 `error` parameter.
 */
+ (MTMathList*) buildFromString:(NSString*) str error:(NSError**) error;

/// This converts the MTMathList to LaTeX.
+ (NSString*) mathListToString:(MTMathList*) ml;

enum MTParseErrors {
    MTParseErrorMismatchBraces = 1,
    MTParseErrorInvalidCommand,
    MTParseErrorCharacterNotFound,
};

@end
