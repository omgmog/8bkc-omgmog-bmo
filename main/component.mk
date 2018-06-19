# This converts all the tile files into one big graphics.[ch] file.
GFX_TILE_FILES := gfx/sprite.tmx
$(eval $(call ConvertTiles,$(GFX_TILE_FILES),graphics))

# Because we use the ConvertTiles macro, we need to tell the make system which other objects
# to compile manually.
COMPONENT_OBJS += app_main.o
