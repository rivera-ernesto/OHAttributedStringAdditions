//
//  AttributedStringDemoTests.m
//  AttributedStringDemoTests
//
//  Created by Olivier Halligon on 13/08/2014.
//  Copyright (c) 2014 AliSoftware. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "UIFont+OHAdditions.h"

@interface UIFontTests : XCTestCase @end

@implementation UIFontTests

- (void)test_fontWithFamily_size_bold_italic_01
{
    UIFont* font = [UIFont fontWithFamily:@"Helvetica" size:42 bold:NO italic:NO];
    XCTAssertEqualObjects(font.fontName, @"Helvetica");
    XCTAssertEqualObjects(font.fontDescriptor.postscriptName, @"Helvetica");
    XCTAssertEqual(font.pointSize, 42);
}

- (void)test_fontWithFamily_size_bold_italic_02
{
    UIFont* font = [UIFont fontWithFamily:@"Helvetica" size:42 bold:NO italic:YES];
    XCTAssertEqualObjects(font.fontName, @"Helvetica Oblique");
    XCTAssertEqualObjects(font.fontDescriptor.postscriptName, @"Helvetica-Oblique");
    XCTAssertEqual(font.pointSize, 42);
}

- (void)test_fontWithFamily_size_bold_italic_03
{
    UIFont* font = [UIFont fontWithFamily:@"Helvetica" size:42 bold:YES italic:NO];
    XCTAssertEqualObjects(font.fontName, @"Helvetica Bold");
    XCTAssertEqualObjects(font.fontDescriptor.postscriptName, @"Helvetica-Bold");
    XCTAssertEqual(font.pointSize, 42);
}

- (void)test_fontWithFamily_size_bold_italic_04
{
    UIFont* font = [UIFont fontWithFamily:@"Helvetica" size:42 bold:YES italic:YES];
    XCTAssertEqualObjects(font.fontName, @"Helvetica Bold Oblique");
    XCTAssertEqualObjects(font.fontDescriptor.postscriptName, @"Helvetica-BoldOblique");
    XCTAssertEqual(font.pointSize, 42);
}

- (void)test_fontWithFamily_size_bold_italic_05
{
    UIFont* font = [UIFont fontWithFamily:@"Zxqvz9pmq" size:42 bold:YES italic:YES];
    XCTAssertEqualObjects(font.fontName, @"Helvetica");
    XCTAssertEqualObjects(font.fontDescriptor.postscriptName, @"Helvetica");
    XCTAssertEqual(font.pointSize, 42);
}

- (void)test_fontWithFamily_size_traits
{
    UIFontDescriptorSymbolicTraits traits = UIFontDescriptorTraitCondensed | UIFontDescriptorTraitBold;
    UIFont* font = [UIFont fontWithFamily:@"Helvetica Neue" size:42 traits:traits];
    XCTAssertEqualObjects(font.fontName, @"Helvetica Neue Condensed Bold");
    XCTAssertEqualObjects(font.fontDescriptor.postscriptName, @"HelveticaNeue-CondensedBold");
    XCTAssertEqual(font.pointSize, 42);
}

- (void)test_fontWithSymbolicTraits
{
    UIFont* baseFont = [UIFont fontWithName:@"Helvetica Neue" size:42];
    UIFont* font = [baseFont fontWithSymbolicTraits:UIFontDescriptorTraitCondensed|UIFontDescriptorTraitBold];
    XCTAssertEqualObjects(font.fontName, @"Helvetica Neue Condensed Bold");
    XCTAssertEqualObjects(font.fontDescriptor.postscriptName, @"HelveticaNeue-CondensedBold");
    XCTAssertEqual(font.pointSize, 42);
    
}

- (void)test_symbolicTraits
{
    UIFont* font = [UIFont fontWithName:@"HelveticaNeue-CondensedBold" size:42];
    XCTAssertEqual(font.symbolicTraits, UIFontDescriptorTraitCondensed|UIFontDescriptorTraitBold);
}

@end
