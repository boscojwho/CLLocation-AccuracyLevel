//
//  CLLocation+AccuracyLevel.h
//
//  Created by Joe Wei Bosco "Boz" Ho on 2013-08-03.
//  Copyright (c) 2013 Joe Wei Bosco "Boz" Ho. All rights reserved.
//

/*
 ABSTRACT: CLLocation+AccuracyLevel categorizes the geographic accuracy level of a given placemark or region into one of the CLLocationAccuracyLevel enum values.

 The CLLocationAccuracyLevel enum mimics the available properties of a CLPlacemark object. In other words, a CLLocationAccuracyLevel is assigned based on the availability of those properties for a given MK/CLPlacemark object (e.g. if subThroughfare == nil, then CLLocationAccuracyLevel must be CLLocationAccuracyLevelThroughfare or higher).
 
 Support for CLRegion or CLCircularRegion may come in a future release.
 
 (If you pass in a CLRegion or CLCircularRegion (iOS 7.0 or higher), a CLLocationAccuracyLevel is determined using the radius property, and rather arbitrarily categorized into one of the CLLocationAccuracyLevel enum values.  Therefore, it is recommended that you pass in an MKMapItem or MK/CLPlacemark to maximize the usefulness of CLLocation+AccuracyLevel.)
 */

#import <CoreLocation/CoreLocation.h>

#import <MapKit/MapKit.h>

@interface CLLocation (AccuracyLevel)

typedef NS_ENUM(NSUInteger, CLLocationAccuracyLevel) {
    
    CLLocationAccuracyLevelUnknown                  = 0,
    
    // See Apple's CLPlacemark documentation for details.
    CLLocationAccuracyLevelSubThroughfare           = 10,   // Building number-level accuracy. (e.g. 1 Wall Street).
    CLLocationAccuracyLevelThroughfare              = 20,   // Street-level accuracy. (e.g. Wall Street).
    CLLocationAccuracyLevelSubLocality              = 30,   // Neighbourhood-level accuracy (e.g. Uptown).
    CLLocationAccuracyLevelLocality                 = 40,   // Municipality-level accuracy (e.g. a New York borough).
    CLLocationAccuracyLevelSubAdministrativeArea    = 50,   // Metropolitan area-level accuracy (e.g. Greater Vancouver).
    CLLocationAccuracyLevelAdministrativeArea       = 60,   // State, province, or prefecture.
    CLLocationAccuracyLevelCountry                  = 70,   // America, or it's 51st state (Canada).
    
    // Just for fun (feel free to delete if this takes up too much space in Xcode autocomplete).
    CLLocationAccuracyLevelPlanetary                = 80,   // e.g. Pluto
    CLLocationAccuracyLevelSolarSystem              = 90,   // e.g. Alpha Centauri AB
    CLLocationAccuracyLevelGalaxy                   = 100,  // e.g. Milky Way
    CLLocationAccuracyLevelUniverse                 = 110   // e.g. The one you're in. Or your own little meta-physical universe =P.
};

+ (CLLocationAccuracyLevel)accuracyLevelForMapItem:(MKMapItem*)aMapItem;
+ (CLLocationAccuracyLevel)accuracyLevelForPlacemark:(CLPlacemark*)aPlacemark;

+ (CLLocationAccuracyLevel)accuracyLevelForRegion:(CLRegion*)aRegion NS_UNAVAILABLE; //__OSX_AVAILABLE_BUT_DEPRECATED(__MAC_NA, __MAC_NA, __IPHONE_7_0, __IPHONE_7_0)
+ (CLLocationAccuracyLevel)accuracyLevelForCircularRegion:(CLCircularRegion*)aCircularRegion NS_UNAVAILABLE; //__OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_7_0)
@end
