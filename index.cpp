#include <cstdio>
#include <unistd.h>

struct Missile {
  int x;
  int y;
  int x_velocity;
  int y_velocity;
};

struct Point {
  int x;
  int y;
};

int main() {
  Point target;
  target.x = 1000;
  target.y = 0;

  Missile missile;
  missile.x = 0;
  missile.y = 0;
  missile.x_velocity = 0;
  missile.y_velocity = 0;

  while (target.x > missile.x || target.y > missile.y) {
    missile.x += missile.x_velocity;
    missile.y += missile.y_velocity;

    int x_distance = target.x - missile.x;
    int y_distance = target.y - missile.y;

    if (x_distance > 0 && missile.x_velocity < 913) {
      missile.x_velocity += 1;
    } else {
      missile.x_velocity = 0;
    }
    if (y_distance > 0 && missile.x_velocity < 913) {
      missile.y_velocity += 1;
    } else {
      missile.y_velocity = 0;
    }

    printf("\x1b[2J\n");
    printf("\x1b[H");
    printf("-----------------------------\n");
    printf("- Missile info\n");
    printf("X: %d\n", missile.x);
    printf("Y: %d\n", missile.y);
    printf("X Velocity: %d\n", missile.x_velocity);
    printf("Y Velocity: %d\n", missile.y_velocity);
    printf("- Target Info\n");
    printf("X: %d\n", target.x);
    printf("Y: %d\n", target.y);
    printf("X Distance: %d\n", x_distance);
    printf("Y Distance: %d\n", y_distance);
    printf("-----------------------------");

    usleep(50000);

  }
}
