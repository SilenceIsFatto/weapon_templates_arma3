class CfgPatches
{
	class YOURAPPEND_WeaponName
	{
		units[]={};
		weapons[]={"YOURAPPEND_WeaponName"};
		requiredVersion=0.1;
		requiredAddons[]={"A3_Weapons_F"};
	};
};
/// All firemodes, to be sure
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class WeaponSlotsInfo;

/// Weapon slots
class SlotInfo;
class MuzzleSlot;
class CowsSlot;
class PointerSlot;
class UnderBarrelSlot;
class Rifle_Base_F; // Replace this with the base class of whatever rifle you're copying off of

#include "cfgMagazines.hpp" /// specific magazines for this rifle
#include "cfgAmmo.hpp" /// specific ammo for this rifle

class CfgWeapons
{
	class WeaponName_Base: Rifle_Base_F // Your weapon inheriting off of rifle base class
	{
		magazines[] = {"", ""}; // We'll get onto these later
		descriptionShort = "";// Description of the weapon
        class Library {
        libtextdesc = "";//another description
        };
		descriptionUse = ""; // Name of the weapon
		reloadAction = ""; // Reload animation?
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

		handAnim[] = {"OFP2_ManSkeleton", "\A3\Weapons_F_Gamma\Smgs\pdw2000\data\Anim\SMG_03.rtm"}; // {"this is pointless to change","path\to\animationthatbestfitsyourweapon.rtm"}
		dexterity = 1.8;
		modes[] = {"FullAuto"}; /// Includes fire modes for AI, FullAuto, Single, Burst

    ////////////////////////////////////////////////////// NO OPTICS ///////////////////////////////////////////////////////////
	class FullAuto: Mode_FullAuto /// Pew
	{
			sounds[] = {StandardSound};
            class BaseSoundModeType
            {
                weaponSoundEffect  = "DefaultRifle";//DefaultHandgun
                closure1[] = {"A3\sounds_f\weapons\closure\closure_handgun_3", 0.235142, 1, 30};//"sound file", volume modifier, unknown, audible distance in meters
                closure2[] = {"A3\sounds_f\weapons\closure\closure_handgun_3", 0.235142, 1.100000, 30};
                soundClosure[] = {"closure1", 0.500000, "closure2", 0.500000};
            };
            class StandardSound: BaseSoundModeType
            {
                begin1[] = {"A3\sounds_f\weapons\SMG_02\SMG_02_st_1b", 1.010000, 1, 600};//"sound file", volume modifier, unknown, audible distance in meters
                begin2[] = {"A3\sounds_f\weapons\SMG_02\SMG_02_st_2b", 1.020000, 1, 600};
                begin3[] = {"A3\sounds_f\weapons\SMG_02\SMG_02_st_3b", 1.000000, 1, 600};
                soundBegin[] = {"begin1", 0.330000, "begin2", 0.330000, "begin3", 0.340000};//chance of sound playing. So 3 sounds = 33% each for a fair distribution.
            }; // Weapon sounds

			reloadTime = 0.096; /// means some 625 rounds per minute
			dispersion = 0.00087; /// A bit less than 3 MOA

            memoryPointCamera = "eye";//the named selection in our model.p3d's memory LOD to be used for the camera's position when in ADS view (Aim Down Sights)
			minRange = 10; minRangeProbab = 0.5; 	/// Task Force Balance black magic - this is the probability which AI thinks it would hit target at set range with
			midRange = 10; midRangeProbab = 0.7; 	/// it is no real probability of hit, just used for AI to compute if the shot is worth to take - AI chooses highest
			maxRange = 10; maxRangeProbab = 0.3; 	/// probability of the weapon, does some calculation and compares it with calculated probability of other weapons
		};
	};
	class YOURAPPEND_WeaponName: WeaponName_Base
	{
		scope = 2; /// should be visible and useable in game
		displayName = ""; /// Weapon Name
		model = ""; /// path to model

		picture = ""; // inventory picture
		UiPicture = ""; // inventory picture

		weaponInfoType = "RscWeaponZeroing"; /// display with zeroing is good for iron sights

		muzzles[] = {this}; /// to be able to switch between bullet muzzle and TGL
	};
};