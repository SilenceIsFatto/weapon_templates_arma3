class CfgMagazines
{
	class Default;

	class CA_Magazine;

	class 17rnd_glock_mag: CA_Magazine 
	{
		scope = 2; /// or 2, to be precise
		displayName = "Glock Mag (17)";
		picture = "\MS_x26tazer\ms_logo.jpg"; /// just some icon
		ammo = "B_Glock_Caseless";
		count = 17; /// 30 rounds is enough
		initSpeed = 800; /// standard muzzle speed
		tracersEvery = 0; /// disable tracers by default
		lastRoundsTracer = 1; /// tracers to track low ammo
		descriptionShort = "Used to shoot people!"; /// on mouse-over in Inventory
		magazineGroup[]	= {"test_mag_group"}; /// all magazines in the same group may be used in weapon that has the group defined as compatible
	};
	class 21rnd_glock_mag: CA_Magazine 
	{
		scope = 2; /// or 2, to be precise
		displayName = "Glock Mag (21)";
		picture = "\MS_x26tazer\ms_logo.jpg"; /// just some icon
		ammo = "B_Glock_Caseless";
		count = 21; /// 30 rounds is enough
		initSpeed = 800; /// standard muzzle speed
		tracersEvery = 0; /// disable tracers by default
		lastRoundsTracer = 1; /// tracers to track low ammo
		descriptionShort = "Used to shoot people!"; /// on mouse-over in Inventory
		magazineGroup[]	= {"test_mag_group"}; /// all magazines in the same group may be used in weapon that has the group defined as compatible
	};
	class 33rnd_glock_mag: CA_Magazine 
	{
		scope = 2; /// or 2, to be precise
		displayName = "Glock Mag (33)";
		picture = "\MS_x26tazer\ms_logo.jpg"; /// just some icon
		ammo = "B_Glock_Caseless";
		count = 33; /// 30 rounds is enough
		initSpeed = 800; /// standard muzzle speed
		tracersEvery = 0; /// disable tracers by default
		lastRoundsTracer = 1; /// tracers to track low ammo
		descriptionShort = "Used to shoot people!"; /// on mouse-over in Inventory
		magazineGroup[]	= {"test_mag_group"}; /// all magazines in the same group may be used in weapon that has the group defined as compatible
	};
};
/*
	class 30Rnd_test_mag_Tracer: 30Rnd_test_mag /// a magazine full of tracer rounds
	{
		tracersEvery = 1; /// moar tracers
		lastRoundsTracer = 30; /// tracers everywhere
		displayName = "Test tracer magazine";
		descriptionShort = "Used to shoot test tracer bullets";
		displaynameshort = "Tracers";
		magazineGroup[]	= {"test_mag_group"};
	};
};
/*