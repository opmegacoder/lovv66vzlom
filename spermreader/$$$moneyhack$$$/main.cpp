#include "memory.h"
#include <thread>
#include "offsets.h"

using namespace std;

uintptr_t localigrok;
uintptr_t anus;
uintptr_t popka;
DWORD64 client;
DWORD64 server;
memory mem = memory("gmod.exe");

void bh();


int main()
{
	setlocale(LC_ALL, "ru");
	 

	//cout << "proc id: " << mem.GetProcessId() << endl;
	

	client = mem.GetModuleAddress("client.dll");
	server = mem.GetModuleAddress("server.dll");
	cout << "clientura -> " << "0x" << hex << client << dec << endl;
	cout << "server -> " << "0x" << hex << server << dec << endl;

	localigrok = mem.Read<uintptr_t>(client + offsets::localigrok);
	anus = mem.Read<uintptr_t>(server + offsets::maxplayers);
	popka = mem.Read<uintptr_t>(server + offsets::curplayers);

	const auto pizda = mem.Read<int>(anus + offsets::hu3ta);
	const auto curp = mem.Read<int>(popka + offsets::hui);

	cout << "localplayer) " << hex << localigrok << dec << endl;
	cout << "max players) " << pizda << endl;
	cout << "current players) " << curp << endl;




	//printf("localigrop = %p\nentity= %p\n", localigrok, entitylistaddr);

	// gavno

	/*for (int i = 0; i < 1; ++i)
	{
		const auto localhp = mem.Read<int>(entitylistaddr + offsets::health);
		cout << "localhp: " << localhp << endl;
		const auto player1 = mem.Read<int>(entitylistaddr1 + offsets::health);
		cout << "player1 hp: " << player1 << endl;
		const auto player2 = mem.Read<int>(entitylistaddr2 + offsets::health);
		cout << "player2 hp: " << player2 << endl;
		const auto player3 = mem.Read<int>(entitylistaddr3 + offsets::health);
		cout << "player3 hp: " << player3 << endl;
	}*/

	// very good

	for (int i = 0; i < pizda; ++i)
	{
		uintptr_t sperma = (offsets::entitylist  + offsets::ebaniyIndex * i);
		uintptr_t entitylistaddrbase = mem.Read<uintptr_t>(client + sperma);
		const auto zdorovie = mem.Read<int>(entitylistaddrbase + offsets::health);
		if (!entitylistaddrbase)
		{
			cout << "nekonekted" << endl;
			break;
		}
		else {
			cout << "zhiznh is: " << zdorovie << endl;
		}
	}



	



	thread pidor(bh);
	

	pidor.detach();

	while (true)
	{

		if (localigrok)
		{

			const auto hepeshka = mem.Read<int>(localigrok + offsets::health);
			const auto bronya = mem.Read<int>(localigrok + offsets::idc + offsets::armor);
			//const auto armorec = mem.Read<int>(localigrok + offsets::armor);
			const auto cordx = mem.Read<float>(localigrok + coordinates::coor_x);
			const auto cordy = mem.Read<float>(localigrok + coordinates::coor_y);
			const auto cordz = mem.Read<float>(localigrok + coordinates::coor_z);
			const auto airState = mem.Read<int>(localigrok + coordinates::state);
			
			cout << "health: " << dec << hepeshka << " bronya: " << bronya << " x: " << cordx << " y: " << cordy << " z: " << cordz << " your state is: " << airState << endl;


			

			Sleep(5000);
			//this_thread::sleep_for(chrono::milliseconds(1));
		}

		
	}
	
}

void bh()
{
	while (true) {


		const auto airState = mem.Read<int>(localigrok + coordinates::state);
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
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




