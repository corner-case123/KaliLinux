
import sys
import pygame 
from settings import Settings 
from ship import Ship
from bullet import Bullet 
from alien import Alien

class AlienInvasion :

	def __init__(self) :
		# start pygame and set-up background 
		pygame.init()
		self.settings = Settings() 
		self.screen = pygame.display.set_mode(
			(self.settings.screen_width,self.settings.screen_height))
		pygame.display.set_caption("Alien Invasion")
		self.ship = Ship(self)

		self.bullets = pygame.sprite.Group() 
		self.aliens = pygame.sprite.Group()

		self._create_fleet()

	def run_game(self) :
		# game loop
		while True :
			self._check_events() 
			self.ship.update()
			self._update_bullets()
			self._update_screen() 

	def _update_bullets(self) :
		# update positions of bullets to get rid of older bullets
		self.bullets.update()
		# get rid of old bullets 
		for bullet in self.bullets.copy() :
			if bullet.rect.bottom <= 0 :
				self.bullets.remove(bullet)
			print(len(self.bullets))

	def _check_events(self) :
		for event in pygame.event.get() :
			if event.type == pygame.QUIT :
				sys.exit()
				exit()
			elif event.type == pygame.KEYDOWN :
				self._check_keydown_events(event)
			elif event.type == pygame.KEYUP :
				self._check_keyup_events(event)

	def _check_keydown_events(self,event) :
		if event.key == pygame.K_RIGHT :
			self.ship.moving_right = True  
		elif event.key == pygame.K_LEFT :
			self.ship.moving_left = True 
		elif event.key == pygame.K_q :
			sys.exit()
		elif event.key == pygame.K_SPACE :
			self._fire_bullet()

	def _check_keyup_events(self,event) :
		if event.key == pygame.K_RIGHT :
			self.ship.moving_right = False  
		elif event.key == pygame.K_LEFT :
			self.ship.moving_left = False 

	def _fire_bullet(self) :

		if len(self.bullets) < self.settings.bullets_allowed :
			new_bullet = Bullet(self)
			self.bullets.add(new_bullet)

	def _update_screen(self) :
		self.screen.fill(self.settings.bg_color)
		self.ship.blitme()

		for bullet in self.bullets.sprites() :
			bullet.draw_bullet() 
		self.aliens.draw(self.screen)

		pygame.display.flip()

	def _create_fleet(self) :

		alien  = Alien(self)

		alien_width = alien.rect.width 
		available_space_x = self.settings.screen_width-(2*alien_width)
		number_aliens_x = available_space_x // (2*alien_width)

		for alien_number in range(number_aliens_x) :

			self._create_alien(alien_number)

	def _create_alien(self,alien_number) :

		alien = Alien(self)

		alien_width , alien_height = alien.rect.size
		alien.x = alien_width+2*alien_width*alien_number

		alien.rect.x = alien.x 
		self.aliens.add(alien)


if __name__ == "__main__" : # run only if this file is executed 

	# make an object and run the game using method 
	ai = AlienInvasion()
	ai.run_game()