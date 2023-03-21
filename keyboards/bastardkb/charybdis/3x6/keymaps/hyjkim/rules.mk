TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += tap_dance.c
endif

