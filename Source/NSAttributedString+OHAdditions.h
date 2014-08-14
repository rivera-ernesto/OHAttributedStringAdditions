/***********************************************************************************
 * This software is under the MIT License quoted below:
 ***********************************************************************************
 *
 * Copyright (c) 2010 Olivier Halligon
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 ***********************************************************************************/


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSAttributedString (OHAdditions)

- (NSRange)fullRange;

// MARK: Convenience Constructors

+ (instancetype)attributedStringWithString:(NSString*)string;
+ (instancetype)attributedStringWithAttributedString:(NSAttributedString*)attrStr;
+ (instancetype)attributedStringWithHTML:(NSString*)htmlString;

// MARK: Size

- (CGSize)sizeConstrainedToSize:(CGSize)maxSize;
- (CGSize)sizeConstrainedToSize:(CGSize)maxSize fitRange:(NSRange*)fitRange;

// MARK: Text Font

- (UIFont*)fontAtIndex:(NSUInteger)index effectiveRange:(NSRangePointer)aRange;
- (void)enumerateFontsInRange:(NSRange)enumerationRange usingBlock:(void (^)(UIFont* font, NSRange range, BOOL *stop))block;

// MARK: Text Color

- (UIColor*)textColorAtIndex:(NSUInteger)index effectiveRange:(NSRangePointer)aRange;
- (UIColor*)textBackgroundColorAtIndex:(NSUInteger)index effectiveRange:(NSRangePointer)aRange;

// MARK: Text Style

- (BOOL)textUnderlinedAtIndex:(NSUInteger)index effectiveRange:(NSRangePointer)aRange;
- (NSUnderlineStyle)textUnderlineStyleAtIndex:(NSUInteger)index effectiveRange:(NSRangePointer)aRange;
- (UIColor*)textUnderlineColorAtIndex:(NSUInteger)index effectiveRange:(NSRangePointer)aRange;

- (BOOL)textBoldAtIndex:(NSUInteger)index effectiveRange:(NSRangePointer)aRange;
- (BOOL)textItalicsAtIndex:(NSUInteger)index effectiveRange:(NSRangePointer)aRange;

// MARK: Link

- (NSURL*)URLAtIndex:(NSUInteger)index effectiveRange:(NSRangePointer)aRange;
- (void)enumerateURLsInRange:(NSRange)enumerationRange usingBlock:(void (^)(NSURL* link, NSRange range, BOOL *stop))block;

// MARK: Character Spacing

- (CGFloat)characterSpacingAtIndex:(NSUInteger)index effectiveRange:(NSRangePointer)aRange;

// MARK: Paragraph Style

- (NSTextAlignment)textAlignmentAtIndex:(NSUInteger)index effectiveRange:(NSRangePointer)aRange;
- (NSLineBreakMode)lineBreakModeAtIndex:(NSUInteger)index effectiveRange:(NSRangePointer)aRange;
- (NSParagraphStyle*)paragraphStyleAtIndex:(NSUInteger)index effectiveRange:(NSRangePointer)aRange;
- (void)enumerateParagraphStylesInRange:(NSRange)enumerationRange usingBlock:(void (^)(NSParagraphStyle* style, NSRange range, BOOL *stop))block;

@end


