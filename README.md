CLLocation-AccuracyLevel
========================

CLLocation+AccuracyLevel assigns a geographic accuracy level to any given placemark using the categories defined in the CLLocationAccuracyLevel enum.

The CLLocationAccuracyLevel enum mimics the available properties of a CLPlacemark object. In other words, a CLLocationAccuracyLevel is assigned based on the availability of those properties for a given MK/CLPlacemark object (e.g. if subThroughfare == nil, then CLLocationAccuracyLevel must be CLLocationAccuracyLevelThroughfare or higher).
 
Support for CLRegion or CLCircularRegion may come in a future release.
