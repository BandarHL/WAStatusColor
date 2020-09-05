//
//  WAStatusColor-Bridging.m
//  Created by BandarHelal on 17/01/1442 AH.
//

#import "WAStatusColor-Bridging.h"
#include <dlfcn.h>

@interface WAStatusColor_Bridging ()
@property (nonatomic, strong) _TtC7Alderis25ColorPickerViewController *lastColorPicker;
@end

@implementation WAStatusColor_Bridging
+ (instancetype)shared {
    static WAStatusColor_Bridging *sharedManager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        dlopen("/Library/Frameworks/Alderis.framework/Alderis", RTLD_LAZY);
        sharedManager = [[self alloc] init];
    });
    return sharedManager;
}

- (UIViewController *)presentlastColorPicker {
    if (!(self.lastColorPicker == nil)) {
        return self.lastColorPicker;
    }
    return nil;
}

- (UIViewController *)presentColorPickerWithDelegate:(id)_self defaultColor:(UIColor *)color {
    _TtC7Alderis25ColorPickerViewController *picker = [[NSClassFromString(@"_TtC7Alderis25ColorPickerViewController") alloc] init];
    picker.delegate = _self;
    picker.color = color;
    self.lastColorPicker = picker;

    // check if ColorPickerViewController class exists after dlopen
    if (!(picker == nil)) {
        return picker;
    }
    // to avoid crashing when user hit the button, i just send a empty ViewController :)
    return UIViewController.new;
}
@end
