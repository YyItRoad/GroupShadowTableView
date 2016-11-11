//
//  GroupShadowTableView.h
//  FaceMoney
//
//  Created by 杨洋 on 9/11/16.
//  Copyright © 2016 杨洋. All rights reserved.
//

#import <UIKit/UIKit.h>

@class GroupShadowTableView;
@protocol GroupShadowTableViewDelegate <NSObject>

@optional
- (void)groupShadowTableView:(GroupShadowTableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath;

- (CGFloat)groupShadowTableView:(GroupShadowTableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath;

- (BOOL)groupShadowTableView:(GroupShadowTableView *)tableView canSelectAtSection:(NSInteger)section;

@end

@protocol GroupShadowTableViewDataSource <NSObject>
@optional
- (NSInteger)numberOfSectionsInGroupShadowTableView:(GroupShadowTableView *)tableView;

@required

- (NSInteger)groupShadowTableView:(GroupShadowTableView *)tableView numberOfRowsInSection:(NSInteger)section;

- (UITableViewCell *)groupShadowTableView:(GroupShadowTableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;

@end

@interface GroupShadowTableView : UITableView
/**
 是否显示分割线  默认YES
 */
@property (nonatomic,assign) BOOL showSeparator;

@property (nonatomic,weak) IBOutlet id <GroupShadowTableViewDelegate> groupShadowDelegate;

@property (nonatomic,weak) IBOutlet id <GroupShadowTableViewDataSource> groupShadowDataSource;

@property (nonatomic,copy) NSInteger (^numberOfSectionsInGroupShadowTableView)(GroupShadowTableView *tableView);

@property (nonatomic,copy) NSInteger (^numberOfRowsInSection)(GroupShadowTableView *tableView,NSInteger section);

@property (nonatomic,copy) CGFloat (^heightForRowAtIndexPath)(GroupShadowTableView *tableView,NSIndexPath *indexPath);

@property (nonatomic,copy) UITableViewCell * (^cellForRowAtIndexPath)(GroupShadowTableView *tableView,NSIndexPath *indexPath);

@property (nonatomic,copy) void (^didSelectRowAtIndexPath)(GroupShadowTableView *tableView,NSIndexPath *indexPath);

@end
