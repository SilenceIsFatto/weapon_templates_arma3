// Anything that requires a file path (- textures in object builder) would be (e.g. a model path)
// \YOURAPPEND_WeaponName\pathtomodel
// do not put the .p3d file extension, this is the only circumstance,
 
// textures in object builder would be:
// YOURAPPEND_WeaponName\texturefile.fileformat
// Textures have to be in either .jpg (not .jpeg), or .paa formats!

class CfgPatches
{
	class YOURAPPEND_WeaponName_config
	{
		units[]={};
		weapons[]={"YOURAPPEND_WeaponName"};
		requiredVersion=0.1;
		requiredAddons[]={"A3_Weapons_F"};
	};
};
/// All firemodes
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
class Rifle_Base_F; // Replace this with the base class of whatever rifle you're copying off of, to do this, equip the gun you want to inherit off of. Then run this in the debug console:
// configname (inheritsFrom (configfile >> "cfgweapons" >> (primaryWeapon player)));
// This should output the base class. Replace ALL "Rifle_Base_F" instances in this script with the new base class.

#include "cfgMagazines.hpp"
#include "cfgAmmo.hpp"

class CfgWeapons
{
	class WeaponName_Base: Rifle_Base_F // Your weapon inheriting off of rifle base class
	{
		magazines[] = {"", ""};
		descriptionShort = "";
		class Library {
		libtextdesc = "";
		};
		descriptionUse = "";
		reloadAction = "";
		maxRecoilSway=0.0125;
        	swayDecaySpeed=1.25;
		inertia = 0.5;
		initSpeed = -1; /// this means that initSpeed of magazine is used
		opticsZoomMin=0.375;
		opticsZoomMax=1.1;
		opticsZoomInit=0.75;
		distanceZoomMin = 300;
		distanceZoomMax = 300;

		handAnim[] = {"OFP2_ManSkeleton", "\A3\Weapons_F_Gamma\Smgs\pdw2000\data\Anim\SMG_03.rtm"}; // {"this is pointless to change","path\to\animationthatbestfitsyourweapon.rtm"}
		// You can probably find the animation above by digging into the arma files.
		dexterity = 1.8;
		modes[] = {"FullAuto"}; // Includes fire modes

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
            };

			reloadTime = 0.096; /// means some 625 rounds per minute
			dispersion = 0.00087; /// A bit less than 3 MOA

            		memoryPointCamera = "eye";// the named selection in our model.p3d's memory LOD
			minRange = 10; minRangeProbab = 0.5;
			midRange = 10; midRangeProbab = 0.7;
			maxRange = 10; maxRangeProbab = 0.3;
		};
	};
	class YOURAPPEND_WeaponName: WeaponName_Base
	{
		scope = 2; // 0 = not usable at all, 1 = usable but not visible, 2 = visible
		displayName = ""; // Weapon Name
		model = ""; // Path to model

		picture = ""; // inventory picture
		UiPicture = ""; // inventory picture

		weaponInfoType = "RscWeaponZeroing";

		muzzles[] = {this};
	};
};
