#include "memory.h"
#include "offsets.h"
using namespace std;

void getmodule(auto mem, auto client)
{
	auto mem = memory("gmod.exe");

	cout << "proc id: " << mem.GetProcessId() << endl;

	const auto client = mem.GetModuleAddress("client.dll");

	cout << "clientura -> " << "0x" << hex << client << dec << endl;
}

int health(auto mem, auto client)
{
	getmodule();
	if (localigrok)
	{

		const auto hepeshka = mem.Read<int>(localigrok + offsets::health);
		const auto player_state = mem.Read<int>(localigrok + offsets::health + coordinates::state);
		const auto cordx = mem.Read<float>(localigrok + offsets::health + coordinates::coor_x);
		const auto cordy = mem.Read<float>(localigrok + offsets::health + coordinates::coor_y);
		const auto cordz = mem.Read<float>(localigrok + offsets::health + coordinates::coor_z);

		if (player_state == )
			cout << "health: " << dec << hepeshka << " x: " << cordx << " y: " << cordy << " z: " << cordz << " on ground" << endl;
		else
			cout << "health: " << dec << hepeshka << " x: " << cordx << " y: " << cordy << " z: " << cordz << " in air!!" << endl;


	}

}