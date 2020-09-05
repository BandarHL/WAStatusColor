#import "WAStatusColor-Bridging.h"

%hook WAStatusTextComposerView
- (void)colorButtonTapped:(id)arg1 {
    WAStatusColor_Bridging *picker = [WAStatusColor_Bridging shared];
    [topMostController() presentViewController:[picker presentColorPickerWithDelegate:self defaultColor:self.backgroundColor] animated:true completion:nil];
}
%new - (void)colorPicker:(_TtC7Alderis25ColorPickerViewController *)colorPicker didSelectColor:(UIColor *)color {
    [self setBackgroundColor:color];
}
%end