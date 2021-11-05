class CfgPatches
{
    class MS_LMTAR15Config
	{
		requiredaddons[] = {"A3_Weapons_F"};
		requiredversion = 0.1;
		units[] = {};
		weapons[] = {"MS_LMTAR15"};
		magazines[] = {""};
    };
};
/*
class cfgVehicles
{
	class Headgear_Base_F;
    class MS_LMTAR15: Headgear_Base_F
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "LMT Defender AR-15";
        author = "Silence";
        vehicleClass = ItemsHeadgear;
        model = "\MS_AR15\LMTAR15_Standard";
        class TransportItems
        {
            class MS_Weapon_AR15
            {
                name = MS_Weapon_AR15;
                count = 1;
            };
        };
    };
};
*/

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class WeaponSlotsInfo;

class ItemCore;
class SlotInfo;
class MuzzleSlot;
class CowsSlot;
class PointerSlot;
class UnderBarrelSlot;
class Rifle_Base_F;

class GripodSlot;
class asdg_SlotInfo;
class asdg_FrontSideRail;
class asdg_OpticRail1913;
class asdg_OpticRail1913_short;
class asdg_UnderSlot;
class asdg_MuzzleSlot;
class asdg_MuzzleSlot_556;

class cfgWeapons
{
	class hlc_AR15_base;
	class hlc_G36_base; // arifle_SPAR_01_base_F;
	class AR15_Base: hlc_AR15_base// arifle_SPAR_01_base_F /// Just basic values common for all testing rifle variants
	{
		magazines[] = {""}; /// original custom made magazines and a group of several standardized mags
		descriptionShort = "A clean rifle developed by Armalite";//tooltip text
        class Library {
        libtextdesc = "A clean rifle developed by Armalite";//another description
        };
		descriptionUse = "Armalite";
		reloadAction = "GestureReloadMX"; /// MX hand animation actually fits this rifle well
		// Size of recoil sway of the cursor
		maxRecoilSway=0.0125;
        // Speed at which the recoil sway goes back to zero (from maxRecoilSway to 0 in 1/swayDecaySpeed seconds)
        swayDecaySpeed=1.25;
		/// inertia coefficient of the weapon
		inertia = 0.5;
		/// positive value defines speed of the muzzle independent on the magazine setting, negative value is a coefficient of magazine initSpeed
		initSpeed = -1; /// this means that initSpeed of magazine is used
/////////////////////////////////////////////////////  I R O N S I G H T S  /////////////////////////////////////////////////////
		opticsZoomMin=0.375;
		opticsZoomMax=1.1;
		opticsZoomInit=0.75;
		distanceZoomMin = 300;
		distanceZoomMax = 300;
/////////////////////////////////////////////////////  I R O N S I G H T S  /////////////////////////////////////////////////////

		handAnim[] = {"OFP2_ManSkeleton", "\a3\weapons_f_exp\Rifles\SPAR_01\data\Anim\SPAR_01.rtm"}; /// MX hand animation actually fits this rifle well
		dexterity = 1.8;
		modes[] = {"FullAuto", "Semi"}; /// Includes fire modes for AI

    ////////////////////////////////////////////////////// NO OPTICS ///////////////////////////////////////////////////////////
	class Semi: Mode_SemiAuto /// Pew
	{
		sounds[] = {StandardSound};
		class BaseSoundModeType
		{
		weaponSoundEffect  = "DefaultRifle";//DefaultHandgun
		closure1[] = {"A3\sounds_f\weapons\closure\closure_rifle_1", 0.235142, 1, 30};//"sound file", volume modifier, unknown, audible distance in meters
		closure2[] = {"A3\sounds_f\weapons\closure\closure_rifle_2", 0.235142, 1.100000, 30};
		soundClosure[] = {"closure1", 0.500000, "closure2", 0.500000};
		};
		class StandardSound: BaseSoundModeType
		{
			begin1[] = {"A3\sounds_f\weapons\EBR\EBR_st_4", 1.010000, 1, 600};//"sound file", volume modifier, unknown, audible distance in meters
			begin2[] = {"A3\sounds_f\weapons\EBR\EBR_st_5", 1.020000, 1, 600};
			begin3[] = {"A3\sounds_f\weapons\EBR\EBR_st_6", 1.000000, 1, 600};
			soundBegin[] = {"begin1", 0.330000, "begin2", 0.330000, "begin3", 0.340000};//chance of sound playing. So 3 sounds = 33% each for a fair distribution.
        };
		class SilencedSound: BaseSoundModeType // Sounds inside this class are used when soundTypeIndex = 1, according to sounds[]
		{
			begin1[] = { "A3\sounds_f\weapons\silenced\silent-07", db-1, 1, 200 };
			begin2[] = { "A3\sounds_f\weapons\silenced\silent-08", db-1, 1, 200 };
			soundBegin[] = { begin1, 0.5, begin2, 0.5 };
		};
		reloadTime = 0.096; /// means some 625 rounds per minute
		dispersion = 0.00087; /// A bit less than 3 MOA

        memoryPointCamera = "eye";//the named selection in our model.p3d's memory LOD to be used for the camera's position when in ADS view (Aim Down Sights)
		minRange = 10; minRangeProbab = 0.5; 	/// Task Force Balance black magic - this is the probability which AI thinks it would hit target at set range with
		midRange = 10; midRangeProbab = 0.7; 	/// it is no real probability of hit, just used for AI to compute if the shot is worth to take - AI chooses highest
		maxRange = 10; maxRangeProbab = 0.3; 	/// probability of the weapon, does some calculation and compares it with calculated probability of other weapons
	};
	class Full: Mode_FullAuto /// Pew
	{
		sounds[] = {StandardSound};
		class BaseSoundModeType
		{
		weaponSoundEffect  = "DefaultRifle";//DefaultHandgun
		closure1[] = {"A3\sounds_f\weapons\closure\closure_rifle_1", 0.235142, 1, 30};//"sound file", volume modifier, unknown, audible distance in meters
		closure2[] = {"A3\sounds_f\weapons\closure\closure_rifle_2", 0.235142, 1.100000, 30};
		soundClosure[] = {"closure1", 0.500000, "closure2", 0.500000};
		};
		class StandardSound: BaseSoundModeType
		{
			begin1[] = {"A3\sounds_f\weapons\EBR\EBR_st_4", 1.010000, 1, 600};//"sound file", volume modifier, unknown, audible distance in meters
			begin2[] = {"A3\sounds_f\weapons\EBR\EBR_st_5", 1.020000, 1, 600};
			begin3[] = {"A3\sounds_f\weapons\EBR\EBR_st_6", 1.000000, 1, 600};
			soundBegin[] = {"begin1", 0.330000, "begin2", 0.330000, "begin3", 0.340000};//chance of sound playing. So 3 sounds = 33% each for a fair distribution.
        };
		class SilencedSound: BaseSoundModeType // Sounds inside this class are used when soundTypeIndex = 1, according to sounds[]
		{
			begin1[] = { "A3\sounds_f\weapons\silenced\silent-07", db-1, 1, 200 };
			begin2[] = { "A3\sounds_f\weapons\silenced\silent-08", db-1, 1, 200 };
			soundBegin[] = { begin1, 0.5, begin2, 0.5 };
		};
		reloadTime = 0.096; /// means some 625 rounds per minute
		dispersion = 0.00087; /// A bit less than 3 MOA

        memoryPointCamera = "eye";//the named selection in our model.p3d's memory LOD to be used for the camera's position when in ADS view (Aim Down Sights)
		minRange = 10; minRangeProbab = 0.5; 	/// Task Force Balance black magic - this is the probability which AI thinks it would hit target at set range with
		midRange = 10; midRangeProbab = 0.7; 	/// it is no real probability of hit, just used for AI to compute if the shot is worth to take - AI chooses highest
		maxRange = 10; maxRangeProbab = 0.3; 	/// probability of the weapon, does some calculation and compares it with calculated probability of other weapons
	};
};
	class MS_LMTAR15: AR15_Base
	{
		scope = 2; /// should be visible and useable in game
		displayName = "AR-15 (Black)"; /// some name
		model = "\MS_AR15\LMTAR15_Standard"; /// path to model

		picture = "\MS_PR\ms_logo.jpg"; /// different accessories have M, S, T instead of X
		UiPicture = "\MS_PR\ms_logo.jpg"; /// weapon with grenade launcher should be marked such way

		weaponInfoType = "RscWeaponZeroing"; /// display with zeroing is good for iron sights

		muzzles[] = {this}; /// to be able to switch between bullet muzzle and TGL
		allowedslots[]={901};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=70.3;
			class MuzzleSlot: asdg_MuzzleSlot_556 {};
            class CowsSlot: asdg_OpticRail1913 {};
			class UnderBarrelSlot: asdg_UnderSlot{};
		};
	};
};