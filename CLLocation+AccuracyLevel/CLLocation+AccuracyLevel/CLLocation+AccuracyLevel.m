//
//  CLLocation+AccuracyLevel.h
//
//  Created by Joe Wei Bosco "Boz" Ho on 2013-08-03.
//  Copyright (c) 2013 Joe Wei Bosco "Boz" Ho. All rights reserved.
//

#import "CLLocation+AccuracyLevel.h"

@implementation CLLocation (AccuracyLevel)

+ (CLLocationAccuracyLevel)accuracyLevelForMapItem:(MKMapItem *)aMapItem {
    CLPlacemark* placemark = aMapItem.placemark;
    CLLocationAccuracyLevel accuracyLevel = [self determineAccuracyLevelUsingCLPlacemark:placemark];
    return accuracyLevel;
}

+ (CLLocationAccuracyLevel)accuracyLevelForPlacemark:(CLPlacemark *)aPlacemark {
    CLLocationAccuracyLevel accuracyLevel = [self determineAccuracyLevelUsingCLPlacemark:aPlacemark];
    return accuracyLevel;
}

+ (CLLocationAccuracyLevel)accuracyLevelForRegion:(CLRegion *)aRegion {
    //    CLLocationDistance regionRadius = aRegion.radius;
    return CLLocationAccuracyLevelUnknown;
}

+ (CLLocationAccuracyLevel)accuracyLevelForCircularRegion:(CLCircularRegion *)aCircularRegion {
    //    CLLocationDistance regionRadius = aCircularRegion.radius;
    return CLLocationAccuracyLevelUnknown;
}

#pragma mark - PRIVATE METHODS
+ (CLLocationAccuracyLevel)determineAccuracyLevelUsingCLPlacemark:(CLPlacemark*)aCLPlacemark {
    
    if (nil != aCLPlacemark.subThoroughfare) {
        return CLLocationAccuracyLevelSubThroughfare;
    }
    else if (nil != aCLPlacemark.thoroughfare) {
        return CLLocationAccuracyLevelThroughfare;
    }
    else if (nil != aCLPlacemark.subLocality) {
        return CLLocationAccuracyLevelSubLocality;
    }
    else if (nil != aCLPlacemark.locality) {
        return CLLocationAccuracyLevelLocality;
    }
    else if (nil != aCLPlacemark.subAdministrativeArea) {
        return CLLocationAccuracyLevelSubAdministrativeArea;
    }
    else if (nil != aCLPlacemark.administrativeArea) {
        return CLLocationAccuracyLevelAdministrativeArea;
    }
    else if (nil != aCLPlacemark.country) {
        return CLLocationAccuracyLevelCountry;
    }
    
    return CLLocationAccuracyLevelUnknown;
}

/*
+ (CLLocationAccuracyLevel)determineAccuracyLevelUsingRegionRadius:(CLLocationDistance)aRegionRadius {
    
    if (aRegionRadius < 50) {
        return CLLocationAccuracyLevelSubThroughfare;
    }
    else if (aRegionRadius) {
        return CLLocationAccuracyLevelThroughfare;
    }
    else if (aRegionRadius) {
        return CLLocationAccuracyLevelSubLocality;
    }
    else if (aRegionRadius) {
        return CLLocationAccuracyLevelLocality;
    }
    else if (aRegionRadius) {
        return CLLocationAccuracyLevelSubAdministrativeArea;
    }
    else if (aRegionRadius) {
        return CLLocationAccuracyLevelAdministrativeArea;
    }
    else if (aRegionRadius) {
        return CLLocationAccuracyLevelCountry;
    }
    
    return CLLocationAccuracyLevelUnknown;
}
 */

@end
