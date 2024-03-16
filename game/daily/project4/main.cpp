#include <windows.h>
#include <cmath> // For sqrt function

int circleRadius1 = 50;  // Initial radius 1
int circleRadius2 = 50; // Initial radius 2
int circleRadius3 = 50; // Initial radius 3

int circleX1 = 300; // Initial X position of the first circle
int circleX2 = 75; // Initial X position of the second circle
int circleX3 = 75; // Initial X position of the third circle

int circleY1 = 100; // Initial Y position of the first circle
int circleY2 = 100; // Initial Y position of the second circle
int circleY3 = 300; // Initial Y position of the third circle

int circleSpeedX1 = -5;  // Initial speed of circle 1 along X-axis
int circleSpeedY1 = 0;  // Initial speed of circle 1 along Y-axis

int circleSpeedX2 = 0;  // Initial speed of circle 2 along X-axis
int circleSpeedY2 = 0;   // Initial speed of circle 2 along Y-axis

int circleSpeedX3 = 0;   // Initial speed of circle 3 along X-axis
int circleSpeedY3 = 0;   // Initial speed of circle 3 along Y-axis

bool hitOccurred = false; // Flag to track if collision occurred

const double gravity = 9.81;  // Acceleration due to gravity (m/s^2)

void DrawCircle(HDC hdc, int x, int y, int radius, int red, int green, int blue) {
    HBRUSH hBrush = CreateSolidBrush(RGB(red, green, blue));  // Black brush
    SelectObject(hdc, hBrush);

    Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);

    DeleteObject(hBrush);
}

void MoveCircle(int &x, int &y, int &speedX, int &speedY, int windowWidth, int windowHeight, int radius) {
    // Update the position based on current speed
    x += speedX;
    y += speedY;

    // Check for collision with window edges
    if (x - radius < 0 || x + radius > windowWidth) {
        speedX = -speedX;  // Reverse the speed to bounce off the edges
    }
    if (y - radius < 0 || y + radius > windowHeight) {
        speedY = -speedY;  // Reverse the speed to bounce off the edges
    }
}

bool CheckCollision(int x1, int y1, int radius1, int x2, int y2, int radius2) {
    // Calculate distance between the centers of the circles
    int dx = x2 - x1;
    int dy = y2 - y1;
    int distance = sqrt(dx * dx + dy * dy);

    // Check if the distance is less than the sum of the radii
    return distance < (radius1 + radius2);
}

void ResolveCollision(int &speedX1, int &speedY1, int &speedX2, int &speedY2) {
    // Swap the velocities to simulate bouncing
    int tempX = speedX1;
    int tempY = speedY1;
    speedX1 = speedX2;
    speedY1 = speedY2;
    speedX2 = tempX;
    speedY2 = tempY;
}

void MoveFirstCircle(int dx) {
    // Update the X position of the first circle based on the arrow key input
    circleX1 += dx;
}

void MoveSecondCircleVertically(int dy) {
    // Update the Y position of the second circle based on the arrow key input
    circleY2 += dy;
}

void MoveSecondCircleHorizontally(int dx) {
    // Update the X position of the second circle based on the arrow key input
    circleX2 += dx;
}

void MoveThirdCircle() {
    static double initialSpeed = 20.0;  // Initial speed of the ball (pixels per frame) if negative, move to the 
    static double angle = 45.0;         // Launch angle in degrees

    // Convert angle from degrees to radians
    double angleRadians = angle * (3.14159 / 180.0);

    // Calculate the horizontal and vertical components of the initial velocity
    double initialSpeedX = initialSpeed * cos(angleRadians);
    double initialSpeedY = initialSpeed * sin(angleRadians);

    // Calculate the time since the ball was launched
    static double time = 0.0;
    time += 0.1; // Adjust time step as needed

    // Calculate the new position of the ball using the equations of motion
    circleX3 = static_cast<int>(circleX3 + initialSpeedX * time);
    circleY3 = static_cast<int>(circleY3 - (initialSpeedY * time - 0.5 * gravity * time * time));

    // Check if the ball has hit the ground
    if (circleY3 >= 480 - circleRadius3) {
        // Reset the position and time for the next kick
        circleY3 = 480 - circleRadius3;
        time = 0.0;
    }
}

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		case WM_CREATE: {
			SetTimer(hwnd, 1, 50, NULL);
            break;
        }
        
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // Draw the first circle
	        DrawCircle(hdc, circleX1, circleY1, circleRadius1, 255, 255, 255);
	
	        // Draw the second circle
	        DrawCircle(hdc, circleX2, circleY2, circleRadius2, 0, 0, 0);
	
	        // Draw the third circle
	        DrawCircle(hdc, circleX3, circleY3, circleRadius3, 0, 255, 0);

            EndPaint(hwnd, &ps);
            break;
        }
        
		case WM_TIMER: {
		    MoveCircle(circleX1, circleY1, circleSpeedX1, circleSpeedY1, 640, 480, circleRadius1);
		    MoveCircle(circleX2, circleY2, circleSpeedX2, circleSpeedY2, 640, 480, circleRadius2);
		
		    if (hitOccurred) {
		        // Move the third circle with animated behavior
		        MoveThirdCircle(); // Adjust parameters as needed
		    }
		
		    // Check for collision between circle 1 and circle 2
		    if (CheckCollision(circleX1, circleY1, circleRadius1, circleX2, circleY2, circleRadius2)) {
		        // Handle collision: Reverse the speeds of both circles
		        ResolveCollision(circleSpeedX1, circleSpeedY1, circleSpeedX2, circleSpeedY2);
		    }
		
		    // Check for collision between circle 2 and circle 3
		    if (CheckCollision(circleX2, circleY2, circleRadius2, circleX3, circleY3, circleRadius3) && !hitOccurred) {
		        hitOccurred = true; // Set the flag to true to indicate collision occurred
		    }
		
		    // Force repaint to update the circles
		    InvalidateRect(hwnd, NULL, TRUE);
		    break;
		}


        
        case WM_KEYDOWN: {
        	// Handle arrow key inputs
        	switch (wParam) {
        		case VK_UP:
        			MoveSecondCircleVertically(-10); // Move second circle up
        			break;
        		case VK_DOWN:
        			MoveSecondCircleVertically(10); // Move second circle down
        			break;
        		case VK_LEFT:
        			MoveSecondCircleHorizontally(-10); // Move second circle to the left
        			break;
        		case VK_RIGHT:
        			MoveSecondCircleHorizontally(10); // Move second circle to the right
        			break;
			}
			
			// Force a repaint to update the circles
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}

		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Tugas Game 4 - Rezky Aditia Fauzan (2241018)",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
