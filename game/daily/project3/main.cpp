#include <windows.h>

int circleRadius1 = 50;  // Initial radius 1
int circleRadius2 = 50; // Initial radius 2

int circleX1 = 150; // Initial X position of the first circle
int circleX2 = 450; // Initial X position of the second circle

int circleY1 = 100; // Initial Y position of the first circle
int circleY2 = 300; // Initial Y position of the second circle

void DrawCircle(HDC hdc, int x, int y, int radius, int red, int green, int blue) {
    HBRUSH hBrush = CreateSolidBrush(RGB(red, green, blue));  // Black brush
    SelectObject(hdc, hBrush);

    Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);

    DeleteObject(hBrush);
}

void MoveFirstCircle(int dx) {
	// Update the X position of the second circle based on the arrow key input
	circleX1 += dx;
	
	// Reset the X position if the circle goes beyond the left edge of the window
	int windowWidth = 640;
	if (circleX1 + circleRadius1 < 0) {
		circleX1 = windowWidth + circleRadius1;
	}
}

void MoveSecondCircleVertically(int dy) {
	// Update the Y position of the second circle based on the arrow key input
	circleY2 += dy;
	
	// Ensure the second cicle stays within the windows boundaries
	int windowHeight = 480;
	if (circleY2 - circleRadius2 < 0) {
		circleY2 = circleRadius2;
	} else if (circleY2 + circleRadius2 > windowHeight) {
		circleY2 = windowHeight - circleRadius2;
	}
}

void MoveSecondCircleHorizontally(int dx) {
	// Update the X position of the second circle based on the arrow key input
	circleX2 += dx;
	
	// Ensure the second cicle stays within the windows boundaries
	int windowWidth = 640;
	if (circleX2 - circleRadius2 < 0) {
		circleX2 = circleRadius2;
	} else if (circleX2 + circleRadius2 > windowWidth) {
		circleX2 = windowWidth - circleRadius2;
	}
}

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		case WM_CREATE: {
			// Set up a timer with ID 1 and an initial delay of 100 milliseconds
			SetTimer(hwnd, 1, 50, NULL);
			
			// Set initial position of the first circle
			circleX1 = 640 + circleRadius1;
			
            break;
        }
        
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // Draw the first circle
            DrawCircle(hdc, circleX1, circleY1, circleRadius1, 255, 255, 255);

            // Draw the second circle
            DrawCircle(hdc, circleX2, circleY2, circleRadius2, 0, 0, 0);

            EndPaint(hwnd, &ps);
            break;
        }
        
        case WM_TIMER: {
        	// Handle timer events
        	switch (wParam) {
        		case 1: // Timer ID 1
        			// Move the first circle to the left
        			MoveFirstCircle(-5);
        			break;
			}
			
			// Force repaint to update the circles
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
        
        case WM_KEYDOWN: {
        	// Handle arrow key inputs
        	switch (wParam) {
        		case VK_UP:
        			MoveSecondCircleVertically(-5); // Move second circle up
        			break;
        		case VK_DOWN:
        			MoveSecondCircleVertically(5); // Move second circle down
        			break;
        		case VK_LEFT:
        			MoveSecondCircleHorizontally(-5); // Move second circle to the left
        			break;
        		case VK_RIGHT:
        			MoveSecondCircleHorizontally(5); // Move second circle to the right
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

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Tugas Game 3 - Rezky Aditia Fauzan (2241018)",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
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
