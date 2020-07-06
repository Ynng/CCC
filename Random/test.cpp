/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <initializer_list>

#define WAYPOINT_BEGIN pathfinderParams.waypoints.begin()


struct PathfinderPoint {
  double x;    // X coordinate relative to the start of the movement
  double y;    // Y coordinate relative to the start of the movement
  double theta; // Exit angle relative to the start of the movement
};

struct PathfinderParams {
    std::initializer_list<PathfinderPoint> waypoints;
    double velocity = 0.85;
    bool backwards = false;
};

PathfinderParams pathfinderParams;


void internalMovePathfinder() {

	printf("------\nmoving from\n%.1f %.1f %.1f\nto\n%.1f %.1f %.1f\n------", (*WAYPOINT_BEGIN).x, (*WAYPOINT_BEGIN).y, (*WAYPOINT_BEGIN).theta,(*(WAYPOINT_BEGIN+1)).x, (*(WAYPOINT_BEGIN+1)).y, (*(WAYPOINT_BEGIN+1)).theta);

	/*profileController->moveTo(
		pathfinderParams.waypoints,
		{pathfinderParams.velocity, 2.0, 10.0}, pathfinderParams.backwards, !(configs->redSide));*/
}

void moveOdomAsync(PathfinderParams params) {
	pathfinderParams = params;
	internalMovePathfinder();
}




int main()
{
    printf("Hello World\n");
    
    PathfinderParams test = {{{-26,7,90},{1,4,12},{1,2,143}},0.9,true};
    
    moveOdomAsync(test);
    int idk;
    scanf("%d",&idk);
    return 0;
}
