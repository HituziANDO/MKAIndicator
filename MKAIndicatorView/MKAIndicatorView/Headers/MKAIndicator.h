//
//  MKAIndicator.h
//  MKAIndicatorView
//
//  Created by Masaki Ando
//  Copyright (c) 2018 Hituzi Ando. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MKAIndicatorType) {
    MKAIndicatorTypeBasic = 0,
    MKAIndicatorTypeCustom,
    MKAIndicatorTypeSpriteAnimation,
    MKAIndicatorTypeOnlyStatusBar,
};

@interface MKAIndicator : NSObject
/**
 * Returns YES if the indicator is displayed, otherwise NO.
 */
@property (nonatomic, readonly) BOOL isVisible;
/**
 * If YES, the indicator is also displayed on the status bar.
 */
@property (nonatomic) BOOL withStatusBarIndicator;
/**
 * Specifies the type of indicator. You can not change the style while displaying.
 */
@property (nonatomic) MKAIndicatorType indicatorType;

/**
 * Returns the singleton instance that is set current style.
 */
+ (instancetype)currentIndicator;
/**
 * Returns the singleton instance.
 */
+ (instancetype)defaultIndicator DEPRECATED_ATTRIBUTE;
/**
 * Returns the singleton instance of basic style. Specifies the style of the indicator.
 *
 * @param style UIActivityIndicatorViewStyle
 */
+ (instancetype)basicIndicatorWithActivityIndicatorViewStyle:(UIActivityIndicatorViewStyle)style;
/**
 * Returns the singleton instance of custom style. Specifies the indicator image.
 *
 * @param image The image of the indicator.
 */
+ (instancetype)customIndicatorWithIndicatorViewImage:(UIImage *)image;
/**
 * Returns the singleton instance of sprite animation style.
 * Specifies the array of indicator images. The size of the indicator image must be unified.
 * And specifies the animation speed.
 *
 * @param images The array of indicator images.
 */
+ (instancetype)spriteAnimationIndicatorWithIndicatorViewImages:(NSArray<UIImage *> *)images;
/**
 * Returns the singleton instance of sprite animation style.
 * Specifies the indicator image file name format and number of frames. The size of the indicator image must be unified.
 * And specifies the animation speed.
 *
 * @param format The file name format like "indicator%ld". The file name must have a sequential number from 0.
 * @param count Number of frames.
 */
+ (instancetype)spriteAnimationIndicatorWithIndicatorViewImagesFormat:(NSString *)format count:(NSInteger)count;
/**
 * Returns the singleton instance of only status bar style.
 */
+ (instancetype)onlyStatusBarIndicator NS_SWIFT_NAME(onlyStatusBarIndicator());

/**
 * Shows / hides the indicator.
 * If `animating` is YES, the display count is incremented by 1 and the indicator is displayed.
 * If it is NO, the display count is decremented by 1, and when the count becomes 0, the indicator is hidden.
 *
 * @param animating YES if the indicator is displayed.
 * @param view Displays the indicator on specified view.
 * @param touchDisabled If YES, the user can not operate while the indicator is displayed.
 */
- (void)startAnimating:(BOOL)animating
                inView:(UIView *)view
     withTouchDisabled:(BOOL)touchDisabled;
/**
 * Shows / hides the indicator.
 * If `animating` is YES, the display count is incremented by 1 and the indicator is displayed.
 * If it is NO, the display count is decremented by 1, and when the count becomes 0, the indicator is hidden.
 *
 * @param animating YES if the indicator is displayed.
 * @param view Displays the indicator on specified view.
 * @param point The center coordinates of the indicator on the specified view.
 * @param touchDisabled If YES, the user can not operate while the indicator is displayed.
 */
- (void)startAnimating:(BOOL)animating
                inView:(UIView *)view
               atPoint:(CGPoint)point
     withTouchDisabled:(BOOL)touchDisabled;
/**
 * The display count is incremented by 1 and the indicator is displayed.
 * The indicator will not be displayed in duplicate even if this method is executed more than once.
 *
 * @param view Displays the indicator on specified view.
 * @param touchDisabled If YES, the user can not operate while the indicator is displayed.
 */
- (void)showInView:(UIView *)view withTouchDisabled:(BOOL)touchDisabled;
/**
 * The display count is incremented by 1 and the indicator is displayed.
 * The indicator will not be displayed in duplicate even if this method is executed more than once.
 *
 * @param view Displays the indicator on specified view.
 * @param point The center coordinates of the indicator on the specified view.
 * @param touchDisabled If YES, the user can not operate while the indicator is displayed.
 */
- (void)showInView:(UIView *)view atPoint:(CGPoint)point withTouchDisabled:(BOOL)touchDisabled;
/**
 * The display count is decremented by 1, and when the count becomes 0, the indicator is hidden.
 */
- (void)hide;
/**
 * Forcibly hides the indicator by setting the display count to 0.
 */
- (void)hideForcibly;
/**
 * Specifies the size of the indicator. You can not change the style while displaying.
 *
 * @param size The size of the view.
 */
- (instancetype)setSize:(CGSize)size;
/**
 * Specifies the style of the indicator when MKAIndicatorType is set to MKAIndicatorTypeBasic.
 * You can not change the style while displaying.
 *
 * @param style UIActivityIndicatorViewStyle
 */
- (void)setActivityIndicatorViewStyle:(UIActivityIndicatorViewStyle)style DEPRECATED_ATTRIBUTE;
/**
 * Specifies the indicator image when MKAIndicatorType is set to MKAIndicatorTypeCustom.
 * You can not change the style while displaying.
 *
 * @param image The image of the indicator.
 */
- (void)setCustomIndicatorViewImage:(UIImage *)image DEPRECATED_ATTRIBUTE;
/**
 * Specifies the array of indicator images when MKAIndicatorType is set to MKAIndicatorTypeSpriteAnimation.
 * The size of the indicator image must be unified. You can not change the style while displaying.
 *
 * @param images The array of indicator images.
 */
- (void)setSpriteAnimationIndicatorViewImages:(NSArray<UIImage *> *)images DEPRECATED_ATTRIBUTE;
/**
 * Specifies the indicator image file name format and number of frames when MKAIndicatorType is set to MKAIndicatorTypeSpriteAnimation.
 * The size of the indicator image must be unified. You can not change the style while displaying.
 *
 * @param format The file name format like "indicator%ld". The file name must have a sequential number from 0.
 * @param count Number of frames.
 */
- (void)setSpriteAnimationIndicatorViewImagesWithFormat:(NSString *)format count:(NSInteger)count DEPRECATED_ATTRIBUTE;
/**
 * Specifies the animation speed when MKAIndicatorType is set to MKAIndicatorTypeCustom or MKAIndicatorTypeSpriteAnimation.
 * You can not change the style while displaying.
 *
 * @param duration Animation speed (smaller value means faster).
 */
- (instancetype)setAnimationDuration:(double)duration;
/**
 * Specifies the number of iterations of animation when MKAIndicatorType is set to MKAIndicatorTypeCustom or MKAIndicatorTypeSpriteAnimation.
 * You can not change the style while displaying.
 *
 * @param repeatCount The number of iterations of animation.
 */
- (instancetype)setAnimationRepeatCount:(NSInteger)repeatCount;
/**
 * Adds the arbitrary background to the indicator.
 * The added background is set on the back. You can not change the style while displaying.
 
 @param bgView The background view.
 */
- (instancetype)addBackgroundView:(UIView *)bgView;
/**
 * Adds the black background to the indicator. You can not change the style while displaying.
 */
- (instancetype)addBlackBackgroundView;
/**
 * The indicator is also displayed on the status bar. You can not change the style while displaying.
 */
- (instancetype)alsoStatusBarIndicator NS_SWIFT_NAME(alsoStatusBarIndicator());

@end

NS_ASSUME_NONNULL_END
