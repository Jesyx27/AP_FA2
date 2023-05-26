# AP_FA2
## warehouse Jesse Ceulemans, adaptive programming

## Alterations from UML

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
