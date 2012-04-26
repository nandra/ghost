PROJECT(mongoose)

SET(mongoose_SOURCES
	mongoose.c
)

SET(mongoose_HEADERS
	mongoose.h
)

ADD_LIBRARY(mongoose SHARED ${mongoose_SOURCES} ${mongoose_HEADERS})

