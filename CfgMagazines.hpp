class CfgMagazines
{
	class Default;

	class CA_Magazine;

	class WeaponName_magcountrnd: CA_Magazine 
	{
		scope = 2; /// or 2, to be precise
		displayName = "Name Of Mag";
		picture = ""; // Icon in inventory/arsenal
		ammo = B_Test_Caseless; // defined in cfgAmmo.hpp
		count = ; // ammo count
		initSpeed = 1200; /// standard muzzle speed
		tracersEvery = 0; // 0 = no tracers, 1 = tracers every shot
		lastRoundsTracer = 3; /// tracers to track low ammo
		descriptionShort = "Used To Shoot People"; /// on mouse-over in Inventory
		magazineGroup[]	= {"test_mag_group"}; /// all magazines in the same group may be used in weapon that has the group defined as compatible
	};
};
