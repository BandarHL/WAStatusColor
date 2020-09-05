//
//  WAHeaders.h
//  Created by BandarHelal on 17/01/1442 AH.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// Alderis
@interface _TtC7Alderis25ColorPickerViewController : UIViewController
//SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) UIColor * _Nonnull defaultColor;)
+ (UIColor * _Nonnull)defaultColor;
@property (nonatomic, weak) id _Nullable delegate;
@property (nonatomic) BOOL overrideSmartInvert;
@property (nonatomic, strong) UIColor * _Nonnull color;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder;
- (void)viewDidLoad;
- (void)viewWillLayoutSubviews;
- (void)viewWillAppear:(BOOL)animated;
- (void)viewDidAppear:(BOOL)animated;
- (void)viewWillDisappear:(BOOL)animated;
@end

//SWIFT_PROTOCOL_NAMED("ColorPickerDelegate")
@protocol HBColorPickerDelegate <NSObject>
- (void)colorPicker:(_TtC7Alderis25ColorPickerViewController * _Nonnull)colorPicker didSelectColor:(UIColor * _Nonnull)color;
- (void)colorPickerDidCancel:(_TtC7Alderis25ColorPickerViewController * _Nonnull)colorPicker;
@end

// WA
@interface WAStatusTextComposerView : UIView
@end

@interface WAStatusTextComposerView () <HBColorPickerDelegate>
@end

@interface WAStatusTextComposerViewController : UIViewController
@end

// https://github.com/julioverne/MImport/blob/0275405812ff41ed2ca56e98f495fd05c38f41f2/mimporthook/MImport.xm#L59
static UIViewController *_topMostController(UIViewController *cont) {
    UIViewController *topController = cont;
    while (topController.presentedViewController) {
        topController = topController.presentedViewController;
    }
    if ([topController isKindOfClass:[UINavigationController class]]) {
        UIViewController *visible = ((UINavigationController *)topController).visibleViewController;
        if (visible) {
            topController = visible;
        }
    }
    return (topController != cont ? topController : nil);
}
static UIViewController *topMostController() {
    UIViewController *topController = [UIApplication sharedApplication].keyWindow.rootViewController;
    UIViewController *next = nil;
    while ((next = _topMostController(topController)) != nil) {
        topController = next;
    }
    return topController;
}