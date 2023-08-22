#include "memory.h"
#include <thread>
#include "offsets.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	auto mem = memory("gmod.exe");

	cout << "proc id: " << mem.GetProcessId() << endl;

	const auto client = mem.GetModuleAddress("client.dll");
	
	cout << "client -> " << hex << client << dec << endl;
	cout << "здаров это взлом от lovv66 нажмите на клавише 1 чтоб начать взлом\n";
	cin >> offsets::megahack;
	Sleep(2000);
	cout << "взлом удался ваша удача равна 228 процентам!!!\n";
	Sleep(2000);


	while (offsets::megahack == 1)
	{
		const auto localigrok = mem.Read<uintptr_t>(client + offsets::localigrok);
		//cout << hex << localigrok << dec << endl;

		if (localigrok)
		{

			const auto hepeshka = mem.Read<int>(localigrok + offsets::health);
			//const auto armorec = mem.Read<int>(localigrok + offsets::health + offsets::armor);
			const auto cordx = mem.Read<float>(localigrok + offsets::health + coordinates::coor_x);
			const auto cordy = mem.Read<float>(localigrok + offsets::health + coordinates::coor_y);
			const auto cordz = mem.Read<float>(localigrok + offsets::health + coordinates::coor_z);
			const auto airState = mem.Read<int>(localigrok + offsets::health + coordinates::state);
			cout << "health: " << dec << hepeshka << " x: " << cordx << " y: " << cordy << " z: " << cordz << " your state is: " << airState << endl;

			if (GetAsyncKeyState(VK_SPACE)&0x8000)
			{   
				


				if (airState == 257 || airState == 263)
				{    
					auto sohran3 = mem.Write<uintptr_t>(client + offsets::forcejump, offsets::sohran);
					Sleep(50);
					auto sohran4 = mem.Write<uintptr_t>(client + offsets::forcejump, offsets::sohran2);



				}




			}
			this_thread::sleep_for(chrono::milliseconds(1));
		}
	}
}

