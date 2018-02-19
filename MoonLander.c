#include <stdio.h>
#include <stdlib.h>


				//Moon lander Sumulation V0.1. Converted From original RadioShack EC-4020 calculator booklet - Tom Harkness Oct2016
/*
The program begins at an ALtitude of 2350 feet, falling at speed of -470 feet/second with 600lbs of fuel.
	*Acceleration due to gravity formula:	 	5 ft/sec^2
	*For every pound of fuel burned - speed will decrease by 1 foot/second.
		(NOTE- This means you need to burn at least 5lbs of fuel each time to maintain speed against gravity)

*/
	int Fuel = 600;
	int Altitude = 2350;
	int Speed = -470;
	int FuelBurned;
	int CrashFromNoFuelSpeed;

void ClearScreen()
{
	int x;
	for(x = 0; x < 10; x++)
	{
		printf("\n\n\n");
	}
}

int EnterBurn()				//Display Speed and Fuel, prompt for Amount of Fuel to Burn and store the ammount burned in FuelBurned
{
	
	ClearScreen();
	printf("Fuel:       ");
	printf(" %d", Fuel);	
	printf(" lbs\n");
	printf("Altitude:  ");
	printf("%d", Altitude);
	printf(" feet\n");
	printf("Speed:   ");
	printf("%d", Speed);	
	printf(" feet/sec\n");
	printf("Burn:  ");
	scanf("%d", &FuelBurned);						//Prompts player to enter ammount of fuel to burn and stores in variable D
		
		if(FuelBurned < 0)							//If fuel burned is less than 0, go back to burn
			{
				EnterBurn();
			}
		
		if(FuelBurned > Fuel)						//If burn is greater than amount of fuel left then only burn ammount left
			{
				FuelBurned = Fuel;
			}
		
		if(FuelBurned > 75)							//If burn is greater than 75 only burn 75
			{
				FuelBurned = 75;
			}
	
		calculations();							//Do maths to calculate new Altitude, Speed & Fuel
			
}		

int calculations()
{
		Fuel = Fuel - FuelBurned;									//Subtract amount of fuel burned from amount remaining 
		Altitude = Altitude + Speed + (FuelBurned - 5);				//Calculate a new Altitude
		Speed = Speed + FuelBurned - 5;								//Calculate a new Speed
		
		if(Fuel == 0)							//If out of fuel goto crash from no fuel
			{
				CrashFromNoFuel();
			}
		if(Altitude <= 0)						//If Altitude less than ground level goto calculate if landed or crashed
			{
				LandedOrCrashed();
			}
		else
			{
				EnterBurn();						//else prompt for burn again
			}								
}	
int LandedOrCrashed()
{

	if((Altitude == 0) && (Speed < 1))				//If Altitude = 0 and speed = less than 1 foot/second (needs to be AbsC<0)
		{
			printf("LANDED!!!!\n");
		}
	else
		{
			printf("CRASHED!!! AT: ");
			printf("  %d", Speed);		
			printf(" ft/sec\n");
		}
		
}

int CrashFromNoFuel()
{	
	
	CrashFromNoFuelSpeed = - (Speed^2 + 10 * Altitude);
	
		printf("CRASHED FROM NO FUEL!!! AT: ");
		printf("  %d", CrashFromNoFuelSpeed);		
		printf(" ft/sec\n");
}

int main()
{

	EnterBurn();


}



