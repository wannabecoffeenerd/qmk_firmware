TAP_DANCE_ENABLE = no
COMBO_ENABLE = yes

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += tap_dance.c
endif

