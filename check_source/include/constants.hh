#ifndef constants_h
#define constants_h 1

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "Geometry.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4VPhysicalVolume.hh"
#include "G4SubtractionSolid.hh"
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"
#include "G4Transform3D.hh"
#include "G4NistManager.hh"
#include "G4VisAttributes.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4SDManager.hh"
#include "G4String.hh"
#include "G4SystemOfUnits.hh"
// #include "G4Version.hh"

// If you want to use GEANT4 version 11, commment out the line #define G4VERSION_NUMBER 1073
// #define G4VERSION_NUMBER 1073

// Here switch on/off FoCal-E/H
constexpr G4bool UseFoCalE = true;
constexpr G4bool UseFoCalH = false;

// Choose which setup to use for FoCal-E:
//   true = tungsten in front of PAD and PIXELs
//   false = default
constexpr G4bool UseModifiedSetup = false;

//=================================================================
//       World parameters and placement of the FoCal
//=================================================================
constexpr G4double World_X = 20.0 * m;   // X-full-length of world
constexpr G4double World_Y = 20.0 * m;   // Y-full-length of world
constexpr G4double World_Z = 1000.0 * m; // Z-full-length of world
// Starting position of the FoCal detector
constexpr G4double Start_Z = 260.0 * mm; // Start from interaction point
constexpr G4double Start_X = 0.0 * mm;   // Reference for the beam pipe
constexpr G4double Start_Y = 0.0 * mm;   // Reference for the beam pipe
//=================================================================
//                  Focal-E parameters
//=================================================================
constexpr G4int NumberPAD = 1; // 18 //7
constexpr G4int NumberPIX = 0; // 2 //0
//=================================================================
// Default FoCal-E setup parameters
constexpr G4int NumberOfLayers = 5; // This parameter is just the input of LayerLayout. If there are n entries in that function then put n. for ex. if there are 0,0,2. then put 3 here.

constexpr G4int LayerLayout[NumberOfLayers] = { 0, 0, 0, 0, 2 };
//=================================================================
// Modified FoCal-E setup parameters
constexpr G4int NumberW = 5; // <-- Change this to get 5 or 10 tungsten layers in front
constexpr G4double GapW = 5.0 * mm;
constexpr G4double GapBtwWandPad = 113. * mm;
constexpr G4double GapBtwPadAndPixel = 117. * mm; // 230*mm - 113*mm
//=================================================================
// Tungsten & aluminum (PIX)
constexpr G4double WidthW = 90.3 * mm;
constexpr G4double WidthAl = 90.3 * mm;
//=================================================================
// PIX detector
constexpr G4int NalpideLayer = 0; // Alpide layers inside aluminum plates (number of half-layers in one layer)
constexpr G4int NpixX = 1024;     // 90
constexpr G4int NpixY = 512;      // 84
constexpr G4int NumberPixRow = 3;
constexpr G4int NumberPixCol = 3;
constexpr G4double PIX_X = 0.02924 * mm;
constexpr G4double PIX_Y = 0.02688 * mm;
constexpr G4double PIX_Z = 0.05 * mm;
constexpr G4double PIX_Alpide_X = 30.1 * mm;
constexpr G4double PIX_Alpide_Y = 13.763 * mm;
constexpr G4double PIX_Flex_X = 90.3 * mm;
constexpr G4double PIX_Flex_Y = 11.25 * mm;
constexpr G4double GapBtwPixelStrips = PIX_Alpide_Y - PIX_Flex_Y;
constexpr G4double PIX_And_Flex_length = PIX_Alpide_Y + PIX_Flex_Y + GapBtwPixelStrips;
constexpr G4double PIX_Full_Length = 3 * PIX_And_Flex_length;
constexpr G4double PIX_Full_Width = 3 * PIX_Alpide_X;
constexpr G4double PIX_Layers_Offset = 1. * mm;

// Thicknesses
constexpr G4double PIX_Absorber_Z = 3.5 * mm;     // original 3.5 mm (change here for the absorber thickness)
constexpr G4double PIX_AirGap_AlPlates = 2. * mm; // This airgap is between the aluminum plates
constexpr G4double PIX_AirGap = 1.2 * mm;
constexpr G4double PIX_Al_Z = 1.5 * mm;
constexpr G4double PIX_Layer_Thickness = 2 * PIX_Al_Z + PIX_AirGap_AlPlates;
// Plate size
constexpr G4double PIX_GuardRingThickness = 0.00 * mm;
constexpr G4double PIX_MiniFoCal_X = ((PIX_X * NpixX) + 2 * PIX_GuardRingThickness) * mm;
constexpr G4double PIX_MiniFoCal_Y = ((PIX_Y * NpixY) + 2 * PIX_GuardRingThickness) * mm;
//=================================================================
// PAD detector
constexpr G4int NpadX = 9;
constexpr G4int NpadY = 8;
constexpr G4double PAD_X = 10 * mm;
constexpr G4double PAD_Y = 10 * mm;
constexpr G4double PAD_Z_active = 0.30 * mm;
constexpr G4double PAD_Z_inactive = 0.02 * mm;
constexpr G4double PAD_Z = PAD_Z_active + PAD_Z_inactive; // PAD_Z = 0.32*mm;

// Overall materials
// Thicknesses
constexpr G4double PAD_Absorber_Z_Last = 10.0 * mm; //
constexpr G4double PAD_Absorber_Z = 3.5 * mm;
constexpr G4double PAD_Glue1_Z = 0.11 * mm; // between W-Si
constexpr G4double PAD_Glue2_Z = 0.13 * mm; // between Si+FPC
constexpr G4double PAD_FPC_Z = 0.28 * mm;
constexpr G4double PAD_AirGap = 1.2 * mm;
constexpr G4double PAD_Layer_Thickness_mod = PAD_Z + PAD_Glue2_Z + PAD_FPC_Z;
constexpr G4double PAD_Layer_Thickness = PAD_Glue1_Z + PAD_Z + PAD_Glue2_Z + PAD_FPC_Z;
// Plate size
constexpr G4double PAD_GuardRingThickness = 0.00 * mm;
constexpr G4double PAD_MiniFoCal_X = ((PAD_X * NpadX) + 2 * PAD_GuardRingThickness) * mm;
constexpr G4double PAD_MiniFoCal_Y = ((PAD_Y * NpadY) + 2 * PAD_GuardRingThickness) * mm;

//=================================================================
//                  Focal-H parameters
//=================================================================
constexpr G4int N_HCAL_Module_X = 3;
constexpr G4int N_HCAL_Module_Y = 3;

constexpr G4int NtowerX = 24;
constexpr G4int NtowerY = 28;

constexpr G4double Tower_dx = 64.75 * mm; // Realistic: Tower_dx = 65.5*mm; Ideal: Tower_dx = 64.75*mm; // X-full-length of Outer Dimensions of HCAL box
constexpr G4double Tower_dy = 64.75 * mm; // Realistic: Tower_dy = 65.5*mm; Ideal: Tower_dy = 64.75*mm; // Y-full-length of Outer Dimensions of HCAL box
constexpr G4double Tower_dz = 1100. * mm; // Ideal: Tower_dz = 1100.*mm; // Z-full-length of Outer Dimensions of HCAL box

constexpr G4double Tower_ID_dx = 61.75 * mm; // Realistic: Tower_ID_dx = 62.5*mm; Ideal: Tower_ID_dx = 61.75*mm; // X-full-length of Inner Dimensions of HCAL box
constexpr G4double Tower_ID_dy = 61.75 * mm; // Realistic: Tower_ID_dy = 62.5*mm; Ideal: Tower_ID_dy = 61.75*mm; // Y-full-length of Inner Dimensions of HCAL box
constexpr G4double Tower_ID_dz = 1100. * mm; // Ideal: Tower_ID_dz = 1100.*mm; // Z-full-length of Inner Dimensions of HCAL box

constexpr G4double GapBtwHcalModules_x = 0.; // Realistic: GapBtwHcalModules_x = 0.65*mm;
constexpr G4double GapBtwHcalModules_y = 0.; // Realistic: GapBtwHcalModules_y = 1.65*mm;

constexpr G4double HCAL_Placement_X = 0.;
constexpr G4double HCAL_Placement_Y = 0.;
constexpr G4double HCAL_Placement_Z = 0.;

constexpr G4double HCAL_Rot_X = 0.;
constexpr G4double HCAL_Rot_Y = 2.085 * deg;
constexpr G4double HCAL_Rot_Z = 0.;

constexpr G4double GapBtwEcalAndHcal = 15. * mm;

//=================================================================
//                  ID numbers calculated
//=================================================================
constexpr G4int IDnumber_PAD_First = 1;
// constexpr G4int IDnumber_PAD_First1	 = 1;
constexpr G4int IDnumber_PAD_First1 = NpadX * NpadY * (NumberPAD - 1) + 1;
constexpr G4int IDnumber_PIX_First = NpadX * NpadY * NumberPAD + 1;
constexpr G4int IDnumber_SCINT_First = NpadX * NpadY * NumberPAD + NalpideLayer * NumberPixRow * NumberPixCol * NumberPIX + 1;

#endif
