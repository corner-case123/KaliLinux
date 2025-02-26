
import pygame 
import settings 

class Ship :

	def __init__(self,ai_game) :

		self.screen = ai_game.screen 
		self.settings = ai_game.settings 

		# gets the rect of game window
		self.screen_rect = ai_game.screen.get_rect()

		self.image = pygame.image.load("ship.bmp")
		#  create a rect for the ship 
		self.rect = self.image.get_rect()

		# storing the float value for smooth  movement 
		# rect.x and rect.y only stores  integer value 
		self.x  = float(self.rect.x)

		# place the ship rect at midpoint of ship 
		self.rect.midbottom = self.screen_rect.midbottom
		self.moving_right = False
		self.moving_left =  False

	def update(self) :
		# .right --> x-coordinate of right side of rect 
		# move if rectangle inside the window
		if self.moving_right and self.rect.right < self.screen_rect.right :
			self.x  += self.settings.ship_speed 
		if self.moving_left and self.rect.left > 0 :
			self.x -= self.settings.ship_speed

		self.rect.x = self.x 

	def blitme(self) :
		#  draw the ship.image in  self.rect 
		self.screen.blit(self.image,self.rect)





