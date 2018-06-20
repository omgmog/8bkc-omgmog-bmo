# This converts all the tile files into one big graphics.[ch] file.
GFX_TILE_FILES := gfx/face1.tmx gfx/face2.tmx gfx/face3.tmx gfx/face4.tmx gfx/face5.tmx gfx/face6.tmx gfx/face7.tmx gfx/face8.tmx
$(eval $(call ConvertTiles,$(GFX_TILE_FILES),graphics))

# Because we use the ConvertTiles macro, we need to tell the make system which other objects
# to compile manually.
COMPONENT_OBJS += app_main.o
