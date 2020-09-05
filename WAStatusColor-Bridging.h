//
//  WAStatusColor-Bridging.h
//  Created by BandarHelal on 17/01/1442 AH.
//
//#import <Alderis/Alderis-Swift.h>
#import "WAHeaders.h"

NS_ASSUME_NONNULL_BEGIN

@interface WAStatusColor_Bridging : NSObject
+ (instancetype)shared;
- (UIViewController *)presentColorPickerWithDelegate:(id)_self defaultColor:(UIColor *)color;
- (UIViewController *)presentlastColorPicker;
@end

NS_ASSUME_NONNULL_END
