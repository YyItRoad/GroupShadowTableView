//
//  ViewController.m
//  GroupShadowTableViewDemo
//
//  Created by 杨洋 QQ: 158954945 on 12/11/16.
//  Copyright © 2016 杨洋. All rights reserved.
//



#import "ViewController.h"
#import "GroupShadowTableView.h"

@interface ViewController () <GroupShadowTableViewDelegate,GroupShadowTableViewDataSource>
@property (weak, nonatomic) IBOutlet GroupShadowTableView *tableView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.tableView.groupShadowDelegate = self;
    self.tableView.groupShadowDataSource = self;
    self.tableView.showSeparator = YES;
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

//MARK: - GroupShadowTableViewDataSource
- (NSInteger)numberOfSectionsInGroupShadowTableView:(GroupShadowTableView *)tableView {
    return 5;
}

- (NSInteger)groupShadowTableView:(GroupShadowTableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return section;
}

- (UITableViewCell *)groupShadowTableView:(GroupShadowTableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Cell"];
    cell.textLabel.text = [NSString stringWithFormat:@"section -> %@ ; row -> %@",@(indexPath.section) ,@(indexPath.row)];
    return cell;
    
}


//MARK: - GroupShadowTableViewDelegate
- (CGFloat)groupShadowTableView:(GroupShadowTableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 60;
}

- (void)groupShadowTableView:(GroupShadowTableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];

}

@end
