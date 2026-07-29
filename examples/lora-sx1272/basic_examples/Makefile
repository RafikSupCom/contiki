CONTIKI_PROJECT = lora-sender lora-receiver lora-noise-creator pingpong-reception-delay
MODULES += arch/dev/sx1272
all: $(CONTIKI_PROJECT)

CFLAGS += -I$(CONTIKI)/core/dev/sx1272
PROJECTDIRS += $(CONTIKI)/core/dev/sx1272

include $(CONTIKI)/Makefile.include
 
