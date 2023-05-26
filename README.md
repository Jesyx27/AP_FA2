# AP_FA2
## warehouse Jesse Ceulemans, adaptive programming

## How to Run
The file contains two running options, main and normal. Both of these options can be ran via makefile. They are named accordingly with .cpp. 
main.cpp	`warehouse\` and
test.cpp	`warehouse\test\`

## Alterations from UML
### Raw Alterations
```
Pallet::itemCapacity,						int -> unsigned int
Pallet::itemCount,						int -> unsigned int
Pallet::getItemCount(),						int -> unsigned int
Pallet::getRemainingSpace(),					int -> unsigned int
Pallet::reallocateEmptyPallet():	itemCapacity		int -> unsigned int
Pallet::
								+ ostream&	operator<<()
								+ bool		operator==()
=================================================================================
Shelf::SwapPallet():			slot,			int -> unsigned int
					slot2,			int -> unsigned int
=================================================================================
Employee::
								+ bool 		operator==()
								+ ostream& 	operator<<()
=================================================================================
Warehouse::pickItems			itemCount		int -> unsigned int
Warehouse::putItems			itemCount		int -> unsigned int
```
### Reasons 
The reason that I chose to alter the UML to include unsigned int is that a lot of these attributes and functions do not ever need an int value below zero
such as the length of a list or as in the count of items on a pallet. When compared to list lenghts these values can cause warnings and bugs to occur, since 
they do not carry over well.

### New UML Diagram
![warehouse](https://github.com/Jesyx27/AP_FA2/assets/86268481/27c16976-143c-4fde-9a91-686812fef2b0)
