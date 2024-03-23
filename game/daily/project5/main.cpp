#include <windows.h>
#include <cmath> // For sqrt function

int circleRadius1 = 50;  // Initial radius 1
int circleRadius2 = 50; // Initial radius 2
int explosionRadius = 150; // Initial radius

int circleX1 = 300; // Initial X position of the first circle
int circleX2 = 75; // Initial X position of the second circle
int explosionX = 300; // Initial X position of the star

int circleY1 = 200; // Initial Y position of the first circle
int circleY2 = 200; // Initial Y position of the second circle
int explosionY = 200; // Initial Y position of the star

bool isExplosion = false; // Flag to control explosion animation
int number = 0;

void DrawCircle(HDC hdc, int x, int y, int radius, int red, int green, int blue) {
    HBRUSH hBrush = CreateSolidBrush(RGB(red, green, blue));  // Black brush
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
    DeleteObject(hBrush);
}

void DrawExplosion(HDC hdc, int x, int y, int radius) {
    POINT points[10];
    for (int i = 0; i < 10; i++) {
        double angle = 3.14159265 / 5 * i - 3.14159265 / 2;
        if (i % 2 == 0) {
            points[i].x = static_cast<int>(x + radius * cos(angle) * 0.4);  // Outer points
            points[i].y = static_cast<int>(y + radius * sin(angle) * 0.4);
        } else {
            points[i].x = static_cast<int>(x + radius * cos(angle));  // Inner points
            points[i].y = static_cast<int>(y + radius * sin(angle));
        }
    }
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));  // Red brush
    SelectObject(hdc, hBrush);
    Polygon(hdc, points, 10);  // Draw the polygon connecting the points
    DeleteObject(hBrush);
}

void DrawOval(HDC hdc, int x, int y, int width, int height, int red, int green, int blue) {
    HBRUSH hBrush = CreateSolidBrush(RGB(red, green, blue));  // Black brush
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x - width/2, y - height/2, x + width/2, y + height/2);
    DeleteObject(hBrush);
}

// Function to move the second circle vertically
void MoveSecondCircleVertically(int dy) {
    circleY2 += dy;
}

// Function to move the second circle horizontally
void MoveSecondCircleHorizontally(int dx) {
    circleX2 += dx;
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
		    if (!isExplosion) {
		    	DrawCircle(hdc, circleX1, circleY1, circleRadius1, 255, 255, 255);
			}
		    
		    // Draw the second circle
		    DrawCircle(hdc, circleX2, circleY2, circleRadius2, 0, 0, 0);
 
            // Calculate the distance between the centers of the circles
		    int dx = circleX2 - circleX1;
		    int dy = circleY2 - circleY1;
		    int distance = sqrt(dx * dx + dy * dy);
		
		    // If the distance between the centers is less than the sum of the radius and explosion hasn't happened yet
		    if (distance <= (circleRadius1 + circleRadius2) && !isExplosion) {
		    	
		    	// Set explosion flag to true so it won't explode again
		    	isExplosion = true;
		        
		        // Draw Explosion
		        DrawExplosion(hdc, explosionX, explosionY, explosionRadius);
		        
		    }
		    
		    if (isExplosion) {
		    	// Draw Oval
		        DrawOval(hdc, circleX1, circleY1 + 75, circleRadius1 * 3, circleRadius1, 255, 255, 255);
			}
		
		    EndPaint(hwnd, &ps);
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
	                MoveSecondCircleHorizontally(-30); // Move second circle to the left
	                break;
	            case VK_RIGHT:
	                MoveSecondCircleHorizontally(30); // Move second circle to the right
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

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Tugas Game 5 - Rezky Aditia Fauzan (2241018)",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
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
