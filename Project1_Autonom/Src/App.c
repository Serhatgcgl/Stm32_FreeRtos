#include "App.h"

char uniqueBuf[64];
uint32_t unique[3];
extern uint8_t CDC_Transmit_FS(uint8_t* Buf, uint16_t Len);
extern uint8_t UserRxBufferFS[];
void Send_UID(void)
{
	memcpy((void *)unique, (const void *)((uint32_t *)(UID_BASE)), 12);
	sprintf(uniqueBuf,"%08x%08x%08x\n",unique[0],unique[1],unique[2]);
  CDC_Transmit_FS((uint8_t*)uniqueBuf,sizeof(uniqueBuf));

}

void ToLower(void)
{
			for (uint8_t i = 0; UserRxBufferFS[i]!='\0'; i++) {
      if(UserRxBufferFS[i] >= 'A' && UserRxBufferFS[i] <= 'Z') {
         UserRxBufferFS[i] = UserRxBufferFS[i] + 32;
      }
		}
		
	
}