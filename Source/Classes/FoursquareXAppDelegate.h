// 
// FoursquareXAppDelegate.h
// FoursquareX
//
// Copyright (C) 2010 Eric Butler <eric@codebutler.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#import <Cocoa/Cocoa.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreWLAN/CoreWLAN.h>

#import <HTTPRiot/HTTPRiot.h> 
#import <Growl/Growl.h>

#import "NSArray-Blocks.h"

#import "MainWindowController.h"
#import "WelcomeWindowController.h"
#import "ShoutWindowController.h"
#import "CheckinWindowController.h"

#import "AvatarManager.h"
#import "FoursquareUpdater.h"

#import "NSPreferences.h"
#import "AppPreferences.h"

typedef void(^AuthCallback)(BOOL success);

@interface FoursquareXAppDelegate : NSObject <NSApplicationDelegate, GrowlApplicationBridgeDelegate, CLLocationManagerDelegate> {
	IBOutlet MainWindowController *mainWindowController;
    IBOutlet WelcomeWindowController *welcomeWindowController;
	IBOutlet ShoutWindowController *shoutWindowController;
	IBOutlet CheckinWindowController *checkinWindowController;
	
	IBOutlet FoursquareUpdater *updater;
	IBOutlet AvatarManager *avatarManager;
	
	IBOutlet NSMenu *statusItemMenu;
	IBOutlet NSMenuItem *locationMenuItem;
	IBOutlet NSMenuItem *quickCheckinMenuItem;
	IBOutlet NSMenuItem *shoutMenuItem;
	
	@private
	
	BOOL firstRun;
	
	BOOL appReady;
	BOOL mapReady;
	
	BOOL loadFinished;
	
	NSMutableArray *quickCheckinMenuItems;
	
	NSStatusItem *statusItem;
	
	NSTimer *timer;
	NSDate *lastFriendUpdate;
	NSDate *lastVenueUpdate;
	
	NSDate *lastSuggestion;
	
	NSNumber *myUserId;
	NSDictionary *currentCheckin;
	
	BOOL hasTwitter;
	BOOL hasFacebook;
	
	CWInterface *wifiInterface;
}

- (IBAction)showMainWindow:(id)sender;
- (IBAction)showQuickCheckinWindow:(id)sender;
- (IBAction)showShoutWindow:(id)sender;
- (IBAction)showPreferences:(id)sender;
- (IBAction)showAddFriends:(id)sender;
- (IBAction)showManageFriends:(id)sender;
- (IBAction)showAddVenue:(id)sender;
- (IBAction)refreshEverything:(id)sender;

- (void)changeUsername:(NSString *)username 
			  password:(NSString *)password
	 alertParentWindow:(NSWindow *)alertParentWindow
		 alertDelegate:(id)alertDelegate
			  callback:(AuthCallback)callback;

- (void)setMapReady;
- (void)finishLoading;
- (BOOL)isLoadFinished;

- (void)gotAvatar:(NSString *)path;

- (BOOL)isAccountConfigured;
- (CLLocation *)lastKnownLocation;

@property (readonly) NSDictionary *currentCheckin;
@property (readonly) CheckinWindowController *checkinWindowController;
@property (readonly) BOOL hasTwitter;
@property (readonly) BOOL hasFacebook;
@end
