#include "cfgMagazines.hpp" /// specific magazines for this rifle
#include "cfgAmmo.hpp" /// specific ammo for this rifle
class CfgPatches
{
    class ms_glock
	{
		requiredaddons[] = {};
		requiredversion = 0.1;
		units[] = {};
		weapons[] = {"MS_Glock17"};
		magazines[] = {"17rnd_glock_mag", "21rnd_glock_mag", "33rnd_glock_mag"};
    };
};
class Mode_SemiAuto;//importing an external class as we use the Mode_SemiAuto below
class CfgWeapons//beginning of our cfgWeapons entry
{
    class ItemCore;
    class PistolCore;   // External class reference
    class Pistol;       // External class reference
    class Pistol_Base_F;
    class WeaponSlotsInfo;
    class SlotInfo;
    class ItemInfo;
    class MS_Glock17: Pistol_Base_F //slaves off Arma's Pistol_Base_F class. The values defined below overwrite Pistol_Base_F, anything not defined is inherited. Consult the wiki/sample content for a full config with every possible value.
    {
        scope = 2;
        displayName = "Glock 17";//Our item's name in the UI
        model = "\MS_Glock\glock";//relative path to the p3d file. The p3d suffix is likely unnecessary.
        picture = "\MS_x26tazer\ms_logo.jpg";//UI image.
        magazines[] = {"17rnd_glock_mag", "21rnd_glock_mag", "33rnd_glock_mag"};//list of magazines this weapon takes
        descriptionShort = "A pistol employed by law enforcement around the world";//tooltip text
        class Library {
            libtextdesc = "A pistol employed by law enforcement around the world";//another description
        };
		hiddenSelections[] = {"gun", "magazine"};
		hiddenSelectionsTextures[] = {"ms_glock\Glock_Albedo.jpg", "ms_glock\Mag_Albedo.jpg"};
        descriptionUse = "Glock 17";
        reloadMagazineSound[] = {"A3\sounds_f\weapons\Reloads\pistols", 0.300000, 1, 50};//the first (0.3) number is the sound's loudness, while the last number is it's audible distance in meters.
        drySound[] = {"A3\sounds_f\weapons\other\dry1", 0.330957, 1, 80};//sound played when the magazine is dry (empty).
        inertia = 0.60000;//Inertia value of the weapon — higher values = greater inertia. Weapons with a greater amount of weight towards their front should have higher inertia, like an M1 Garand compared to an MP5. 
        initSpeed = -1.02;//This is a 2% increase in the ammo's velocity for this weapon. This allows weapons with longer/better barrels to fire the same ammo as other weapons yet at a different muzzle velocity. A 2% decrease would be = -0.98;
        recoil = "recoil_pistol_rook40";//recoil profile defined in arma's weapon config, or a custom profile defined in this file's CfgRecoils
        modes[] = {"Single"};//firemodes like Single, FullAuto
        muzzles[] = {"this"};//muzzles. Used for things like underbarrel grenade launchers or in this case a faked safety. If we give a muzzle no magazines to use it cannot fire, this mimicks a safety.
        class Single : Mode_SemiAuto
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
			class SilencedSound : BaseSoundModeType {
				begin1[] = {"A3\Sounds_F\arsenal\weapons\Pistols\Acpc2\Silencer_Acpc2_short_01", 0.562341, 1, 600};
				begin2[] = {"A3\Sounds_F\arsenal\weapons\Pistols\Acpc2\Silencer_Acpc2_short_02", 0.562341, 1, 600};
				begin3[] = {"A3\Sounds_F\arsenal\weapons\Pistols\Acpc2\Silencer_Acpc2_short_03", 0.562341, 1, 600};
				soundBegin[] = {"begin1", 0.33, "begin2", 0.33, "begin3", 0.34};
			};
            reloadTime = 0.100000;//NOT the time to reload the magazine but the time in seconds between shots. It would more appropriately be called cycleTime.
            dispersion = 0.007000;//Accuracy. Lower values are higher accuracy. To find a realistic value you should consider your weapon's barrel length and quality and compare it to values from A3's weapons, plus test in-game.
            memoryPointCamera = "eye";//the named selection in our model.p3d's memory LOD to be used for the camera's position when in ADS view (Aim Down Sights)
			minRange = 10; minRangeProbab = 0.5; 	/// Task Force Balance black magic - this is the probability which AI thinks it would hit target at set range with
			midRange = 10; midRangeProbab = 0.7; 	/// it is no real probability of hit, just used for AI to compute if the shot is worth to take - AI chooses highest
			maxRange = 10; maxRangeProbab = 0.3; 	/// probability of the weapon, does some calculation and compares it with calculated probability of other weapons
        };
        class WeaponSlotsInfo : WeaponSlotsInfo
        {
            holsterOffset = "holster";//named selection in the Memory LOD for the pistol's position when holstered. If not included the center is used. (Center of scene I believe, not center of geo)
            holsterScale = 1;//scale of model in holster
            mass = 20;
            allowedSlots[] = {701,801,901};//what storage slots this item can "fit" in — clothing (701), vest(801), backpack(901).
            class MuzzleSlot : SlotInfo
            {
                linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
                compatibleItems[] = {"hlc_muzzle_evo40", "hlc_muzzle_octane45"};//What items (classname) can be used in our weapon's MuzzleSlot (the model's center point is placed on the weapon's MuzzleProxy).
            };
            class CowsSlot : SlotInfo//Top / optic slot
            {
                linkProxy = "\a3\data_f\proxies\weapon_slots\top";
                compatibleItems[] = {"hlc_optic_docterv", "hlc_optic_romeov"};
            };
            class PointerSlot : SlotInfo//side slot
            {
				linkProxy = "\a3\data_f\proxies\weapon_slots\SIDE";
                compatibleItems[] = {"hlc_acc_dbalpl","hlc_acc_dbalpl_fl", "acc_flashlight_pistol"};
            };
        };
    };
};