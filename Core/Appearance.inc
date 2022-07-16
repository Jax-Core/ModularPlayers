[Variables]
Sec.SaveLocation=#SKINSPATH##SKin.Name#\Main\Vars\#Style#.inc
Sec.SaveLocation2=#SKINSPATH##SKin.Name#\@Resources\Vars.inc
Sec.AnchorName=AnchorSuppli
@includePlayerVars=#SKINSPATH##SKin.Name#\Main\Vars\#Style#.inc

;================================================================================================================================================================================

[Options]
Meter=String
Text=General options
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
Text=Widget scale
MeterStyle=Set.String:S | Set.OptionName:S

[AdditionalOptions]
Meter=String
Text="#Style#" style options
MeterStyle=Set.String:S | Set.OptionCat:S

@includeCoreAppearanceStyles=#SKINSPATH##SKin.Name#\Core\AppearanceStyles\#Style#.inc