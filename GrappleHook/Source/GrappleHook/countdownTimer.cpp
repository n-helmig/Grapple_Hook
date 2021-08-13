// Fill out your copyright notice in the Description page of Project Settings.


#include "countdownTimer.h"
#include "TimerManager.h"
#include "Engine.h"

// Sets default values
AcountdownTimer::AcountdownTimer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AcountdownTimer::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(timerHandler, this, &AcountdownTimer::onTimerEnd, timeTotal, false);
	
}

// Called every frame
void AcountdownTimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	timeLeft = GetWorldTimerManager().GetTimerRemaining(timerHandler);
	//takes timeLeft and splits it into minutes and seconds 
	seconds_display = AcountdownTimer::timeLeft % 60;
	minutes_display = AcountdownTimer::timeLeft / 60;
}

void AcountdownTimer::onTimerEnd()
{
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Timer is up"));
	
}

