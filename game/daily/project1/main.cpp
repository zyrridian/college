#include <windows.h>

int circleRadius1 = 50;  // Initial radius 1
int circleRadius2 = 50; // Initial radius 2

void DrawCircle(HDC hdc, int x, int y, int radius, int red, int green, int blue) {
    HBRUSH hBrush = CreateSolidBrush(RGB(red, green, blue));  // Black brush
    SelectObject(hdc, hBrush);

    Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);

    DeleteObject(hBrush);
}

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		case WM_CREATE: {
            // Create buttons
            CreateWindow("BUTTON", "Kecil", WS_VISIBLE | WS_CHILD, 50, 300, 80, 30, hwnd, (HMENU)101, NULL, NULL);
            CreateWindow("BUTTON", "Besar", WS_VISIBLE | WS_CHILD, 150, 300, 80, 30, hwnd, (HMENU)102, NULL, NULL);
            CreateWindow("BUTTON", "Kecil", WS_VISIBLE | WS_CHILD, 350, 300, 80, 30, hwnd, (HMENU)103, NULL, NULL);
            CreateWindow("BUTTON", "Besar", WS_VISIBLE | WS_CHILD, 450, 300, 80, 30, hwnd, (HMENU)104, NULL, NULL);
            break;
        }
        
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // Draw the first circle
            DrawCircle(hdc, 150, 100, circleRadius1, 0, 0, 0);

            // Draw the second circle
            DrawCircle(hdc, 450, 100, circleRadius2, 255, 255, 255);

            EndPaint(hwnd, &ps);
            break;
        }
        
        case WM_COMMAND: {
            // Handle button clicks
            switch (LOWORD(wParam)) {
                case 101:  // Increase size for the first circle
                    if (circleRadius1 > 10) {
                        circleRadius1 -= 10;
                    }
                    break;
                case 102:  // Decrease size for the first circle
                    circleRadius1 += 10;
                    break;
                case 103:  // Increase size for the second circle
                    if (circleRadius2 > 10) {
                        circleRadius2 -= 10;
                    }
                    break;
                case 104:  // Decrease size for the second circle
                    circleRadius2 += 10;
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

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Tugas Game 1 - Rezky Aditia Fauzan (2241018)",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
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
